<!DOCTYPE html>
<html lang="sv" class="no-js">
<head>
	<meta charset="utf-8" />

	<title><?php print $head_title; ?></title>

	<script>
		// Switch classes for JavaScript detection
		document.documentElement.className = document.documentElement.className.replace(/(\s|^)no-js(\s|$)/, '$1js$2');
	</script>

	<meta name="viewport" content="width=device-width,initial-scale=1.0" />

	<link rel="shortcut icon" href="/sites/all/themes/alingsasintra/gui/i/favicon.ico" type="image/ico" />
	<link rel="alternate" type="application/rss+xml" title="Alingsås" href="/feed.xml" />

	<?php print $styles; ?>

	<!--[if IE 9]>
    <link rel="stylesheet" href="/sites/all/themes/alingsasintra/gui/css/ie9.css?1" />
    <![endif]-->

	<!--[if lt IE 9]>
		<link rel="stylesheet" href="/sites/all/themes/alingsasintra/gui/css/ie.css?1" />
	<![endif]-->

	<?php print $scripts; ?>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>
</html>
