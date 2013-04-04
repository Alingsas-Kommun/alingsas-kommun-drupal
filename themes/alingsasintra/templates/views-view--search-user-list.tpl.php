
	<?php if ($exposed): ?>
    <div class="row cols-3 cf" style="">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <div class="m news-listing company-news">
	  <?php if ($header): ?>
    <p>
      <?php print $header; ?>
    </p>
  <?php endif; ?>
	<?php if ($rows): ?>
      <?php print $rows; ?>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>
  <?php if ($pager): ?>
  <div class="paging cf">
    <?php print $pager; ?>
  </div>
  <?php endif; ?>
<script type="text/javascript">

jQuery(function(){
	jQuery('.user-status').each(function(){
		var userstatus = [];
		var id = jQuery(this).attr('id').substr(5)
		jQuery.getJSON('/vision/' + id + '/status', function(data) {
			if(typeof data.available != 'undefined') {
  			if(typeof data.message != 'undefined') {
  				  userstatus.push(data.message);
  			}
  			if(typeof data.start != 'undefined') {
  			  if(typeof data.stop != 'undefined') {
  				  data.start = data.start + ' - ' + data.stop;
  			  }
  			  userstatus.push(data.start);
  			}
  			if(userstatus.length == 0) {
  				userstatus.push('Anträffbar');
  			}
			}
			else {
				userstatus.length = 0;
				userstatus.push('Ingen information');
			}
		}).error(function(){
		  userstatus.length = 0;
		  userstatus.push('Ingen information');
		}).complete(function(){
		  jQuery('#user-' + id).html(userstatus.join(', '));
		});
	});
});

</script>

</div>