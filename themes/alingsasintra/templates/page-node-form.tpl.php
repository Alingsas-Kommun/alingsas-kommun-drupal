<div class="row cols-1 cf">
  <?php print drupal_render($form['title']); ?>
</div>

<div class="row cols-1 cf">
  <?php print drupal_render($form['field_introduction']); ?>
</div>

<div class="row cols-1 cf">
  <?php print drupal_render($form['field_image']); ?>
</div>

<div class="row cols-1 cf">
  <?php print drupal_render($form['body']); ?>
</div>



  <?php print drupal_render_children($form); ?>
