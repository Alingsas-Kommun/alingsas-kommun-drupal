<?php
/**
 * @file
 * alingsasintra_notifications.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function alingsasintra_notifications_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'notifications';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Notifications';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Viktigt information';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Använda';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Återställ';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = 'important-message';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Fält: Innehåll: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Fält: Innehåll: Typ av anmälan */
  $handler->display->display_options['fields']['field_notification_type']['id'] = 'field_notification_type';
  $handler->display->display_options['fields']['field_notification_type']['table'] = 'field_data_field_notification_type';
  $handler->display->display_options['fields']['field_notification_type']['field'] = 'field_notification_type';
  $handler->display->display_options['fields']['field_notification_type']['label'] = '';
  $handler->display->display_options['fields']['field_notification_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_notification_type']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['field_notification_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_notification_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_notification_type']['hide_empty'] = TRUE;
  /* Sort criterion: Innehåll: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Innehåll: Publicerad */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Innehåll: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'notification' => 'notification',
  );
  /* Filter criterion: Innehåll: Visas på startsidan */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  /* Filter criterion: Innehåll: Typ av anmälan (field_notification_type) */
  $handler->display->display_options['filters']['field_notification_type_value']['id'] = 'field_notification_type_value';
  $handler->display->display_options['filters']['field_notification_type_value']['table'] = 'field_data_field_notification_type';
  $handler->display->display_options['filters']['field_notification_type_value']['field'] = 'field_notification_type_value';
  $handler->display->display_options['filters']['field_notification_type_value']['value'] = array(
    1 => '1',
  );

  /* Display: Viktigt medelande */
  $handler = $view->new_display('block', 'Viktigt medelande', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Vanligt information */
  $handler = $view->new_display('block', 'Vanligt information', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = 'info-message';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Innehåll: Publicerad */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Innehåll: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'notification' => 'notification',
  );
  /* Filter criterion: Innehåll: Visas på startsidan */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  /* Filter criterion: Innehåll: Typ av anmälan (field_notification_type) */
  $handler->display->display_options['filters']['field_notification_type_value']['id'] = 'field_notification_type_value';
  $handler->display->display_options['filters']['field_notification_type_value']['table'] = 'field_data_field_notification_type';
  $handler->display->display_options['filters']['field_notification_type_value']['field'] = 'field_notification_type_value';
  $handler->display->display_options['filters']['field_notification_type_value']['value'] = array(
    0 => '0',
  );
  $translatables['notifications'] = array(
    t('Master'),
    t('Viktigt information'),
    t('more'),
    t('Använda'),
    t('Återställ'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('[title]'),
    t('Viktigt medelande'),
    t('Vanligt information'),
  );
  $export['notifications'] = $view;

  return $export;
}
