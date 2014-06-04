<?php //dpr($content); ?>
<div class="m teaser">
    <div class="m-h teaser-img">
    <?php if (isset($content['field_image']['#items'][0]) && $content['field_image']['#items'][0]['uri']): ?>
      <a href="<?php print isset($content['field_teaser_link']['#items'][0]['url']) ? $content['field_teaser_link']['#items'][0]['url'] : '#empty' ; ?>" target="<?php print isset($content['field_teaser_link']['#items'][0]['attributes']['target']) ? $content['field_teaser_link']['#items'][0]['attributes']['target'] : '_self'; ?>">
        <img src="<?php print file_create_url($content['field_image']['#items'][0]['uri']); ?>" width="<?php print $content['field_image']['#items'][0]['width']; ?>" height="<?php print $content['field_image']['#items'][0]['height']; ?>" title="<?php print $content['field_image']['#items'][0]['title']; ?>" alt="<?php print $content['field_image']['#items'][0]['alt']; ?>">
      </a>
    <?php endif; ?>
    </div>
    <div class="m-c">
    	<h2><a href="<?php print isset($content['field_teaser_link']['#items'][0]['url']) ? $content['field_teaser_link']['#items'][0]['url'] : '#empty' ; ?>" target="<?php print isset($content['field_teaser_link']['#items'][0]['attributes']['target']) ? $content['field_teaser_link']['#items'][0]['attributes']['target'] : '_self'; ?>"><?php print $title; ?></a></h2>
    	<p><?php print nl2br($content['body'][0]['#markup']); ?></p>
    </div>
</div>
