(function($) {
	$.fn.netrCustomSelect = function(settings) {
		var config = {
			replacedClass: 'replaced', // Class name added to replaced selects
			customSelectClass: 'custom-select', // Class name of the (outer) inserted span element
			activeClass: 'active', // Class name assigned to the fake select when the real select is in hover/focus state
			wrapperElement: '<div class="custom-select-container" />' // Element that wraps the select to enable positioning
		};
		if (settings) {
			$.extend(config, settings);
		}
		this.each(function() {
			var select = $(this);
			select.addClass(config.replacedClass);
			select.wrap(config.wrapperElement);

			var update = function() {
				val = $('option:selected', this).text();
				span.find('span span').text(val);
			};

			// Update the fake select when the real select’s value changes
			select.change(update);

			/* Gecko browsers don't trigger onchange until the select closes, so
			 * changes made by using the arrow keys aren't reflected in the fake select.
			 * See https://bugzilla.mozilla.org/show_bug.cgi?id=126379.
			 * IE normally triggers onchange when you use the arrow keys to change the selected
			 * option of a closed select menu. Unfortunately jQuery doesn’t seem able to bind to this.
			 * We could overwrite any existing onchange handlers, but that isn’t nice.
			 * As a workaround the text is also updated when any key is pressed and then released.
			 */
			select.keyup(update);

			/* Create and insert the spans that will be styled as the fake select
			 * To prevent (modern) screen readers from announcing the fake select in addition to the real one,
			 * aria-hidden is used to hide it.
			 */
			var span = $('<span class="' + config.customSelectClass + '" aria-hidden="true"><span><span>' + $('option:selected', this).text() + '</span></span></span>');
			select.after(span);
			// Add or remove a class name to enable styling of hover/focus states
			select.bind({
				mouseenter: function() {
					span.addClass(config.activeClass);
				},
				mouseleave: function() {
					span.removeClass(config.activeClass);
				},
				focus: function() {
					span.addClass(config.activeClass);
				},
				blur: function() {
					span.removeClass(config.activeClass);
				}
			});
		});
	};
})(jQuery);