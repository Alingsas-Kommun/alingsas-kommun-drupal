				<?php print render($content['field_image']); ?>
				<h3><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h3>
				<span class="date"><?php print $content['field_date'][0]['#markup']; ?></span>
				<p><?php if(isset($content['field_introduction'])): ?>
				  <?php print $content['field_introduction']['#items'][0]['safe_value']; ?></p>
				<?php else: ?>
				  <?php print text_summary($content['body'][0]['#markup'], null, 75); ?>
				<?php endif; ?></p>
				<div class="news-meta">
					<?php if($comment_count):?><span class="comments"><?php print $comment_count; ?></span><?php endif; ?>
				</div>
