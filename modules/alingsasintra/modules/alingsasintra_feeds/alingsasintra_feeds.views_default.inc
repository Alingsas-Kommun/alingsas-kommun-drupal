<?php
/**
 * @file
 * alingsasintra_feeds.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function alingsasintra_feeds_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'jobb';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'jobb';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Jobb';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Använda';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Återställ';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« första';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ föregående';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nästa ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sista »';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'cf';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Fält: Innehåll: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Innehåll: Publiceringsdatum -  start date (field_jf_publishdate) */
  $handler->display->display_options['sorts']['field_jf_publishdate_value']['id'] = 'field_jf_publishdate_value';
  $handler->display->display_options['sorts']['field_jf_publishdate_value']['table'] = 'field_data_field_jf_publishdate';
  $handler->display->display_options['sorts']['field_jf_publishdate_value']['field'] = 'field_jf_publishdate_value';
  $handler->display->display_options['sorts']['field_jf_publishdate_value']['order'] = 'DESC';
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
    'alingsas_job' => 'alingsas_job',
  );
  /* Filter criterion: Innehåll: Publiceringsdatum - end date (field_jf_publishdate:value2) */
  $handler->display->display_options['filters']['field_jf_publishdate_value2']['id'] = 'field_jf_publishdate_value2';
  $handler->display->display_options['filters']['field_jf_publishdate_value2']['table'] = 'field_data_field_jf_publishdate';
  $handler->display->display_options['filters']['field_jf_publishdate_value2']['field'] = 'field_jf_publishdate_value2';
  $handler->display->display_options['filters']['field_jf_publishdate_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_jf_publishdate_value2']['granularity'] = 'second';
  $handler->display->display_options['filters']['field_jf_publishdate_value2']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_jf_publishdate_value2']['default_date'] = 'now';

  /* Display: index */
  $handler = $view->new_display('page', 'index', 'index');
  $handler->display->display_options['path'] = 'jobb';
  $translatables['jobb'] = array(
    t('Master'),
    t('Jobb'),
    t('more'),
    t('Använda'),
    t('Återställ'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« första'),
    t('‹ föregående'),
    t('nästa ›'),
    t('sista »'),
    t('index'),
  );
  $export['jobb'] = $view;

  return $export;
}
