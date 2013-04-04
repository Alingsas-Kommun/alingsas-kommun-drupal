<div class="m company-news">
	<div class="m-h cf">
		<h2>Gemensamma Nyheter</h2>
	</div>
	<div class="m-c cf">
		<?php if ($rows): ?>
        <?php print $rows; ?>
    <?php elseif ($empty): ?>
    <div class="view-empty">
        <p><?php print $empty; ?></p>
    </div>
    <?php endif; ?>

    <?php if ($pager): ?>
      <?php print $pager; ?>
    <?php endif; ?>

    <?php if ($more): ?>
       <div class="more-link">
			<a href="/nyheter"><button>Visa fler</button></a>
		  </div>
    <?php endif; ?>
	</div>
</div>
