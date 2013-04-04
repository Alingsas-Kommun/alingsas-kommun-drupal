<?php if(isset($content['field_image']) && (!isset($view->current_display) || $view->current_display != 'block_common')):?>
				<?php print render($content['field_image']); ?>
<?php endif; ?>
				<h3><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h3>
				<span class="date"><?php print $date; ?></span>
				<p>
				<?php if(isset($content['field_introduction'][0]['#markup']) && $content['field_introduction'][0]['#markup']): ?>
				  <?php print $content['field_introduction'][0]['#markup']; ?>
				<?php else: ?>
				  <?php print text_summary($content['body'][0]['#markup'], null, 75); ?>
				<?php endif; ?>
				</p>
				<div class="news-meta">
				  <?php if(isset($content['field_organizational_structure']) && count($content['field_organizational_structure'])):?>
					<ul class="news-group">
					<?php $ellipsis = (isset($content['field_organizational_structure'][3])) ? '&nbsp...' : ''; ?>
					  <?php for($i=0; isset($content['field_organizational_structure'][$i]) && $i <= 2; $i++):?>
						<li>
						  <a href="/nyheter-term/<?php print $content['field_organizational_structure'][$i]['#options']['entity']->tid; ?>" class="cat"><?php print $content['field_organizational_structure'][$i]['#title']; ?></a><?php print $i==2 ? $ellipsis : ''; ?>
						</li>
						<?php endfor; ?>
					</ul>
					<?php endif; ?>
					<?php if($comment_count):?><span class="comments"><?php print $comment_count; ?></span><?php endif; ?>
				</div>
