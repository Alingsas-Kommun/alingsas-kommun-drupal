
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

</div>