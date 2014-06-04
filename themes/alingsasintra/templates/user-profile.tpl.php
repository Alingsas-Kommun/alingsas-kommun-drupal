						<div class="user-status cf">
<?php
print render($user_profile['user_picture']);
?>
						<!--	<div class="user-vision">
								<h2>Min status</h2>
								<p>Laddar...</p>
							</div> -->
						</div>
				<div class="m contact-info">
	<div class="m-h">
    	<h2>Kontaktinformation</h2>
    </div>
    <div class="m-c">
    	<ul>
    		<li>
    			<strong>E-post:</strong> <?php print isset($user_profile['group_user_contact']['field_user_email'][0]['#markup']) ? '<a href="mailto:' . $user_profile['group_user_contact']['field_user_email'][0]['#markup'] . '">' . $user_profile['group_user_contact']['field_user_email'][0]['#markup'] . '</a>' : '' ?>
    		</li>
    		<li>
    			<strong>Telefon:</strong> <?php print isset($user_profile['group_user_contact']['field_user_phone'][0]['#markup']) ? $user_profile['group_user_contact']['field_user_phone'][0]['#markup'] : '' ?>
    		</li>
    		<li>
    			<strong>Mobil:</strong> <?php print isset($user_profile['group_user_contact']['field_user_mobile'][0]['#markup']) ? $user_profile['group_user_contact']['field_user_mobile'][0]['#markup'] : '' ?>
    		</li>
    		<li>
    			<strong>Fax:</strong> <?php print isset($user_profile['group_user_contact']['field_user_fax'][0]['#markup']) ? $user_profile['group_user_contact']['field_user_fax'][0]['#markup'] : '' ?>
    		</li>
    		<li>
    			<strong>Adress:</strong> <?php print isset($user_profile['group_user_contact']['field_user_address'][0]['#markup']) ? $user_profile['group_user_contact']['field_user_address'][0]['#markup'] : '' ?>
    		</li>
    	</ul>
    </div>
</div>

<?php if(isset($user_profile['field_organizational_structure']['#items']) && count($user_profile['field_organizational_structure']['#items'])): ?>
<div class="m contact-info org">
	<div class="m-h">
    	<h2>Organisation</h2>
    </div>
    <div class="m-c">
    	<ul>
  <?php foreach($user_profile['field_organizational_structure']['#items'] as $item): ?>
      <li>
    			<a href="/news/byterm/<?php print $item['tid']; ?>"><?php print $item['taxonomy_term']->name; ?></a>
    		</li>
  <?php endforeach; ?>
    	</ul>
    </div>
</div>
<?php endif; ?>
<?php if(isset($user_profile['field_target_groups']['#items']) && count($user_profile['field_target_groups']['#items'])): ?>
<div class="m contact-info org">
	<div class="m-h">
    	<h2>Målgrupper</h2>
    </div>
    <div class="m-c">
    	<ul>
  <?php foreach($user_profile['field_target_groups']['#items'] as $item): ?>
      <li>
    			<a href="/news/byterm/<?php print $item['tid']; ?>"><?php print $item['taxonomy_term']->name; ?></a>
    		</li>
  <?php endforeach; ?>
    	</ul>
    </div>
</div>
<?php endif; ?>
<?php if(isset($user_profile['field_firstname']['#object']->uid)) :?>
<!-- <script type="text/javascript">
jQuery(function(){
	var userstatus = [];
	jQuery.getJSON('/vision/<?php print $user_profile['field_firstname']['#object']->uid;?>/status', function(data) {
		if(typeof data.available != 'undefined') {
			if(typeof data.message != 'undefined') {
				  userstatus.push(data.message);
			}
			if(typeof data.start != 'undefined') {
			  if(typeof data.stop != 'undefined') {
				  data.start = data.start + ' - ' + data.stop;
			  }
			  userstatus.push(data.start);
			}
			if(userstatus.length == 0) {
				userstatus.push('Anträffbar');
			}
		}
		else {
			userstatus.length = 0;
			userstatus.push('Ingen information');
		}
	}).error(function(){
	  userstatus.length = 0;
	  userstatus.push('Ingen information');
	}).complete(function(){
	  jQuery('.main-content .user-status p').html(userstatus.join(', '));
	});
});
</script> -->
<?php endif; ?>
