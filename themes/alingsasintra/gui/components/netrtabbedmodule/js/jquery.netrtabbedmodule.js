(function ($) {

	var TabbedModule = function (el, options) {
		var self = this;
		var activate;
		var moduleElements;

		this.activeModule = null;

		this.options = $.extend({}, {
			// Selector for module
			moduleSelector: '.m',
			// Selector for heading inside module
			headingSelector: '.m-h',
			// Selector for content inside module
			contentSelector: '.m-c',
			// Selector for initially active module
			activeSelector: '.active',
			// Class set for selected items
			selectedClass: 'sel',
			// Whether to add tab changes to browser history or not
			addToHistory: false
		}, options || {});

		this.el = el;

		this.navigation = $('<ul class="tabs clearfix" role="tablist">');

		this.ignoreHashChange = false;

		moduleElements = this.el.find(this.options.moduleSelector);

		// Get the hash, if any, so we can activate the corresponding tab
		var hash = new netr.URI(document.location.toString()).fragment;

		this.modules = $.map(moduleElements, function (module, index) {
			// Create simple item object
			var item = {
				module: $(module),
				id: $(module).attr('id') || 'tabpanel-' + index
			};
			// Should this be the default selected item?
			if ( (hash.length && item.id == hash) || (!hash.length && item.module.is(self.options.activeSelector)) || index === 0) {
				activate = item;
			}

			item.module.attr({
				id: '', // Remove id to avoid jumping when hash is updated
				role: 'tabpanel',
				'aria-labelledby': 'tabnav-' + index
			});

			// Create navigation tab
			item.tab = $('<li>', {
				'class': (index === 0 ? 'first' : (index === moduleElements.length - 1 ? 'last' : '')),
				'role': 'presentation'
			}).append($('<a>', {
				href: '#' + (item.module.attr('id') || ''),
				role: 'tab',
				id: 'tabnav-' + index,
				tabindex: '-1',
				text: item.module.find(self.options.headingSelector).hide().text(),
				click: function (e) {
					e.preventDefault();
					self.ignoreHashChange = true;
					self.showItem(item, self.options.addToHistory, true);
				},
				keydown: function (e) {
					switch (e.which) {
						case 37: case 38:
							if ($(this).parent().prev().length > 0) {
								$(this).parent().prev().find(">a").click();
							} else {
								$(self.navigation).find("li:last>a").click();
							}
							break;
						case 39: case 40:
							if ($(this).parent().next().length > 0) {
								$(this).parent().next().find(">a").click();
							} else {
								$(self.navigation).find("li:first>a").click();
							}
							break;
					}
				}

			})).appendTo(self.navigation);

			return item;
		});

		// Add tab navigation to DOM
		this.el.prepend($('<div class="tab-navigation">').append(this.navigation));

		if (activate) {
			// Activate a module but don't set focus to the active tab
			this.showItem(activate, false, false);
		}

		// Observe changes on the url hash, if supported by the browser
		if (self.options.addToHistory) {
			$(window).bind('hashchange', function () {
				if (!self.ignoreHashChange) {
					var hash = new netr.URI(document.location.toString()).fragment;

					if (hash.length) {
						$.each(self.modules, function () {
							var item = this;
							if (item.id == hash) {
								self.showItem(item, self.options.addToHistory, true);
							}
						});
					}
					self.ignoreHashChange = false;
				}
			});
		}

	};

	TabbedModule.prototype = {
		showItem: function (activate, setHash, setFocus) {
			var self = this;
			var url = new netr.URI(document.location.toString());
			$.each(this.modules, function () {
				if (activate === this) {
					this.tab.addClass(self.options.selectedClass).find('a').attr({
						'aria-selected': 'true',
						'tabindex': '0'
					});
					if (setFocus === true) {
						this.tab.find('a').focus();
					}
					this.module.removeClass('hidden-tab').attr('aria-hidden', 'false');
					if (setHash !== false) {
						url.fragment = this.id;
						document.location = url.toString();
					}
					this.tab.trigger('show_module.netrtabbedmodule', this);
					self.activeModule = this;
					self.ignoreHashChange = false;
				} else {
					this.tab.removeClass(self.options.selectedClass).find('a').attr({
						'aria-selected': 'false',
						'tabindex': '-1'
					});
					this.module.addClass('hidden-tab').attr('aria-hidden', 'true');
					this.tab.trigger('hide_module.netrtabbedmodule', this);
				}
			});
		}
	};

	$.fn.netrtabbedmodule = function (options) {
		return this.each(function () {
			new TabbedModule($(this), options);
		});
	};

}(jQuery));