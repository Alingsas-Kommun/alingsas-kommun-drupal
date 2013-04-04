<?php //dpr($content); ?>
<div class="m teaser">
	<div class="m-h">
    	<?php print render($content['field_image']); ?>
    </div>
    <div class="m-c">
    	<h2><a href="<?php print $content['field_teaser_link'][0]['#markup']; ?>" target="<?php print isset($content['field_teaser_link']['#items'][0]['attributes']['target']) ? $content['field_teaser_link']['#items'][0]['attributes']['target'] : '_self'; ?>"><?php print $title; ?></a></h2>
    	<p><?php print nl2br($content['body'][0]['#markup']); ?></p>
    </div>
</div>
