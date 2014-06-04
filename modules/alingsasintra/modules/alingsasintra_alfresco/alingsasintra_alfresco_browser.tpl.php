<div class="alfresco-browser">

  <script type="text/javascript">
	jQuery(function(){

		sortUl('.al-content > ul');
		var al_elements = new Object();
		jQuery('.alfresco-browser').delegate("span.add", "mouseenter mouseleave", function(){
            jQuery(this).closest('li').toggleClass('over');
    });
		jQuery('.alfresco-browser').delegate('span.add', 'click', function(event) {
			var url = '';
			var obj = jQuery(this).parent().children('a');
			var title = obj.text();
			if(obj.hasClass('document')) {
				url = obj.attr('href');
			}
			else {
				var path = [];
				obj.parents('li').children('a').each(function(index){
					  if(jQuery(this).attr('href') == 'null') {
						  path.splice(0,0, jQuery(this).text());
					  }
					  else {
						  url = jQuery(this).attr('href').replace('dashboard', 'documentlibrary#filter=path|/' + path.join('/') + '&page=1');
					  }
				});
			}
			window.alfield.parent().parent().find('.link-field-url input').val(url);
			window.alfield.parent().parent().find('.link-field-title input').val(title);
			window.aldialog.dialog('close');
			return false;
		});
		jQuery('.alfresco-browser').delegate('a', 'click', function(event) {
			if(jQuery(this).hasClass('document')) {
				window.alfield.parent().parent().find('.link-field-url input').val(jQuery(this).attr('href'));
				window.alfield.parent().parent().find('.link-field-title input').val(jQuery(this).text());
				window.aldialog.dialog('close');
				return false;
			}
			var item = jQuery(this).attr('id');
			if(al_elements.hasOwnProperty(item)) {
				jQuery('#' + item).parent('li').children('ul').slideToggle();
			}
			else {
				jQuery('#' + item).after('<span class="' + item + ' throbber">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span>');
  			jQuery.getJSON('/alfresco/browse/get/' + item, function(data) {
  				ul = jQuery('<ul/>');
  				jQuery.each(data, function(key, val) {
  				  if(val.private == true) {
  					  ul.append(jQuery('<li/>').append('<span class="private ' + val.type + '" href="' + val.href + '" id="' + val.id + '">' + val.name + '</span>'));
  					} else {
  						ul.append(jQuery('<li/>').append('<a class="' + val.type + '" href="' + val.href + '" id="' + val.id + '">' + val.name + '</a><span class="add">välj</span>'));
  					}
  				});
  				sortUl(ul);
  				jQuery('#' + item).parent().append(ul);
  				al_elements[item] = true;
  			}).error(function(){
  			  alert('Fel! Kunde inte ladda listan.');
  			}).complete(function(){
  	  		jQuery('.' + item + '.throbber').remove();
  			});
			}
			return false;
	  });

		function sortUl(selector) {
		    jQuery(selector).children("li").sort(function(a, b) {
		        var upA = jQuery(a).text().toUpperCase();
		        var upB = jQuery(b).text().toUpperCase();
		        return (upA < upB) ? -1 : (upA > upB) ? 1 : 0;
		    }).appendTo(selector);
		}
	});
	</script>
  <div class="al-content">
    <ul>
      <?php foreach($sites as $site): ?>
        <?php if($site->isPrivate()): ?>
      <li><span class="site private"><?php print $site->title; ?></span></li>
        <?php else : ?>
      <li><a class="site" href="<?php print $site->getHref(); ?>" id="<?php print $site->getId(); ?>"><?php print $site->title; ?></a></li>
        <?php endif; ?>
      <?php endforeach; ?>
    </ul>
    &nbsp;
  </div>
</div>
