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

  	<?php if((isset($content['field_contact_user']) && $content['field_contact_user']) || (isset($content['field_contact_name']) && $content['field_contact_name'])): ?>
  	<div class="m contact">
  	  <div class="m-h">
      	<h2>Kontakt</h2>
      </div>
      <div class="m-c">
      <?php if(isset($content['field_contact_user']['#items'][0]['entity']) && $content['field_contact_user']['#items'][0]['entity']):?>
      <?php $contact =  $content['field_contact_user']['#items'][0]['entity']; ?>
         <p>
         <?php print $contact->field_firstname['und'][0]['safe_value']; ?> <?php print $contact->field_lastname['und'][0]['safe_value']; ?> <a href="mailto:<?php print $contact->mail; ?>"><?php print $contact->mail?></a>
         </p>
      <?php endif; ?>
      <?php if(isset($content['field_contact_name']) && $content['field_contact_name']):?>
         <p>
         <?php print $content['field_contact_name']['#items'][0]['safe_value']; ?> <a href="mailto:<?php print $content['field_contact_email']['#items'][0]['safe_value']; ?>"><?php print $content['field_contact_email']['#items'][0]['safe_value']?></a>
         <?php if(isset($content['field_contact_more']['#items'][0]['safe_value']) && $content['field_contact_more']['#items'][0]['safe_value']):?>
         <br/>
         <?php print nl2br($content['field_contact_more']['#items'][0]['safe_value']); ?>
         <?php endif; ?>
         </p>
      <?php endif; ?>

      </div>
    </div>
    <?php endif; ?>


    <div class="main-content-meta">
  		<p>Publicerad av: <?php print $name; ?>den <span> <?php print $date; ?></span></p>
  	</div>

  </div>
