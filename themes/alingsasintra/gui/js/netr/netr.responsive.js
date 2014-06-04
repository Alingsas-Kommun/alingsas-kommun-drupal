// Functionality for settings breakpoints for responsive websites.
netr.responsive = {
	breakpoints: [],

	// Adds a breakpoint object with the following attributes:
	//
	// condition = a function returning a boolean for whether this breakpoint should be active or not.
	// enter     = a function which will execute everytime condition() turns from false to true.
	// exit      = a function which will execute everytime condition() turns from true to false.
	//
	addBreakpoint: function(breakpoint) {
		netr.responsive.breakpoints.push(breakpoint);
	},

	// Activate the breakpoing functionality
	activate: function() {
		jQuery(window).bind('resize orientationchange', function() {
			netr.responsive.checkBreakpoints();
		});
		netr.responsive.checkBreakpoints();
	},

	// Loop through all breakpoints and determine which ones are active.
	checkBreakpoints: function() {
		// Build temporary array of active breakpoints
		var active_breakpoints = jQuery.grep(netr.responsive.breakpoints, function(breakpoint, index) {
			return breakpoint.is_active;
		});

		// Build temporary array of inactive breakpoints.
		var inactive_breakpoints = jQuery.grep(netr.responsive.breakpoints, function(breakpoint, index) {
			return !breakpoint.is_active;
		});


		// Check all active breakpoints first.
		jQuery.each(active_breakpoints, function(index, breakpoint) {
			if (!breakpoint.condition()) {
				// We have left this breakpoint.
				if (typeof breakpoint.exit == 'function') {
					breakpoint.exit();
				}
				breakpoint.is_active = false;
			}
		});

		// Check all inactive breakpoints.
		jQuery.each(inactive_breakpoints, function(index, breakpoint) {
			if (breakpoint.condition()) {
				// We have entered this breakpoint.
				if (typeof breakpoint.enter == 'function') {
					breakpoint.enter();
				}
				breakpoint.is_active = true;
			}
		});
	}
};

// Check for media query support
// Taken from https://github.com/paulirish/matchMedia.js
/*! matchMedia() polyfill - Test a CSS media type/query in JS. Authors & copyright (c) 2012: Scott Jehl, Paul Irish, Nicholas Zakas. Dual MIT/BSD license */
window.matchMedia = window.matchMedia || (function(doc, undefined){
	var bool,
		docElem = doc.documentElement,
		refNode = docElem.firstElementChild || docElem.firstChild,
		// fakeBody required for <FF4 when executed in <head>
		fakeBody = doc.createElement('body'),
		div = doc.createElement('div');
	div.id = 'mq-test-1';
	div.style.cssText = "position:absolute;top:-100em";
	fakeBody.style.background = "none";
	fakeBody.appendChild(div);
	return function(q){
		div.innerHTML = '&shy;<style media="'+q+'"> #mq-test-1 { width: 42px; }</style>';
		docElem.insertBefore(fakeBody, refNode);
		bool = div.offsetWidth == 42;
		docElem.removeChild(fakeBody);
			return { matches: bool, media: q };
	};
})(document);