<div id="tool" class="m toggle-module toggle cf open">
	<div class="m-h cf">
		<span class="toggle-icon tool"></span>
		<h2>Verktyg</h2>
	</div>
	<div class="m-c cf">
		<div class="toggle-list">
		<?php if ($rows): ?>
        <?php print $rows; ?>
    <?php elseif ($empty): ?>
      <div class="view-empty">
          <?php print $empty; ?>
      </div>
    <?php endif; ?>
    </div>
    <?php if ($pager): ?>
      <?php print $pager; ?>
    <?php endif; ?>
	</div>
</div>