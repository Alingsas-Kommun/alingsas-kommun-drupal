(function($) {
	$.fn.netrSubNav = function(settings) {
		var config = {
			toggledElement: '.nav-sub ul', // jQuery selector matching the element to toggle
			triggerContainer: '.nav-sub h2', // jQuery selector matching the element to insert the toggle button into
			buttonClass: 'button', // Class name for the trigger button
			openClass: 'open', // Class name added when the toggled element is hidden
			menuText: 'Innehåll', // Text prepended to the button text
			showText: ' (Visa)', // Button text when the toggled element is hidden
			hideText: ' (Dölj)' // Button text when the toggled element is displayed
		};
		if (settings) {
			$.extend(config, settings);
		}
		this.triggerContainer = $(config.triggerContainer);
		return this.each(function() {
			var nav = $(config.toggledElement);
			nav.hide();
			var button = $('<button type="button" class="' + config.buttonClass + '"><span>' + config.menuText + '<span class="structural"> ' + config.showText + '</span></span></button>');
			button.click(function() {
				button.toggleClass(config.openClass);
				var stateText = button.find('span.structural:last');
				if ($.trim(stateText.text()) == $.trim(config.showText)) {
					nav.show();
					stateText.text(config.hideText);
				} else {
					nav.hide();
					stateText.text(config.showText);
				}
			});
			button.insertAfter($(config.triggerContainer));
		});
	};
})(jQuery);