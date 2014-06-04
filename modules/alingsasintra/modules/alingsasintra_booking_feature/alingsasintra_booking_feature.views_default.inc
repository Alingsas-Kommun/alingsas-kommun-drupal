<?php
/**
 * @file
 * alingsasintra_booking_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function alingsasintra_booking_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'alingsasintra_events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_event_index';
  $view->human_name = 'Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Aktiviteter och kurser';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Använda';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Återställ';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« första';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ föregående';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nästa ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sista »';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'cf';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Sidhuvud: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Visar @start-@end av @total';
  /* Fält: Innehåll: Rendered Nod */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'teaser';
  /* Sort criterion: Datum och tid: Start date (indexed) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'search_api_index_event_index';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['expose']['label'] = 'Start date (indexed)';
  /* Filter criterion: Indexed Nod: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_event_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Datum och tid: Start date (indexed) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'search_api_index_event_index';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_value']['value'] = 'now';
  /* Filter criterion: Nyhetsflöde: Namn (indexed) */
  $handler->display->display_options['filters']['field_organizational_structure_name']['id'] = 'field_organizational_structure_name';
  $handler->display->display_options['filters']['field_organizational_structure_name']['table'] = 'search_api_index_event_index';
  $handler->display->display_options['filters']['field_organizational_structure_name']['field'] = 'field_organizational_structure_name';
  $handler->display->display_options['filters']['field_organizational_structure_name']['operator'] = 'empty';

  /* Display: Events common */
  $handler = $view->new_display('page', 'Events common', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Gemensamma aktiviteter och kurser';
  $handler->display->display_options['path'] = 'events';

  /* Display: Events by organization */
  $handler = $view->new_display('page', 'Events by organization', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Förvaltningens aktiviteter och kurser';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Nod: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_event_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Datum och tid: Start date (indexed) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'search_api_index_event_index';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_value']['value'] = 'now';
  /* Filter criterion: Nyhetsflöde: Namn (indexed) */
  $handler->display->display_options['filters']['field_organizational_structure_name']['id'] = 'field_organizational_structure_name';
  $handler->display->display_options['filters']['field_organizational_structure_name']['table'] = 'search_api_index_event_index';
  $handler->display->display_options['filters']['field_organizational_structure_name']['field'] = 'field_organizational_structure_name';
  $handler->display->display_options['filters']['field_organizational_structure_name']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'events-by-organization';
  $translatables['alingsasintra_events'] = array(
    t('Master'),
    t('Aktiviteter och kurser'),
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
    t('Visar @start-@end av @total'),
    t('Start date (indexed)'),
    t('Events common'),
    t('Gemensamma aktiviteter och kurser'),
    t('Events by organization'),
    t('Förvaltningens aktiviteter och kurser'),
  );
  $export['alingsasintra_events'] = $view;

  return $export;
}
