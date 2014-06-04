<?php
/**
 * @file
 * alingsasintra_user_profile.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function alingsasintra_user_profile_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-personal-menu:all-content
  $menu_links['menu-personal-menu:all-content'] = array(
    'menu_name' => 'menu-personal-menu',
    'link_path' => 'all-content',
    'router_path' => 'all-content',
    'link_title' => 'Allt innehåll',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-personal-menu:mina-nyheter
  $menu_links['menu-personal-menu:mina-nyheter'] = array(
    'menu_name' => 'menu-personal-menu',
    'link_path' => 'mina-nyheter',
    'router_path' => 'mina-nyheter',
    'link_title' => 'Mina nyheter',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-personal-menu:my/content
  $menu_links['menu-personal-menu:my/content'] = array(
    'menu_name' => 'menu-personal-menu',
    'link_path' => 'my/content',
    'router_path' => 'my/content',
    'link_title' => 'Mitt skapade innehåll',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-personal-menu:user
  $menu_links['menu-personal-menu:user'] = array(
    'menu_name' => 'menu-personal-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'Min profil',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-personal-menu:user/edit-contact
  $menu_links['menu-personal-menu:user/edit-contact'] = array(
    'menu_name' => 'menu-personal-menu',
    'link_path' => 'user/edit-contact',
    'router_path' => 'user/edit-contact',
    'link_title' => 'Redigera kontaktinformation',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-personal-menu:user/edit-favorites
  $menu_links['menu-personal-menu:user/edit-favorites'] = array(
    'menu_name' => 'menu-personal-menu',
    'link_path' => 'user/edit-favorites',
    'router_path' => 'user/edit-favorites',
    'link_title' => 'Mina favoriter',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Allt innehåll');
  t('Min profil');
  t('Mina favoriter');
  t('Mina nyheter');
  t('Mitt skapade innehåll');
  t('Redigera kontaktinformation');


  return $menu_links;
}
