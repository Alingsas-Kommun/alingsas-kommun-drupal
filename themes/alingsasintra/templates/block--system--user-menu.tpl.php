<?php
  global $user;
  $vars = array();
  $user = user_load($user->uid);
  $vars['user_firstname'] = $user->name;
  $vars['user_lastname'] = '';
  $vars['user_ou'] = '';
  $user_firstname = field_get_items('user', $user, 'field_firstname');
  $user_lastname = field_get_items('user', $user, 'field_lastname');
  $user_ou = field_get_items('user', $user, 'field_ou');
  if ($user_firstname) {
    $vars['user_firstname'] = $user_firstname[0]['value'];
  }
  if ($user_lastname) {
    $vars['user_lastname'] = $user_lastname[0]['value'];
  }
  if ($user_ou) {
    $vars['user_ou'] = $user_ou[0]['value'];
  }
?>
<div class="user-profile">
	<div class="user cf">
		<?php print theme('user_picture', array('account' =>$user)); ?>
		<div class="cf">
			<p><a href="/user"><?php print $vars['user_firstname'] ?> <?php print $vars['user_lastname'] ?></a><a class="last leaf" href="/user/logout">Logga ut</a></p>
			<ul class="menu">
				<li class="first leaf"><?php print $vars['user_ou'] ?></li>
			</ul>
			<!-- <p id="#user-message" class="message" style="clear:both;">&nbsp;</p> -->
		</div>
	</div>
</div>
<!-- deactivate until vision is working properly
<script type="text/javascript">
jQuery(function(){
	var userstatustop = [];
	jQuery.getJSON('/vision/<?php print $user->uid; ?>/status', function(data) {
		if(typeof data.available != 'undefined') {
			if(typeof data.message != 'undefined') {
				  userstatustop.push(data.message);
			}
			if(typeof data.start != 'undefined') {
			  if(typeof data.stop != 'undefined') {
				  data.start = data.start + ' - ' + data.stop;
			  }
			  userstatustop.push(data.start);
			}
			if(userstatustop.length == 0) {
				userstatustop.push('Anträffbar');
			}
		}
		else {
			userstatustop.length = 0;
			userstatustop.push('Ingen information');
		}
	}).error(function(){
	  userstatustop.length = 0;
	  userstatustop.push('ingen information');
	}).complete(function(){
	  jQuery('.user-profile .message').html(userstatustop.join(', '));
	});
});
</script> -->
