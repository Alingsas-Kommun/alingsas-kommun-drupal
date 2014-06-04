
	<?php if ($exposed): ?>
    <div class="row cols-3 cf" style="display: none;">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <?php if ($exposed): ?>
  <?php
  $year = date('Y');
  if($_GET['created']['min']) {
    $time = strtotime($_GET['created']['min']);
    $time_end = strtotime($_GET['created']['max']);
    if(($time+32*24*60*60) > $time_end) {
      $month = date('m', $time);
    }
    $year = date('Y', $time);
  }
  ?>
    <form class="form-general">
						<div class="row cols-4 cf">
							<div class="col col-1 small">
								<div class="select">
								    <label for="select1">År</label>
								    <div class="select"><select class="form-select" name="select1" id="select1">
								    	<option value="2012" <?php print($year==2012)?'selected':'';?>>2012</option>
								    	<option value="2013" <?php print($year==2013)?'selected':'';?>>2013</option>
								    	<option value="2014" <?php print($year==2014)?'selected':'';?>>2014</option>
								    </select></div>
								</div>
							</div>
							<div class="col col-2 small">
								<div class="select">
								    <label for="select2">Månad</label>
								    <div class="select"><select class="form-select" name="select2" id="select2">
								      <option value="" <?php print(!$month)?'selected':'';?>>Alla</option>
								    	<option value="01" <?php print($month=='01')?'selected':'';?>>Januari</option>
								    	<option value="02" <?php print($month=='02')?'selected':'';?>>Februari</option>
								    	<option value="03" <?php print($month=='03')?'selected':'';?>>Mars</option>
								    	<option value="04" <?php print($month=='04')?'selected':'';?>>April</option>
								    	<option value="05" <?php print($month=='05')?'selected':'';?>>Maj</option>
								    	<option value="06" <?php print($month=='06')?'selected':'';?>>Juni</option>
								    	<option value="07" <?php print($month=='07')?'selected':'';?>>Juli</option>
								    	<option value="08" <?php print($month=='08')?'selected':'';?>>Augusti</option>
								    	<option value="09" <?php print($month=='09')?'selected':'';?>>September</option>
								    	<option value="10" <?php print($month=='10')?'selected':'';?>>Oktober</option>
								    	<option value="11" <?php print($month=='11')?'selected':'';?>>November</option>
								    	<option value="12" <?php print($month=='12')?'selected':'';?>>December</option>
								    </select></div>
								</div>
							</div>

							<div class="col col-4 mini form-actions">
								<input type="button" value="Filtrera" name="submit" id="send-filter">
							</div>
						</div>
					</form>
<script type="text/javascript">
jQuery(function(){
  jQuery('#send-filter').click(function(){
	  if(jQuery('#select2').val()){
	    jQuery('#edit-created-min').val(jQuery('#select1').val() + '-' + jQuery('#select2').val() + '-01 00:00:00');
	    jQuery('#edit-created-max').val(jQuery('#select1').val() + '-' + jQuery('#select2').val() + '-31 23:59:59');
    }
    else {
    	jQuery('#edit-created-min').val(jQuery('#select1').val() + '-01-01 00:00:00');
	    jQuery('#edit-created-max').val(jQuery('#select1').val() + '-12-31 23:59:59');
    }
    jQuery('#views-exposed-form-personalized-content-page-my-news').submit();
	});
});
</script>
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

</div>