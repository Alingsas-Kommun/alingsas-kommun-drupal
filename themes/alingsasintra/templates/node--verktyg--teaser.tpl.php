				<h3><a href="<?php print $content['field_link']; ?>"><?php print $title; ?></a></h3>
				<span class="date"><?php print $date; ?></span>
				<p>
				 <?php print $content['body'][0]['#markup']; ?>
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
				</div>
