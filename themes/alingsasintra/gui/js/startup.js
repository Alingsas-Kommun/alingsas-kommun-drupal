/*
 * STARTUP SCRIPTS 
 */

// Initialize on document ready
jQuery(function() {	
	// Add class for javascript detection
	jQuery('html').removeClass('no-js').addClass('js');
	(function() {
		var image = new Image();
		image.onload = function() {
			if (image.width > 0) {
				jQuery('html').addClass('images-on');
			}
		};
		image.src = '/sites/all/themes/alingsasintra/gui/i/px.png';
	}());

	// Enable html5 placeholder attributes for older browsers
	// jQuery('input[placeholder]').placeholder();

	// Add rel attribute to external links
	//jQuery('a:external').attr('rel', 'external');

	// Add tabs to modules, if loaded
	if (typeof jQuery.fn.netrtabbedmodule != 'undefined') {
		jQuery('.tabbed-module').netrtabbedmodule();
	}

	// Print button
	jQuery('.article-info').append(jQuery('<a>', {
		id: 'print-link',
		href: '#',
		html: 'Skriv ut sidan',
		click: function (e) {
			e.preventDefault();
			window.print();
		}
	}));
	
	jQuery('select.form-select').not('.webform-datepicker select').netrCustomSelect();
	
	jQuery('a').not('.nav-main a, .nav-sub a, .job-module a, #message a, .function-nav a, .teaser-img a').filter(function() {
    	return this.hostname && this.hostname !== location.hostname;
 	 }).after(' <img src="/sites/all/themes/alingsasintra/gui/i/icons/extlink.png" alt="external link" class="ext-link"/>');
  
	// Toggle modules 
	jQuery('.toggle .m-h h2').append('<button>Toggle module</button>');
	//close user boxes by default
	jQuery('.region-sidebar-third .toggle .m-h').removeClass('toggle-btn').each(function(){
		jQuery(this).next().hide();
		if(jQuery.cookie('widget' + jQuery(this).parent('div').attr('id')) == 'open'){
			jQuery(this).next().show();
		}
		else {
			jQuery(this).addClass('closed');
			jQuery(this).addClass('toggle-btn');
		}
	});
	//open content boxes by default
	jQuery('.region-content .toggle .m-h').removeClass('toggle-btn').each(function(){
		jQuery(this).next().hide();
		if(jQuery.cookie('widget' + jQuery(this).parent('div').attr('id')) == 'closed'){
			jQuery(this).next().hide();
			jQuery(this).addClass('toggle-btn');
		}
		else {
			jQuery(this).addClass('open');
			jQuery(this).next().show();
		}
	});
    jQuery('.toggle .m-h').click(function() {
    	var cookieName = 'widget' + jQuery(this).parent('div').attr('id');
    	var hiddenElem = jQuery(this).next();
    	if(hiddenElem.is(':hidden')) {
    		jQuery(this).removeClass('toggle-btn');
    		jQuery(this).addClass('open');
	    	hiddenElem.slideDown(200);
	    	jQuery.cookie(cookieName, 'open', { path: '/' });
    	}
    	else {
    		jQuery(this).addClass('toggle-btn');
    		jQuery(this).removeClass('open');
	    	hiddenElem.slideUp(200);
	    	jQuery.cookie(cookieName, 'closed', { path: '/' });
    	}
        return false;
    });
    
	function close(link) {
		link.next().hide();
		link.removeClass('open');
		jQuery(document).unbind('.close');
	}
		
	function open(link) {
		link.addClass('open');
		link.next().show();
	}
	
    //back button
    jQuery('a.back').click(function(e){
       e.preventDefault();
       history.back(1);
    });
	// Set up responsive breakpoints
	// max-width:940px
	netr.responsive.addBreakpoint((function () {
		return {
			condition: function () {
				return window.matchMedia('only screen and (max-width:940px)').matches;
			},
			enter: function () {
			
				// Initialise nav menu for narrow viewports
				jQuery('.nav-main ul').netrNavMenu();
				jQuery('.header-nav').addClass('closedMenu');
				
				//Initialise sub menu for narrow viewports
				jQuery('.nav-sub').netrSubNav();
				jQuery('.region-sidebar-menu').addClass('closedMenu');
				
				//Initialize search for narrow viewports
				jQuery('.header-search').each(function() {
					var search = jQuery(this);
					var btn = jQuery('<button />', {
						type: 'button',
						text: 'Sök',
						'class': 'search-toggle button'
					}).bind('click', function() {
						if ('.button.open') {
							jQuery('.profile-toggle.button.open').next().hide();
						}
						var link = jQuery(this);
							if(link.next().is(':visible') != '') {
								close(link);
							} 
							else {
								open(link);
							}	
						jQuery('#header, #section-content').bind('click.close', function(e) {
							if(!jQuery(e.target).is('#edit-keys' || '.header-search' )) {
								close(link);
							}	
						});
						jQuery(document).keydown(function(e) {
								if (e.keyCode == 27) {
									close(link)
							 } 
						});
						return false;
					}).prependTo('.header .container-12');
				});
				jQuery('.header-search').insertAfter('.search-toggle.button').hide();
				
				//Move modules
				jQuery('.grid-6 + .grid-3').appendTo('#footer .container-12');
				
				//Initialize profile for narrow viewports
				jQuery('.region-sidebar-third').appendTo('.header .container-12');
				if(jQuery('.region-sidebar-third').is(':visible') != '') {
					jQuery('.region-sidebar-third').hide();
				}
				
				var profileBtn = jQuery('<button />', {
						type: 'button',
						text: 'Mina inställningar',
						'class': 'profile-toggle button'
					}).bind('click', function() {
					if ('.button.open') {
						jQuery('.search-toggle.button.open').next().hide();
					}
					var link = jQuery(this);
						if(link.next().is(':visible') != '') {
							close(link);
						} 
						else {
							open(link);
						}	
					jQuery('#header, #section-content').bind('click.close', function(e) {
						if(!jQuery(e.target).is('.user-profile' || '.region-sidebar-third')){
							close(link);
						}	
					});
					jQuery(document).keydown(function(e) {
							if (e.keyCode == 27) {
								close(link)
						 } 
					});
					return false;
				}).insertBefore('.region-sidebar-third');	
			},
			
			exit: function () {
				// Remove netrNavMenu functionality
				jQuery('.header-nav').removeClass('closedMenu');
				jQuery('.nav-sub').prependTo(jQuery('.region-sidebar-menu'));
				//jQuery('.nav-menu-narrow ul').prependTo(jQuery('.header-third .nav-main'));
				jQuery('.nav-main .nav-menu-narrow').replaceWith(jQuery('.nav-main .nav-menu-narrow > ul'));
				
				//Move back and show search
				jQuery('.header-search').appendTo('.header .grid-6').show();
				
				//Remove buttons
				jQuery('.search-toggle.button').remove();
				jQuery('.profile-toggle.button').remove();
				
				//Move back function nav
				jQuery('#footer .grid-3').insertAfter('.header .grid-6');
				
				//Move back user profile toggle
				jQuery('.region-sidebar-third').appendTo('#section-content .container-12');
				if(jQuery('.region-sidebar-third').is(':hidden') != '') {
					jQuery('.region-sidebar-third').show();
				}
				
				// Expand #nav-sub and remove the toggle button
				jQuery('.region-sidebar-menu').removeClass('closedMenu');
				jQuery('.nav-sub button:first').replaceWith(jQuery('.nav-sub nav h2'));
				jQuery('.nav-sub ul').removeAttr('style');
				
			}
		};
	}()));
	
	// Activate responsive breakpoints
	if ( !jQuery('html:first').hasClass('static') ) {
		netr.responsive.activate();
	}    
	
	
	jQuery('form').submit(function(){
	       if(jQuery('#edit-promote').attr('checked') && jQuery('#edit-field-organizational-structure-und').val().length <= 0){
	         jQuery('#edit-field-organizational-structure').addClass('tr-error');
	         alert('Du måste välja ut minst en grupp om Du begränsa målgrupp. Det gör du under "Publicera till".');
	         jQuery('html, body').animate({
	             scrollTop: jQuery("#edit-promote").offset().top
	         }, 500);
	         return false;
	       }
	    });
 
});

	jQuery(window).load(function() {
	// Set width for image captions based on image width.
	jQuery('span.caption').each(function () {
		var caption = jQuery(this);
		var img = caption.children('img');
		if (img.length && caption.is(':not(.fullwidth)') && caption.is(':not(.fullwidth-dec)')) {
			caption.css('width', img.outerWidth() || '');
		}
	});
	
});
