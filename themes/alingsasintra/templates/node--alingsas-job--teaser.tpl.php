      	<h3><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h3>
				<span class="date"><?php print render($content['field_jf_publishdate']); ?></span>
				<?php print text_summary($content['body'][0]['#markup'], null, 300); ?>
				<div class="news-meta">
				  <?php if($content['field_jf_applicationenddate'] && $content['field_jf_applicationenddate']['#items'][0]['value'] != '1752-12-31 23:00:00'): ?>
				    <span><?php print render($content['field_jf_applicationenddate']); ?></span>
					<?php endif; ?>
				</div>
