<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

    <?php print render($content['body']); ?>






 <?php if($field_jf_qualifications || $field_jf_experience): ?>
<h2>Kvalifikationer</h2>
<div class="textblock">
  <?php if($content['field_jf_qualifications']): ?>
    <?php print nl2br(render($content['field_jf_qualifications'])); ?>
  <?php endif; ?>
  <?php if($field_jf_experience): ?>
    <?php print render($content['field_jf_experience']); ?>
  <?php endif; ?>
  <?php if($field_jf_experience_desc): ?>
    <?php print nl2br(render($content['field_jf_experience_desc'])); ?>
  <?php endif; ?>
</div>
<?php endif; ?>

<?php if($field_jf_employmenttype_nam || $field_jf_employmenttype_des || $field_jf_employmentgrade_na || $field_jf_employmentgrade_de || $field_jf_employmentstartdate): ?>
  <h2>Anställningens omfattning</h2>
<div class="textblock">
  <?php if($field_jf_employmenttype_nam): ?>
    <?php print render($content['field_jf_employmenttype_nam']); ?>
  <?php endif; ?>
  <?php if($field_jf_employmenttype_des): ?>
    <?php print nl2br(render($content['field_jf_employmenttype_des'])); ?>
  <?php endif; ?>
  <?php if($field_jf_employmentgrade_na): ?>
    <?php print render($content['field_jf_employmentgrade_na']); ?>
  <?php endif; ?>
  <?php if($field_jf_employmentgrade_de): ?>
    <?php print nl2br(render($content['field_jf_employmentgrade_de'])); ?>
  <?php endif; ?>
  <?php if($field_jf_numberofjobs): ?>
     <?php print render($content['field_jf_numberofjobs']); ?>
  <?php endif; ?>
  <?php if($field_jf_workshift): ?>
    <?php print render($content['field_jf_workshift']); ?>
  <?php endif; ?>
  <?php if($field_jf_workshift_desc): ?>
    <?php print nl2br(render($content['field_jf_workshift_desc'])); ?>
  <?php endif; ?>

  <?php if($field_jf_employmentstartdate && strpos($content['field_jf_employmentstartdate']['#items'][0]['value'], '1753') === FALSE): ?>
    <?php print render($content['field_jf_employmentstartdate']); ?>
  <?php endif; ?>
  <?php if($field_jf_employmentenddate && strpos($content['field_jf_employmentenddate']['#items'][0]['value'], '1753') === FALSE): ?>
    <?php print render($content['field_jf_employmentenddate']); ?>
  <?php endif; ?>

</div>
<?php endif; ?>

<?php if($field_jf_applicationenddate || $field_jf_referensnummer || $field_applicationmethods): ?>
  <h2>Ansökning</h2>
<div class="textblock">
  <?php if($field_jf_applicationenddate && $content['field_jf_applicationenddate']['#items'][0]['value'] != '1753-01-01T00:00:00'): ?>
     <?php print render($content['field_jf_applicationenddate']); ?>
  <?php endif; ?>
  <?php if($field_jf_referencenumber): ?>
    <?php print render($content['field_jf_referencenumber']); ?>
  <?php endif; ?>
  <?php if($field_jf_applicationmethods): ?>
    <?php print render($content['field_jf_applicationmethods']); ?>
  <?php endif; ?>
</div>
<?php endif; ?>

<?php if($field_jf_salarytype): ?>
<h2>Lön</h2>
<div class="textblock">
  <?php if($field_jf_salarytype): ?>
    <?php print render($content['field_jf_salarytype']); ?>
  <?php endif; ?>
  <?php if($field_jf_salarytype_desc): ?>
    <?php print nl2br(render($content['field_jf_salarytype_desc'])); ?>
  <?php endif; ?>
 </div>
<?php endif; ?>

<?php if($field_jf_contact1_name || $field_jf_contact2_name): ?>
<h2>Kontakt</h2>
<div class="textblock">
  <?php if($field_jf_contact1_name): ?>

      <strong><?php print render($content['field_jf_contact1_name']); ?></strong>
    <?php if($field_jf_contact1_title): ?>
      <?php print render($content['field_jf_contact1_title']); ?>
    <?php endif; ?>
    <?php if($field_jf_contact1_phone): ?>
      <?php print render($content['field_jf_contact1_phone']); ?>
    <?php endif; ?>
    <?php if($field_jf_contact1_email): ?>
      <a href="mailto:<?php print $field_jf_contact1_email[0]['safe_value']; ?>"><?php print $field_jf_contact1_email[0]['safe_value']; ?></a>
    <?php endif; ?>

  <?php endif; ?>

  <?php if($field_jf_contact2_name): ?>

      <strong><?php print render($content['field_jf_contact2_name']); ?></strong>
    <?php if($field_jf_contact2_title): ?>
      <?php print render($content['field_jf_contact2_title']); ?>
    <?php endif; ?>
    <?php if($field_jf_contact2_phone): ?>
      <?php print render($content['field_jf_contact2_phone']); ?>
    <?php endif; ?>
    <?php if($field_jf_contact2_email): ?>
      <a href="mailto:<?php print $field_jf_contact2_email[0]['safe_value']; ?>"><?php print $field_jf_contact2_email[0]['safe_value']; ?></a>
    <?php endif; ?>

  <?php endif; ?>
</div>
<?php endif; ?>





<?php if($field_jf_additionalinfo): ?>
<h2>Övrigt</h2>
<div class="textblock">
<?php print nl2br(render($content['field_jf_additionalinfo'])); ?>
</div>
<?php endif; ?>

<?php if($field_jf_department): ?>
<h2>Arbetsgivare</h2>
<div class="textblock">
Alingsås kommun, <?php print $content['field_jf_department']['#items'][0]['value']; ?>
</div>
<?php endif; ?>

<?php if($field_jf_departmentdescr): ?>
<h2>Arbetsplatsbeskrivning</h2>
<div class="textblock">
<?php print nl2br(render($content['field_jf_departmentdescr'])); ?>
</div>
<?php endif; ?>




&nbsp;








    <div class="main-content-meta">
    <?php if(isset($content['field_contact_user']['#items'][0]['entity']) || isset($content['field_contact_name'])): ?>
    <p><strong>Kontakt:</strong>
  	  <?php if(isset($content['field_contact_user']['#items'][0]['entity'])): ?>
      <a href="/user/<?php print $content['field_contact_user']['#items'][0]['entity']->uid; ?>"><?php print $content['field_contact_user']['#items'][0]['entity']->field_firstname['und']; ?> <?php print $content['field_contact_user']['#items'][0]['entity']->field_lastname['und']; ?></a>
        <?php if(isset($content['field_contact_user']['#items'][0]['entity']->field_user_email['und'])) : ?>
        <a href="mailto:<?php print $content['field_contact_user']['#items'][0]['entity']->field_user_email['und']; ?>"><?php print $content['field_contact_user']['#items'][0]['entity']->field_user_email['und']; ?></a>
        <?php endif; ?>
      <?php elseif(isset($content['field_contact_name']) && $content['field_contact_name']):?>
         <?php print $content['field_contact_name']['#items']; ?> <a href="mailto:<?php print $content['field_contact_email']['#items']; ?>"><?php print $content['field_contact_email']['#items']?></a>
      <?php endif; ?>

      </p>
    <?php endif; ?>
  		<p>Publicerad av: <?php print $name; ?>den <span> <?php print $date; ?></span></p>
  	</div>

</div>

<?php if($content['comments']):?>
</div>
<div id="showcomments" class="m comments toggle">
    <div class="m-h open">
    	<h2>Kommentarer <span>(<?php print $comment_count; ?>)</span></h2>
    </div>
    <div class="m-c">
    <?php print print render($content['comments']); ?>
    </div>
</div>
<div>
<?php endif; ?>
