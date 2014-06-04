/**
* @fileoverview Wrapper methods for Google Maps API v3
*/

(function ($) {
	/**
	 * NetRelations Google Maps wrapper constructor
	 * @constructor
	 *
	 * @requires Google Maps API v3.0 or later
	 * @requires jQuery 1.5.2 or later
	 *
	 * @param {jQuery} el The element where the map will be inserted
	 * @param {Object} options An options object. See {@link NetRGoogleMap.options} for a list of options
	 */
	var NetRGoogleMap = function (el, options) {
		this.options = $.extend(true, {}, $.netrGoogleMap.defaultOptions, options || {});

		this.container = el;

		this.markers = [];

		// Replace static map with dynamic map
		this.mapContainer = $('<div class="googlemap-container">');
		this.container.empty().append(this.mapContainer);

		this.googlemap = new google.maps.Map(this.mapContainer[0], this.options.googleMapOptions);

		// If a list of elements has been passed in, parse it for coordinates and info
		if (this.options.vcards) {
			this.parseVCards({vcards: this.options.vcards});
		}

	};


	NetRGoogleMap.prototype = {

		/**
		* Creates a marker on the map, with info bubble displaying on mouseover
		* @param  latlng  Coordinates for marker
		* @param  info  Info to display in infowindow
		*
		* @returns An instance of google.maps.Marker
		*/
		addMarker: function (options) {
			var t = this;

			options = $.extend({
				latlng: '',
				info: '',
				zoomTo: false
			}, options || {});

			// Create new marker
			var marker = new google.maps.Marker({
				map: this.googlemap,
				position: options.latlng,
				icon: this.options.icons.marker,
				shadow: this.options.icons.shadow,
				// Set z-index based on latitude to get a somwhat correct layer order
				zIndex: Math.abs(100000 - Math.floor(options.latlng.lat() * 10000))
			});

			if (options.info) {
				google.maps.event.addListener(marker, 'click', function () {
					t.showInfoWindow(marker, options.info);
				});
			}

			this.markers.push(marker);

			if (options.zoomTo !== false) {
				this.zoomToMarker({marker: marker});
			}

			return marker;
		},

		/**
		 * Adjust center and zoomlevel to match the maps markers
		 */
		fitAroundMarkers: function (options) {
			var t = this;

			options = $.extend({
				zoomLevel: 13
			}, options || {});

			var bounds = new google.maps.LatLngBounds();
			$.each(this.markers, function (index, marker) {
				bounds.extend(marker.getPosition());
			});

			var listener = google.maps.event.addListenerOnce(this.googlemap, 'zoom_changed', function () {
				if (t.googlemap.getZoom() > options.zoomLevel) {
					t.googlemap.setZoom(options.zoomLevel);
				}
			});

			// Shrink to fit all markers
			this.googlemap.fitBounds(bounds);
		},

		/**
		 * Zooms to a specific marker
		 */
		zoomToMarker: function (options) {
			options = $.extend({
				marker: '',
				zoomLevel: 13
			}, options || {});
			this.googlemap.setCenter(options.marker.getPosition());
			this.googlemap.setZoom(options.zoomLevel);
		},

		/**
		 * Displays an infowindow for a marker
		 *
		 * @param {google.maps.Marker}  marker  The marker this infowindow should be anchored to
		 * @param {jQuery}  info  Element containing the markup to display in the infowindow
		 */
		showInfoWindow: function (marker, info) {
			if (!marker.infoWindow) {
				marker.infoWindow = new google.maps.InfoWindow({
					content: info.clone()[0],
					maxWidth: 350
				});
			}
		
			marker.infoWindow.open(this.googlemap, marker);
		},

		/**
		 * Parses vcard elements for geodata and creates markers on the map
		 *
		 * @param {jQuery}  elements  A Collection of vcard elements to parse
		 */
		parseVCards: function (options) {
			var t = this;
			var zoomChangeListener;

			options = $.extend({
				vcards: null,
				zoomLevel: 5
			}, options || {});

			if (options.vcards) {
				options.vcards.each(function () {
					var item = $(this);
					var geocoder;
					var coords;

					function addMarker () {
						var marker = t.addMarker({
							latlng: coords,
							info: item
						});
					}

					// Does this vcard contain any geo data?
					if (item.find('.geo').length) {
						// If so, use that data to create a new LatLng instance
						coords = new google.maps.LatLng(item.find('.geo .latitude:first').text(), item.find('.geo .longitude:first').text());
						addMarker();
					} else {
						// If not, try to geocode the address data
						geocoder = new google.maps.Geocoder();
						geocoder.geocode({
							// Get first address from vcard and strip multiple whitespace
							address: item.find('.adr:first').text().replace(/\s+/g, ' ')
						}, function (result, status) {
							if (status == google.maps.GeocoderStatus.OK) {
								coords = result[0].geometry.location;
								addMarker();
								t.fitAroundMarkers();
							}
						});
					}
				});

				this.fitAroundMarkers();
			}
		}

	};

	$.fn.netrGoogleMap = function (method, options) {
		var methods = {
			init: function (opitonios) {
				var el = $(this);
				el.data('googlemap', new NetRGoogleMap(el, opitonios || {}));
			},
			getMap: function () {
				return this.data('googlemap');
			},
			parseVCards: function (options) {
				if (this.data('googlemap')) {
					this.data('googlemap').parseVCards(options);
				}
				return this;
			},
			addMarker: function (options) {
				if (this.data('googlemap')) {
					return this.data('googlemap').addMarker(options);
				}
			},
			zoomToMarker: function (options) {
				if (this.data('googlemap')) {
					return this.data('googlemap').zoomToMarker(options);
				}
			},
			fitAroundMarkers: function (options) {
				if (this.data('googlemap')) {
					return this.data('googlemap').fitAroundMarkers();
				}
			}
		};

		// Method calling logic
		if (methods[method]) {
			// Method exists
			return methods[method].apply(this, Array.prototype.slice.call(arguments, 1));
		} else if (typeof method === 'object' || ! method) {
			// Initialize
			return methods.init.call(this, method);
		} else {
			// Method doesn't exist
			throw new Error( 'Method ' +  method + ' does not exist on netrGoogleMap' );
		}
	};

	/**
	 * NetRelations Google Maps wrapper default options
	 */
	$.netrGoogleMap = {
		defaultOptions: {
			// These options are passed along to the internal google.maps.Map instance
			googleMapOptions: {
				// Initial zoom level
				zoom: 1,
				// Initial center coordinates
				center: new google.maps.LatLng(20, 10),
				// Options for map type control
				mapTypeControlOptions: {
					mapTypeIds: [
						google.maps.MapTypeId.ROADMAP,
						google.maps.MapTypeId.HYBRID
					],
					style: google.maps.MapTypeControlStyle.DROPDOWN_MENU
				},
				// Initial Map mapTypeId
				mapTypeId: google.maps.MapTypeId.ROADMAP,
				// Zooming by use of scrollwheel on or off
				scrollwheel: false
			},
			// A bunch of vcard elements to parse for coordinates and info.
			// Uses data found in element with class="geo" if present, otherwise
			// does a geocoding request to Google using the vcards address data.
			vcards: null,
			// Icons
			icons: {
				marker: new google.maps.MarkerImage('/gui/components/netr.gmap/i/mapmarker.png',
					// Size
					new google.maps.Size(32, 47),
					// Origin
					new google.maps.Point(0,0),
					// Anchor
					new google.maps.Point(16, 45)
				),
				shadow: new google.maps.MarkerImage('/gui/components/netr.gmap/i/mapmarker.png',
					// Size
					new google.maps.Size(32, 25),
					// Origin
					new google.maps.Point(32, 22),
					// Anchor
					new google.maps.Point(1, 24)
				)
			}
		}
	};

}(jQuery));