(function($){

	$.fn.netrNavMenu = function( options ) {
		var settings = {
			narrowClass: 'nav-menu-narrow',
			expandedClass: 'expanded',
			menuText: 'Meny',
			showText: 'visa',
			hideText: 'dölj'
		};
		return this.each(function(){
			var $this = $(this);
			if (options) {
				$.extend(settings, options);
			}

			// Show the menu
			var showMenu = function() {
				wrap.addClass(settings.expandedClass);
				$button.find('span > span').text(' (' + settings.hideText + ')');
			};

			// Hide the menu
			var hideMenu = function() {
				wrap.removeClass(settings.expandedClass);
				$button.find('span > span').text(' (' + settings.showText + ')');
			};

			$this.wrap('<div class="' + settings.narrowClass + '" />');
			var wrap = $this.parent();

			// Make sure there is always a selected item
			var selectedItem = $this.find('> li.active:first');
			if (!selectedItem.length) {
				selectedItem = $this.find('> li:first');
				selectedItem.addClass('active');
			}

			// Create and insert button
			var $button = $('<button type="button" title="' + settings.menuText + '"><span>' + settings.menuText + '<span class="structural"> (' + settings.showText + ')</span></span></button>');
			$button.click(function() {
				if (wrap.hasClass(settings.expandedClass)) {
					hideMenu();
				} else {
					showMenu();
				}
			});
			$button.insertBefore($this);

			// Close the menu and put focus on the button when ESC is pressed
			wrap.bind('keydown.netrNavMenu', function(e) {
				if (e.keyCode == 27) {
					hideMenu();
					$button.focus();
				}
			});
		});
	};

})(jQuery);