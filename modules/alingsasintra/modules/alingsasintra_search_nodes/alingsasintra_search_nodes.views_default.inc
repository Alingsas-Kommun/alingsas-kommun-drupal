<?php
/**
 * @file
 * alingsasintra_search_nodes.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function alingsasintra_search_nodes_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'search_nodes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_node_index';
  $view->human_name = 'Search nodes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sök innehåll';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Sök';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Återställ';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
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
  /* Fält: Sök: Relevance */
  $handler->display->display_options['fields']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['fields']['search_api_relevance']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['fields']['search_api_relevance']['label'] = '';
  $handler->display->display_options['fields']['search_api_relevance']['exclude'] = TRUE;
  $handler->display->display_options['fields']['search_api_relevance']['alter']['max_length'] = '5';
  $handler->display->display_options['fields']['search_api_relevance']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['search_api_relevance']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['search_api_relevance']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['search_api_relevance']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_relevance']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['search_api_relevance']['separator'] = '';
  $handler->display->display_options['fields']['search_api_relevance']['link_to_entity'] = 0;
  /* Fält: Indexed Nod: Innehållstyp */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Fält: Indexed Nod: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Fält: Indexed Nod: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Fält: Indexed Nod: Författare */
  $handler->display->display_options['fields']['author']['id'] = 'author';
  $handler->display->display_options['fields']['author']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['author']['field'] = 'author';
  $handler->display->display_options['fields']['author']['label'] = '';
  $handler->display->display_options['fields']['author']['exclude'] = TRUE;
  $handler->display->display_options['fields']['author']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['author']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['author']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['author']['view_mode'] = 'full';
  /* Fält: Indexed Nod: Datum för skapande */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = '<h3>[title]</h3>    
          <p>[body]</p>    
          <p class="news-meta">
        <span class="date">[created]</span>
        <span class="type">Typ: [type]</span>
        <span class="author">Författare: [author]</span>
        <span class="relevance">Relevans: [search_api_relevance]</span>
       </p>';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'kort_utom_tid';
  $handler->display->display_options['fields']['created']['link_to_entity'] = 0;
  /* Filter criterion: Indexed Nod: Innehållstyp */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'advert' => 'advert',
    'event' => 'event',
    'notification' => 'notification',
    'alingsas_job' => 'alingsas_job',
    'news' => 'news',
    'page' => 'page',
    'verktyg' => 'verktyg',
  );
  /* Filter criterion: Sök: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Sök';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );

  /* Display: Page: Search nodes */
  $handler = $view->new_display('page', 'Page: Search nodes', 'search_nodes');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'sok';
  $translatables['search_nodes'] = array(
    t('Master'),
    t('Sök innehåll'),
    t('more'),
    t('Sök'),
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
    t('.'),
    t('<h3>[title]</h3>    
          <p>[body]</p>    
          <p class="news-meta">
        <span class="date">[created]</span>
        <span class="type">Typ: [type]</span>
        <span class="author">Författare: [author]</span>
        <span class="relevance">Relevans: [search_api_relevance]</span>
       </p>'),
    t('Page: Search nodes'),
  );
  $export['search_nodes'] = $view;

  $view = new view();
  $view->name = 'search_users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_user_index';
  $view->human_name = 'Search users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sök person';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Sök';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Återställ';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
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
  /* Sidhuvud: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Visar @start-@end av @total';
  /* Fält: Indexed Användare: Användar-ID */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'search_api_index_user_index';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_entity'] = 0;
  /* Fält: Indexed Användare: Efternamn */
  $handler->display->display_options['fields']['field_lastname']['id'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['table'] = 'search_api_index_user_index';
  $handler->display->display_options['fields']['field_lastname']['field'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['label'] = '';
  $handler->display->display_options['fields']['field_lastname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lastname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lastname']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_lastname']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_lastname']['type'] = 'text_plain';
  /* Fält: Indexed Användare: Email */
  $handler->display->display_options['fields']['field_user_email']['id'] = 'field_user_email';
  $handler->display->display_options['fields']['field_user_email']['table'] = 'search_api_index_user_index';
  $handler->display->display_options['fields']['field_user_email']['field'] = 'field_user_email';
  $handler->display->display_options['fields']['field_user_email']['label'] = '';
  $handler->display->display_options['fields']['field_user_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_email']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_email']['alter']['text'] = '<p><span class="user_label">E-post: </span><a href="mailto:[field_user_email-value]">[field_user_email-value]</a></p>';
  $handler->display->display_options['fields']['field_user_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_email']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_email']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_user_email']['type'] = 'text_plain';
  /* Fält: Indexed Användare: Enhet */
  $handler->display->display_options['fields']['field_ou']['id'] = 'field_ou';
  $handler->display->display_options['fields']['field_ou']['table'] = 'search_api_index_user_index';
  $handler->display->display_options['fields']['field_ou']['field'] = 'field_ou';
  $handler->display->display_options['fields']['field_ou']['label'] = '';
  $handler->display->display_options['fields']['field_ou']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ou']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_ou']['alter']['text'] = 'Enhet: [field_ou-value]';
  $handler->display->display_options['fields']['field_ou']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ou']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_ou']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_ou']['type'] = 'text_plain';
  /* Fält: Indexed Användare: Förnamn */
  $handler->display->display_options['fields']['field_firstname']['id'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['table'] = 'search_api_index_user_index';
  $handler->display->display_options['fields']['field_firstname']['field'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['label'] = '';
  $handler->display->display_options['fields']['field_firstname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_firstname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_firstname']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_firstname']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_firstname']['type'] = 'text_plain';
  /* Fält: Indexed Användare: Mobil */
  $handler->display->display_options['fields']['field_user_mobile']['id'] = 'field_user_mobile';
  $handler->display->display_options['fields']['field_user_mobile']['table'] = 'search_api_index_user_index';
  $handler->display->display_options['fields']['field_user_mobile']['field'] = 'field_user_mobile';
  $handler->display->display_options['fields']['field_user_mobile']['label'] = '';
  $handler->display->display_options['fields']['field_user_mobile']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_mobile']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_mobile']['alter']['text'] = '<p><span class="user_label">Mobil: </span> [field_user_mobile]</p>';
  $handler->display->display_options['fields']['field_user_mobile']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_mobile']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_mobile']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_user_mobile']['type'] = 'text_plain';
  /* Fält: Indexed Användare: Telefon */
  $handler->display->display_options['fields']['field_user_phone']['id'] = 'field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['table'] = 'search_api_index_user_index';
  $handler->display->display_options['fields']['field_user_phone']['field'] = 'field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['label'] = '';
  $handler->display->display_options['fields']['field_user_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_phone']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_phone']['alter']['text'] = '<p><span class="user_label">Telefon: </span> [field_user_phone]</p>';
  $handler->display->display_options['fields']['field_user_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_phone']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_user_phone']['type'] = 'text_plain';
  /* Fält: Indexed Användare: Namn */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'search_api_index_user_index';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '([name])';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_entity'] = 0;
  /* Fält: Indexed Användare: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_user_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['text'] = '				<h3><a href="[url]">[field_firstname] [field_lastname] [name]</a></h3>
				[field_user_email]
				[field_user_phone]
				[field_user_mobile]
<p>Status: <span class="user-status" id="user-[uid]">ingen status information</span></p>
				<div class="news-meta">
					<ul class="news-group">
						<li>[field_ou]</li>
					</ul>
				</div>';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Fält: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_firstname][field_lastname]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Sök: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_user_index';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  /* Filter criterion: Sök: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_user_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Sök';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'name' => 'name',
    'field_firstname' => 'field_firstname',
    'field_lastname' => 'field_lastname',
    'field_ou' => 'field_ou',
    'field_user_title' => 'field_user_title',
    'field_user_email' => 'field_user_email',
    'field_user_phone' => 'field_user_phone',
    'field_user_mobile' => 'field_user_mobile',
    'field_user_fax' => 'field_user_fax',
    'field_user_address' => 'field_user_address',
  );

  /* Display: Sök person */
  $handler = $view->new_display('page', 'Sök person', 'search_user_list');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'sok-anvandare';
  $translatables['search_users'] = array(
    t('Master'),
    t('Sök person'),
    t('more'),
    t('Sök'),
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
    t('.'),
    t(','),
    t('<p><span class="user_label">E-post: </span><a href="mailto:[field_user_email-value]">[field_user_email-value]</a></p>'),
    t('Enhet: [field_ou-value]'),
    t('<p><span class="user_label">Mobil: </span> [field_user_mobile]</p>'),
    t('<p><span class="user_label">Telefon: </span> [field_user_phone]</p>'),
    t('([name])'),
    t('				<h3><a href="[url]">[field_firstname] [field_lastname] [name]</a></h3>
				[field_user_email]
				[field_user_phone]
				[field_user_mobile]
<p>Status: <span class="user-status" id="user-[uid]">ingen status information</span></p>
				<div class="news-meta">
					<ul class="news-group">
						<li>[field_ou]</li>
					</ul>
				</div>'),
    t('[field_firstname][field_lastname]'),
  );
  $export['search_users'] = $view;

  return $export;
}
