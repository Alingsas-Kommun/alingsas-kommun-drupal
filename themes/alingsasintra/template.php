<?php

function alingsasintra_css_alter(&$css) {
  // Turn off some styles from the system module
  //unset($css[drupal_get_path('module', 'system') . '/system.messages.css']);
  unset($css[drupal_get_path('module', 'system') . '/system.menus.css']);
  //unset($css[drupal_get_path('module', 'system') . '/system.theme.css']);
}

function alingsasintra_username_alter(&$name, $account) {
  if (isset($account->uid)) {
    $this_user = user_load($account->uid);//loads the custom fields
    if((isset($this_user->field_firstname['und'][0]['value']) && isset($this_user->field_lastname['und'][0]['value']) && ($this_user->field_firstname['und'][0]['value'] || $this_user->field_lastname['und'][0]['value']))) {
      $name = $this_user->field_firstname['und'][0]['value'].' '.$this_user->field_lastname['und'][0]['value'];
    }
  }
}

function alingsasintra_theme($existing, $type, $theme, $path) {
  return array(
      'page_node_form' => array(
          'arguments' => array('form' => NULL),
          'template' => 'page-node-form',
          'render element' => 'form',
          'path' => drupal_get_path('theme', 'alingsasintra')."/templates",
      ),
      'news_node_form' => array(
          'arguments' => array('form' => NULL),
          'template' => 'news-node-form',
          'render element' => 'form',
          'path' => drupal_get_path('theme', 'alingsasintra')."/templates",
      ),
  );
}

function alingsasintra_preprocess_node(&$vars) {
  if($vars['view_mode'] == 'teaser') {
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__teaser';
  }
  if($vars['view_mode'] == 'search_result_teaser') {
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__searchresultteaser';
  }
}

function alingsasintra_preprocess_page(&$vars) {
  if( arg(1)
      && isset($vars['page']['#views_contextual_links_info']['views_ui'])
      && $vars['page']['#views_contextual_links_info']['views_ui']['view_name'] == 'nyheter'
      && $vars['page']['#views_contextual_links_info']['views_ui']['view_display_id'] == 'news_terms') {
    $term = taxonomy_term_load(arg(1));
    drupal_set_title('Visa alla nyheter från '.$term->name);
  }
}

function alingsasintra_preprocess_html(&$vars) {
  if(arg(1)) {
    $node = node_load(arg(1));
    if($node->type == 'notification') {
      $vars['classes_array'][] = 'notification-'.$node->field_notification_type['und'][0]['value'];
    }
  }
  if( arg(1)
      && $vars['theme_hook_suggestions'][0] == 'html__user'
      && $vars['user']->uid == arg(1)) {
    $vars['classes_array'][] = 'my-profile';
  }
}

function alingsasintra_image($variables) {
  $attributes = $variables['attributes'];
  $attributes['src'] = file_create_url($variables['path']);

  foreach (array('width', 'height', 'alt', 'title') as $key) {

    if (isset($variables[$key])) {
      $attributes[$key] = $variables[$key];
    }

    if($key == 'width' && $variables[$key]) {
      $attributes['style'] = 'max-width:' . $variables[$key] . 'px;';
    }
  }

  return '<img' . drupal_attributes($attributes) . ' /><em class="caption">' . (isset($variables['title']) ? $variables['title'] : '') . '</em>';
}

function alingsasintra_menu_local_tasks(&$variables) {
  $output = '';
  $secondary = '';
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] .= '<ul class="tabs secondary">';
    $variables['secondary']['#suffix'] = '</ul>';
    $secondary = drupal_render($variables['secondary']);
    for($i=1; isset($variables['primary'][$i]); $i++) {
      if(isset($variables['primary'][$i]['#active'])) {
        $variables['primary'][$i]['#suffix'] = $secondary;
        break;
      }
    }
  }
  if (!empty($variables['primary'])) {
    $output .= drupal_render($variables['primary']);
  }

  return $output;
}

?>
