  <ul>
    <?php foreach ($items as $delta => $item): ?>
      <li><?php print(render($item)); ?></li>
    <?php endforeach; ?>
  </ul>
