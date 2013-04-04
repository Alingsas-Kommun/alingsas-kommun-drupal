  <ul>
    <?php foreach ($items as $delta => $item): ?>
      <li><a href="<?php print(file_create_url($item['#file']->uri)); ?>"><?php print (($item['#file']->description) ? $item['#file']->description : $item['#file']->filename); ?></a></li>
    <?php endforeach; ?>
  </ul>
