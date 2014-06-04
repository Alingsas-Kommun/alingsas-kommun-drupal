<?php if(!$logged_in): ?>

<header id="header" role="banner">

	<div id="skip">
		<a href="#section-content">Hoppa till innehåll</a>
	</div>

	<div class="cf header-first">
		<div class="container-12">
		  &nbsp;
		</div>
	</div>
	<div class="cf header-second">
		<div class="container-12">
			<div id="logo" class="grid-4">
				<a href="/"><img src="/sites/all/themes/alingsasintra/gui/i/logo.png" alt="Logo"></a>
			</div>
		</div>
	</div>
</header>

<section id="section-content">

		<div id="zone-content" class="clearfix container-12">

			  <?php if($page['content']):?>
          <?php print render($page['content']); ?>
        <?php endif; ?>

    </div>

</section>

<footer id="footer" class="cf" role="contentinfo">
	<div class="footer-wrap">
		<div class="container-12">&nbsp;</div>
	</div>
</footer>


<?php else: ?>

<header id="header" role="banner">

	<div id="skip">
		<a href="#section-content">Hoppa till innehåll</a>
	</div>

	<div class="header-wrap">
		<div class="cf header">
			<div class="container-12">
				<div id="logo" class="grid-3">
				  <a href="/"><img src="/sites/all/themes/alingsasintra/gui/i/logo.png" alt="Logo"></a>
				</div>
				<div class="grid-6">
				  <?php if($page['header_first']):?>
            <?php print render($page['header_first']); ?>
          <?php endif; ?>
				</div>
				<div class="grid-3">
					<div id="function-modules" class="cf">
						<div class="m calendar month">
							<div class="m-h cf">
								<span><?php print date('M'); ?></span>
							</div>
							<div class="m-c cf">
								<span><?php print date('j'); ?></span>
							</div>
						</div>
						<div class="m calendar time">
							<div class="m-h cf">
								<span>Kl</span>
							</div>
							<div class="m-c cf">
								<span><?php print date('H.i')?></span>
							</div>
						</div>
						<div class="m calendar week">
							<div class="m-h cf">
								<span>Vecka</span>
							</div>
							<div class="m-c cf">
								<span><?php print date('W')?></span>
							</div>
						</div>
					</div>
				</div>
			</div>
		</div>
		<div class="cf header-nav">
			<div class="container-12">
				<div class="nav-main cf" role="navigation">
  				<h2 class="structural">Huvudnavigering</h2>
  				<?php if($logged_in):?>
  				  <?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('links', 'inline', 'clearfix')))); ?>
  				<?php endif; ?>
			  </div>
			</div>
		</div>
	</div>
</header>

<section id="section-content">

		<div id="zone-content" class="clearfix container-12">

      <?php if($is_front):?>
      <div class="grid-9">
      <?php if($page['notification_area'] || $messages):?>
        <?php print render($page['notification_area']); ?>
        <?php print $messages; ?>
      <?php endif; ?>
        <div class="region-content">

  			  <?php if($page['content']):?>
            <?php print render($page['content']); ?>
          <?php endif; ?>
        </div>
        <div class="region-sidebar-second">
          <?php if($page['sidebar_second']):?>
            <?php print render($page['sidebar_second']); ?>
          <?php endif; ?>
        </div>
      </div>
      <?php else: ?>

        <div class="region-content grid-9">

        <?php if($messages):?>
            <?php print $messages; ?>
          <?php endif; ?>

        <div class="main-content cf">

          <?php print render($title_prefix); ?>
            <h1 class="title" id="page-title"><?php print $title; ?></h1>
          <?php print render($title_suffix); ?>

          <?php if($page['content']):?>
            <?php print render($page['content']); ?>
          <?php endif; ?>

          </div>

          </div>
      <?php endif; ?>

        <div class="grid-3 region-sidebar-third" role="complementary">
  				<?php if($page['sidebar_third']): ?>
            <?php print render($page['sidebar_third']); ?>
          <?php endif; ?>
        </div>

		</div>

</section>

<footer id="footer" class="cf" role="contentinfo">
	<div class="container-12 footer-wrap">
		<div class="function-nav">
			<ul>
				<li>
					<a href="/">Alingsås.se</a>
				</li>
				<li>
					<a href="/">Tillgänglighet</a>
				</li>
				<li>
					<a href="/">Webbkarta</a>
				</li>
				<li>
					<a href="/">A till Ö</a>
				</li>
			</ul>
		</div>
	</div>
</footer>

<?php endif; ?>
