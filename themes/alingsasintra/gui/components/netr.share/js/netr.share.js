/**
 * @requires jQuery
 * @class Module with tabbed content
 * @constructor
 * @param {String or Object} el       Element containing sharing links
 * @param {Object}           options  See NetR.Share.prototype.defaultOptions
 */
netr.Share = function (el, options) {
	var t = this;
	this.options = $.extend({}, this.defaultOptions, options || {});
	this.container = $(el);
	// Delegate event observing to container instead of individual links
	this.container.click(function (e) {
		var target = $(e.target).closest('a');
		if (target.length) {
			// Does the links classname match any regex in t.jsLinks?
			if (!t.jsLinks.length || !($.grep(t.jsLinks, function (regex) { return regex.test(target.attr('class')); })).length) {
				// If not, open links href in new window
				e.preventDefault();
				window.open(target.attr('href'), '', t.options.windowOptions);
			}
			// Log event
			try {
				t.logEvent(target.attr('class').replace(/^service-/, ''));
			} catch (e) {}
		}
	});
	if (this.options.addToFavourites) {
		this.createAddToFavouritesLink();
	}
};
netr.Share.prototype = {

	// Default options
	defaultOptions: {
		// Whether to add favourites link from start
		addToFavourites: true,
		// Text for favourites link
		addToFavouritesText: 'Favourites',
		// Title for favourites link
		addToFavouritesTitle: 'Add to favourites',
		// Options for window.open
		windowOptions: 'toolbar=no,width=800,height=500,scrollbars=yes'
	},

	// Push special class names (regex) to this array to prevent default behavior when clicked
	jsLinks: [],

	/**
	 * Log share event with Google Analytics
	 * @param {String} service  Name of sharing service
	 */
	logEvent: function (service) {
		if (window.pageTracker) {
			// TODO: behövs document.URL här, eller loggas det ändå?
			window.pageTracker._trackEvent('Share', service, document.URL);
		}
	},

	/**
	 * Add an 'add to favourites' link in supported browsers
	 */
	createAddToFavouritesLink: function () {
		this.jsLinks.push(/\bservice-add-favourite\b/);
		this.favouritesLink = $('<li><a href="' + document.URL + '" class="service-add-favourite" title="' + this.options.addToFavouritesTitle + '"><span>' + this.options.addToFavouritesText + '</span></a></li>');
		this.container.find('li:first').before(this.favouritesLink);
		try {
			if (window.sidebar && window.sidebar.addPanel) {
				// Firefox
				this.favouritesLink.click(function (e) {
					e.preventDefault();
					window.sidebar.addPanel(document.title, document.URL, "");
				});
			} else if (document.all) {
				// Internet Explorer
				this.favouritesLink.click(function (e) {
					e.preventDefault();
					window.external.AddFavorite(document.URL, document.title);
				});
			} else if ($.browser.opera) {
				// Opera
				this.favouritesLink.find('a').attr({
					'rel': 'sidebar',
					'title': document.title
				});
			} else {
				// Other browsers get nothing :(
				this.favouritesLink.remove();
			}
		} catch (e) {
			// To prevent non working link, remove it if something breaks
			this.favouritesLink.remove();
		}
	}
};