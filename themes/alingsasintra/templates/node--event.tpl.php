<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

    <?php if(isset($content['field_date']) && $content['field_date']): ?>
    <p class="date">
      <?php print render($content['field_date']); ?>
    </p>
    <?php endif; ?>

    <?php if(isset($content['field_event_location']) && $content['field_event_location']): ?>
    <p class="location">
      Plats: <?php print $content['field_event_location']['#items'][0]['value']; ?>
    </p>
    <?php endif; ?>

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

  	<?php if(isset($content['field_event_related_information']) && $content['field_event_related_information']): ?>
  	<div class="m related-files">
  	  <div class="m-h">
      	<h2>Relaterad information</h2>
      </div>
      <div class="m-c">
      	<?php print render($content['field_event_related_information']); ?>
      </div>
    </div>
    <?php endif; ?>

  	<?php if(isset($content['booking_link']) && $content['booking_link']): ?>
    <div class="nix">
      <?php print render($content['booking_link']); ?>
    </div>
    <?php endif; ?>

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
  		<p>Publicerad av: <?php print $name; ?> senast uppdaterad <span> <?php print format_date($node->changed); ?></span></p>
  	</div>

  </div>

<?php if(isset($content['field_event_general_information']) && $content['field_event_general_information']): ?>
</div>
<div id="external-information" class="m related-info toggle">
	<div class="m-h">
    <h2>Allmän information</h2>
  </div>
  <div class="m-c">
      <?php print render($content['field_event_general_information']); ?>
  </div>
</div>
<div>
<?php endif; ?>
