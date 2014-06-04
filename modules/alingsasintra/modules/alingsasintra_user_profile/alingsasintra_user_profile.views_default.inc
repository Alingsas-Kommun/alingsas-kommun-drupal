<?php
/**
 * @file
 * alingsasintra_user_profile.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function alingsasintra_user_profile_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'entity_reference_user';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Entity reference user';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Använda';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Återställ';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« första';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ föregående';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nästa ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sista »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Fält: Användare: Namn */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Fält: Användare: Förnamn */
  $handler->display->display_options['fields']['field_firstname']['id'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['table'] = 'field_data_field_firstname';
  $handler->display->display_options['fields']['field_firstname']['field'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['label'] = '';
  $handler->display->display_options['fields']['field_firstname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_firstname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_firstname']['element_default_classes'] = FALSE;
  /* Fält: Användare: Email */
  $handler->display->display_options['fields']['field_user_email']['id'] = 'field_user_email';
  $handler->display->display_options['fields']['field_user_email']['table'] = 'field_data_field_user_email';
  $handler->display->display_options['fields']['field_user_email']['field'] = 'field_user_email';
  $handler->display->display_options['fields']['field_user_email']['label'] = '';
  $handler->display->display_options['fields']['field_user_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_email']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_email']['empty'] = 'ingen email-adress';
  /* Fält: Användare: Enhet */
  $handler->display->display_options['fields']['field_ou']['id'] = 'field_ou';
  $handler->display->display_options['fields']['field_ou']['table'] = 'field_data_field_ou';
  $handler->display->display_options['fields']['field_ou']['field'] = 'field_ou';
  $handler->display->display_options['fields']['field_ou']['label'] = '';
  $handler->display->display_options['fields']['field_ou']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ou']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ou']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_ou']['empty'] = 'ingen enhet angiven';
  $handler->display->display_options['fields']['field_ou']['hide_alter_empty'] = FALSE;
  /* Fält: Användare: Efternamn */
  $handler->display->display_options['fields']['field_lastname']['id'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['fields']['field_lastname']['field'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['label'] = '';
  $handler->display->display_options['fields']['field_lastname']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_lastname']['alter']['text'] = '[field_firstname] [field_lastname] ([field_ou], [field_user_email]) ';
  $handler->display->display_options['fields']['field_lastname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lastname']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_lastname']['empty'] = '[name] ([field_ou], [field_user_email]) ';
  $handler->display->display_options['fields']['field_lastname']['hide_alter_empty'] = FALSE;
  /* Filter criterion: Användare: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Entity Reference Users */
  $handler = $view->new_display('entityreference', 'Entity Reference Users', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_firstname' => 'field_firstname',
    'field_user_email' => 'field_user_email',
    'field_lastname' => 'field_lastname',
    'name' => 0,
    'field_ou' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['entity_reference_user'] = array(
    t('Master'),
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
    t('ingen email-adress'),
    t('ingen enhet angiven'),
    t('[field_firstname] [field_lastname] ([field_ou], [field_user_email]) '),
    t('[name] ([field_ou], [field_user_email]) '),
    t('Entity Reference Users'),
  );
  $export['entity_reference_user'] = $view;

  return $export;
}
