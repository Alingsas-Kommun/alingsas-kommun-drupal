</div>

<div class="m news-listing company-news unit">
  <div class="m-h cf">
		<h2>Nyheter från <?php print drupal_get_title(); ?> </h2>
	</div>
	<?php if ($exposed): ?>
  <div class="row cols-3 cf">
      <?php print $exposed; ?>
  </div>
  <?php endif; ?>

  <div class="m-c cf">
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
</div>

<div>