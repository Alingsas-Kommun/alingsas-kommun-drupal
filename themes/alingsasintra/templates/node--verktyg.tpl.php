<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

    <p><?php print render($content['body']); ?></p>

  	<?php if(isset($content['field_link']) && $content['field_link']): ?>
  	<p>
  	<strong>Länk: </strong> <a href="<?php print $content['field_link']['#items'][0]['safe_value']; ?>"><?php print strlen($content['field_link']['#items'][0]['safe_value']) > 50 ? substr($content['field_link']['#items'][0]['safe_value'],0,50).'...' : $content['field_link']['#items'][0]['safe_value']; ?></a>
  	</p>
  	<?php endif; ?>

</div>
