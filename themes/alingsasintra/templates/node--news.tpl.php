<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php if(isset($content['field_introduction']) && $content['field_introduction']): ?>
    <p class="intro">
      <?php print nl2br($content['field_introduction']['#items'][0]['safe_value']); ?>
    </p>
    <?php endif; ?>

    <?php if(isset($content['field_image']) && $content['field_image']): ?>
    <div class="top-image">
      <?php print render($content['field_image']); ?>
    </div>
    <?php endif; ?>

  	<?php print render($content['body']); ?>

	<?php if(isset($content['field_url']) && $content['field_url']): ?>
  	<div class="m related-files">
  	  <div class="m-h">
      	<h2>Relaterad information</h2>
      </div>
      <div class="m-c">
      	<?php print render($content['field_url']); ?>
      </div>
    </div>
    <?php endif; ?>


    <div class="main-content-meta">
    <?php if(isset($content['field_contact_user']['#items'][0]['entity']) || isset($content['field_contact_name'])): ?>
    <p><strong>Kontakt:</strong>
  	  <?php if(isset($content['field_contact_user']['#items'][0]['entity'])): ?>
      <a href="/user/<?php print $content['field_contact_user']['#items'][0]['entity']->uid; ?>"><?php print $content['field_contact_user']['#items'][0]['entity']->field_firstname['und'][0]['safe_value']; ?> <?php print $content['field_contact_user']['#items'][0]['entity']->field_lastname['und'][0]['safe_value']; ?></a>
        <?php if(isset($content['field_contact_user']['#items'][0]['entity']->field_user_email['und'][0]['safe_value'])) : ?>
        <a href="mailto:<?php print $content['field_contact_user']['#items'][0]['entity']->field_user_email['und'][0]['safe_value']; ?>"><?php print $content['field_contact_user']['#items'][0]['entity']->field_user_email['und'][0]['safe_value']; ?></a>
        <?php endif; ?>
      <?php elseif(isset($content['field_contact_name']) && $content['field_contact_name']):?>
         <?php print $content['field_contact_name']['#items'][0]['safe_value']; ?> <a href="mailto:<?php print $content['field_contact_email']['#items'][0]['safe_value']; ?>"><?php print $content['field_contact_email']['#items'][0]['safe_value']?></a>
      <?php endif; ?>

      </p>
    <?php endif; ?>

  		<p>Publicerad av: <?php print $name; ?>den <span> <?php print $date; ?></span></p>
  	</div>

  </div>

<?php if(isset($content['field_general_information']) && $content['field_general_information']): ?>
</div>
<div id="external-information" class="m related-info toggle">
	<div class="m-h">
    <h2>Allmän information</h2>
  </div>
  <div class="m-c">
      <?php print render($content['field_general_information']); ?>
    </div>
</div>
<div>
<?php endif; ?>

<?php if($content['comments']):?>
</div>
<div id="showcomments" class="m comments toggle">
    <div class="m-h open">
    	<h2>Kommentarer <span>(<?php print $comment_count; ?>)</span></h2>
    </div>
    <div class="m-c">
    <?php print render($content['comments']); ?>
    </div>
</div>
<div>
<?php endif; ?>