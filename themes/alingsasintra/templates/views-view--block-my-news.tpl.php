<div class="m my-news">
	<div class="m-h">
		<h2>Mina Nyheter</h2>
	</div>
	<div class="m-c cf">
		<?php if ($rows): ?>
        <?php print $rows; ?>
    <?php elseif ($empty): ?>
    <div class="view-empty">
        <p><?php print $empty; ?></p>
    </div>
    <?php endif; ?>

    <?php if ($more): ?>
      <div class="more-link">
			<a href="/mina-nyheter"><button>Visa fler</button></a>
		  </div>
    <?php endif; ?>

	</div>
</div>
