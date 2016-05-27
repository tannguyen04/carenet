<?php
/**
 * @file
 * carenet_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function carenet_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'card_rate';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Card rate';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage Providers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  /* Field: Global: Fieldset */
  $handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['label'] = 'Line items';
  $handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'field_card_rate_item',
  );
  $handler->display->display_options['fields']['fieldset']['fieldset']['collapsible'] = 1;
  $handler->display->display_options['fields']['fieldset']['fieldset']['collapsed'] = 1;
  /* Field: Content: Line item */
  $handler->display->display_options['fields']['field_card_rate_item']['id'] = 'field_card_rate_item';
  $handler->display->display_options['fields']['field_card_rate_item']['table'] = 'field_data_field_card_rate_item';
  $handler->display->display_options['fields']['field_card_rate_item']['field'] = 'field_card_rate_item';
  $handler->display->display_options['fields']['field_card_rate_item']['label'] = 'Items';
  $handler->display->display_options['fields']['field_card_rate_item']['type'] = 'field_collection_table_view';
  $handler->display->display_options['fields']['field_card_rate_item']['settings'] = array(
    'edit' => 'Edit',
    'delete' => 'Delete',
    'add' => 'Add',
    'description' => 1,
    'view_mode' => 'full',
    'empty' => 1,
    'cssrowcol' => 0,
    'cssfield' => 0,
  );
  $handler->display->display_options['fields']['field_card_rate_item']['delta_offset'] = '0';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  $handler->display->display_options['fields']['delete_node']['text'] = 'Delete';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'card_rate' => 'card_rate',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Manage Card Rate';
  $handler->display->display_options['path'] = 'admin/carenet-manage/card-rate';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Manage Card Rate';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  $handler->display->display_options['fields']['delete_node']['text'] = 'Delete';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'provider' => 'provider',
  );
  $handler->display->display_options['path'] = 'admin/carenet-manage/provider';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Manage Providers';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['card_rate'] = $view;

  $view = new view();
  $view->name = 'get_city_by_state';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_node_index';
  $view->human_name = 'Get city by state';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Get city by state';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_json';
  /* Field: Indexed Node: City */
  $handler->display->display_options['fields']['field_pv_city']['id'] = 'field_pv_city';
  $handler->display->display_options['fields']['field_pv_city']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_city']['field'] = 'field_pv_city';
  $handler->display->display_options['fields']['field_pv_city']['label'] = 'city';
  $handler->display->display_options['fields']['field_pv_city']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_pv_city']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_pv_city']['bypass_access'] = 0;
  /* Field: Indexed Node: City */
  $handler->display->display_options['fields']['field_pv_city_1']['id'] = 'field_pv_city_1';
  $handler->display->display_options['fields']['field_pv_city_1']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_city_1']['field'] = 'field_pv_city';
  $handler->display->display_options['fields']['field_pv_city_1']['label'] = 'tid';
  $handler->display->display_options['fields']['field_pv_city_1']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_pv_city_1']['display'] = 'id';
  $handler->display->display_options['fields']['field_pv_city_1']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_pv_city_1']['bypass_access'] = 0;
  /* Filter criterion: Indexed Node: State */
  $handler->display->display_options['filters']['field_pv_state']['id'] = 'field_pv_state';
  $handler->display->display_options['filters']['field_pv_state']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['filters']['field_pv_state']['field'] = 'field_pv_state';
  $handler->display->display_options['filters']['field_pv_state']['value'] = array();
  $handler->display->display_options['filters']['field_pv_state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pv_state']['expose']['operator_id'] = 'field_pv_state_op';
  $handler->display->display_options['filters']['field_pv_state']['expose']['label'] = 'state';
  $handler->display->display_options['filters']['field_pv_state']['expose']['operator'] = 'field_pv_state_op';
  $handler->display->display_options['filters']['field_pv_state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['field_pv_state']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_pv_state']['expose']['reduce'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'get-city-by-state';
  $export['get_city_by_state'] = $view;

  $view = new view();
  $view->name = 'get_county_by_city';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_node_index';
  $view->human_name = 'Get county by city';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Get county by city';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_json';
  /* Field: Indexed Node: County */
  $handler->display->display_options['fields']['field_pv_county']['id'] = 'field_pv_county';
  $handler->display->display_options['fields']['field_pv_county']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_county']['field'] = 'field_pv_county';
  $handler->display->display_options['fields']['field_pv_county']['label'] = 'county';
  $handler->display->display_options['fields']['field_pv_county']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_pv_county']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_pv_county']['bypass_access'] = 0;
  /* Field: Indexed Node: County */
  $handler->display->display_options['fields']['field_pv_county_1']['id'] = 'field_pv_county_1';
  $handler->display->display_options['fields']['field_pv_county_1']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_county_1']['field'] = 'field_pv_county';
  $handler->display->display_options['fields']['field_pv_county_1']['label'] = 'tid';
  $handler->display->display_options['fields']['field_pv_county_1']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_pv_county_1']['display'] = 'id';
  $handler->display->display_options['fields']['field_pv_county_1']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_pv_county_1']['bypass_access'] = 0;
  /* Filter criterion: Indexed Node: City */
  $handler->display->display_options['filters']['field_pv_city']['id'] = 'field_pv_city';
  $handler->display->display_options['filters']['field_pv_city']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['filters']['field_pv_city']['field'] = 'field_pv_city';
  $handler->display->display_options['filters']['field_pv_city']['value'] = array();
  $handler->display->display_options['filters']['field_pv_city']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pv_city']['expose']['operator_id'] = 'field_pv_city_op';
  $handler->display->display_options['filters']['field_pv_city']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['field_pv_city']['expose']['operator'] = 'field_pv_city_op';
  $handler->display->display_options['filters']['field_pv_city']['expose']['identifier'] = 'city';
  $handler->display->display_options['filters']['field_pv_city']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_pv_city']['expose']['reduce'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'get-county-by-city';
  $export['get_county_by_city'] = $view;

  $view = new view();
  $view->name = 'list_provider_by_telephone';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_node_index';
  $view->human_name = 'List Provider By Telephone';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'List Provider By Telephone';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_json';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Node: Provider Organization Name */
  $handler->display->display_options['fields']['field_pv_og_name']['id'] = 'field_pv_og_name';
  $handler->display->display_options['fields']['field_pv_og_name']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_og_name']['field'] = 'field_pv_og_name';
  $handler->display->display_options['fields']['field_pv_og_name']['label'] = 'name';
  /* Field: Indexed Node: NPI */
  $handler->display->display_options['fields']['field_pv_npi']['id'] = 'field_pv_npi';
  $handler->display->display_options['fields']['field_pv_npi']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_npi']['field'] = 'field_pv_npi';
  $handler->display->display_options['fields']['field_pv_npi']['label'] = 'npi';
  /* Field: Indexed Node: State */
  $handler->display->display_options['fields']['field_pv_state']['id'] = 'field_pv_state';
  $handler->display->display_options['fields']['field_pv_state']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_state']['field'] = 'field_pv_state';
  $handler->display->display_options['fields']['field_pv_state']['label'] = 'state';
  $handler->display->display_options['fields']['field_pv_state']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_pv_state']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_pv_state']['bypass_access'] = 0;
  /* Field: Indexed Node: City */
  $handler->display->display_options['fields']['field_pv_city']['id'] = 'field_pv_city';
  $handler->display->display_options['fields']['field_pv_city']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_city']['field'] = 'field_pv_city';
  $handler->display->display_options['fields']['field_pv_city']['label'] = 'city';
  $handler->display->display_options['fields']['field_pv_city']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_pv_city']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_pv_city']['bypass_access'] = 0;
  /* Field: Indexed Node: County */
  $handler->display->display_options['fields']['field_pv_county']['id'] = 'field_pv_county';
  $handler->display->display_options['fields']['field_pv_county']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_county']['field'] = 'field_pv_county';
  $handler->display->display_options['fields']['field_pv_county']['label'] = 'county';
  $handler->display->display_options['fields']['field_pv_county']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_pv_county']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_pv_county']['bypass_access'] = 0;
  /* Field: Indexed Node: Authorized Official */
  $handler->display->display_options['fields']['field_pv_authorized_official']['id'] = 'field_pv_authorized_official';
  $handler->display->display_options['fields']['field_pv_authorized_official']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_authorized_official']['field'] = 'field_pv_authorized_official';
  $handler->display->display_options['fields']['field_pv_authorized_official']['label'] = 'authorized_official';
  /* Field: Indexed Node: Official Telephone */
  $handler->display->display_options['fields']['field_pv_official_telephone']['id'] = 'field_pv_official_telephone';
  $handler->display->display_options['fields']['field_pv_official_telephone']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_official_telephone']['field'] = 'field_pv_official_telephone';
  $handler->display->display_options['fields']['field_pv_official_telephone']['label'] = 'official_telephone';
  /* Field: Indexed Node: Type */
  $handler->display->display_options['fields']['field_pv_type']['id'] = 'field_pv_type';
  $handler->display->display_options['fields']['field_pv_type']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_type']['field'] = 'field_pv_type';
  $handler->display->display_options['fields']['field_pv_type']['label'] = 'type';
  $handler->display->display_options['fields']['field_pv_type']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_pv_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_pv_type']['bypass_access'] = 0;
  /* Filter criterion: Indexed Node: Telephone */
  $handler->display->display_options['filters']['field_pv_telephone']['id'] = 'field_pv_telephone';
  $handler->display->display_options['filters']['field_pv_telephone']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['filters']['field_pv_telephone']['field'] = 'field_pv_telephone';
  $handler->display->display_options['filters']['field_pv_telephone']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pv_telephone']['expose']['operator_id'] = 'field_pv_telephone_op';
  $handler->display->display_options['filters']['field_pv_telephone']['expose']['label'] = 'Telephone';
  $handler->display->display_options['filters']['field_pv_telephone']['expose']['operator'] = 'field_pv_telephone_op';
  $handler->display->display_options['filters']['field_pv_telephone']['expose']['identifier'] = 'telephone';
  $handler->display->display_options['filters']['field_pv_telephone']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['field_pv_telephone']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'list-provider-by-telephone';
  $export['list_provider_by_telephone'] = $view;

  $view = new view();
  $view->name = 'listing_multi_provider';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_node_index';
  $view->human_name = 'Listing Multi Provider';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Listing Multi Provider';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'views_json';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Node: City */
  $handler->display->display_options['fields']['field_pv_city']['id'] = 'field_pv_city';
  $handler->display->display_options['fields']['field_pv_city']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_city']['field'] = 'field_pv_city';
  $handler->display->display_options['fields']['field_pv_city']['label'] = 'city';
  $handler->display->display_options['fields']['field_pv_city']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_pv_city']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_pv_city']['bypass_access'] = 0;
  /* Field: Indexed Node: County */
  $handler->display->display_options['fields']['field_pv_county']['id'] = 'field_pv_county';
  $handler->display->display_options['fields']['field_pv_county']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_county']['field'] = 'field_pv_county';
  $handler->display->display_options['fields']['field_pv_county']['label'] = 'county';
  $handler->display->display_options['fields']['field_pv_county']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_pv_county']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_pv_county']['bypass_access'] = 0;
  /* Filter criterion: Indexed Node: Telephone */
  $handler->display->display_options['filters']['field_pv_telephone']['id'] = 'field_pv_telephone';
  $handler->display->display_options['filters']['field_pv_telephone']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['filters']['field_pv_telephone']['field'] = 'field_pv_telephone';
  $handler->display->display_options['filters']['field_pv_telephone']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pv_telephone']['expose']['operator_id'] = 'field_pv_telephone_op';
  $handler->display->display_options['filters']['field_pv_telephone']['expose']['label'] = 'Telephone';
  $handler->display->display_options['filters']['field_pv_telephone']['expose']['operator'] = 'field_pv_telephone_op';
  $handler->display->display_options['filters']['field_pv_telephone']['expose']['identifier'] = 'field_pv_telephone';
  $handler->display->display_options['filters']['field_pv_telephone']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'listing-multi-provider';
  $export['listing_multi_provider'] = $view;

  $view = new view();
  $view->name = 'provider_listing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_node_index';
  $view->human_name = 'provider-listing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'provider-listing';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Indexed Node: Telephone */
  $handler->display->display_options['fields']['field_pv_telephone']['id'] = 'field_pv_telephone';
  $handler->display->display_options['fields']['field_pv_telephone']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_telephone']['field'] = 'field_pv_telephone';
  $handler->display->display_options['fields']['field_pv_telephone']['label'] = 'telephone';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Node: City */
  $handler->display->display_options['fields']['field_pv_city']['id'] = 'field_pv_city';
  $handler->display->display_options['fields']['field_pv_city']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_city']['field'] = 'field_pv_city';
  $handler->display->display_options['fields']['field_pv_city']['label'] = 'city';
  $handler->display->display_options['fields']['field_pv_city']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_pv_city']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_pv_city']['bypass_access'] = 0;
  /* Field: Indexed Node: County */
  $handler->display->display_options['fields']['field_pv_county']['id'] = 'field_pv_county';
  $handler->display->display_options['fields']['field_pv_county']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_county']['field'] = 'field_pv_county';
  $handler->display->display_options['fields']['field_pv_county']['label'] = 'county';
  $handler->display->display_options['fields']['field_pv_county']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_pv_county']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_pv_county']['bypass_access'] = 0;
  /* Field: Indexed Node: Type */
  $handler->display->display_options['fields']['field_pv_type']['id'] = 'field_pv_type';
  $handler->display->display_options['fields']['field_pv_type']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_type']['field'] = 'field_pv_type';
  $handler->display->display_options['fields']['field_pv_type']['label'] = 'type';
  $handler->display->display_options['fields']['field_pv_type']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_pv_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_pv_type']['bypass_access'] = 0;
  /* Field: Indexed Node: Status */
  $handler->display->display_options['fields']['field_pv_status']['id'] = 'field_pv_status';
  $handler->display->display_options['fields']['field_pv_status']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_status']['field'] = 'field_pv_status';
  $handler->display->display_options['fields']['field_pv_status']['label'] = 'status';
  $handler->display->display_options['fields']['field_pv_status']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_pv_status']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_pv_status']['bypass_access'] = 0;
  /* Sort criterion: Indexed Node: Date changed */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filter criterion: Indexed Node: City */
  $handler->display->display_options['filters']['field_pv_city']['id'] = 'field_pv_city';
  $handler->display->display_options['filters']['field_pv_city']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['filters']['field_pv_city']['field'] = 'field_pv_city';
  $handler->display->display_options['filters']['field_pv_city']['value'] = array();
  $handler->display->display_options['filters']['field_pv_city']['group'] = 1;
  $handler->display->display_options['filters']['field_pv_city']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pv_city']['expose']['operator_id'] = 'field_pv_city_op';
  $handler->display->display_options['filters']['field_pv_city']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['field_pv_city']['expose']['operator'] = 'field_pv_city_op';
  $handler->display->display_options['filters']['field_pv_city']['expose']['identifier'] = 'city';
  $handler->display->display_options['filters']['field_pv_city']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_pv_city']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: State */
  $handler->display->display_options['filters']['field_pv_state']['id'] = 'field_pv_state';
  $handler->display->display_options['filters']['field_pv_state']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['filters']['field_pv_state']['field'] = 'field_pv_state';
  $handler->display->display_options['filters']['field_pv_state']['value'] = array();
  $handler->display->display_options['filters']['field_pv_state']['group'] = 1;
  $handler->display->display_options['filters']['field_pv_state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pv_state']['expose']['operator_id'] = 'field_pv_state_op';
  $handler->display->display_options['filters']['field_pv_state']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['field_pv_state']['expose']['operator'] = 'field_pv_state_op';
  $handler->display->display_options['filters']['field_pv_state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['field_pv_state']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_pv_state']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['field_pv_status']['id'] = 'field_pv_status';
  $handler->display->display_options['filters']['field_pv_status']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['filters']['field_pv_status']['field'] = 'field_pv_status';
  $handler->display->display_options['filters']['field_pv_status']['value'] = array();
  $handler->display->display_options['filters']['field_pv_status']['group'] = 1;
  $handler->display->display_options['filters']['field_pv_status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pv_status']['expose']['operator_id'] = 'field_pv_status_op';
  $handler->display->display_options['filters']['field_pv_status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_pv_status']['expose']['operator'] = 'field_pv_status_op';
  $handler->display->display_options['filters']['field_pv_status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['field_pv_status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_pv_status']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: County */
  $handler->display->display_options['filters']['field_pv_county']['id'] = 'field_pv_county';
  $handler->display->display_options['filters']['field_pv_county']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['filters']['field_pv_county']['field'] = 'field_pv_county';
  $handler->display->display_options['filters']['field_pv_county']['value'] = array();
  $handler->display->display_options['filters']['field_pv_county']['group'] = 1;
  $handler->display->display_options['filters']['field_pv_county']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pv_county']['expose']['operator_id'] = 'field_pv_county_op';
  $handler->display->display_options['filters']['field_pv_county']['expose']['label'] = 'County';
  $handler->display->display_options['filters']['field_pv_county']['expose']['operator'] = 'field_pv_county_op';
  $handler->display->display_options['filters']['field_pv_county']['expose']['identifier'] = 'county';
  $handler->display->display_options['filters']['field_pv_county']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_pv_county']['expose']['reduce'] = 0;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_full';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'field_pv_og_name' => 'field_pv_og_name',
    'field_pv_telephone' => 'field_pv_telephone',
  );
  /* Filter criterion: Indexed Node: Date */
  $handler->display->display_options['filters']['field_last_datetime']['id'] = 'field_last_datetime';
  $handler->display->display_options['filters']['field_last_datetime']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['filters']['field_last_datetime']['field'] = 'field_last_datetime';
  $handler->display->display_options['filters']['field_last_datetime']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_datetime']['expose']['operator_id'] = 'field_last_datetime_op';
  $handler->display->display_options['filters']['field_last_datetime']['expose']['label'] = 'date';
  $handler->display->display_options['filters']['field_last_datetime']['expose']['operator'] = 'field_last_datetime_op';
  $handler->display->display_options['filters']['field_last_datetime']['expose']['identifier'] = 'date';
  $handler->display->display_options['filters']['field_last_datetime']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Indexed Node: Priority Index */
  $handler->display->display_options['filters']['field_pv_priority_index']['id'] = 'field_pv_priority_index';
  $handler->display->display_options['filters']['field_pv_priority_index']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['filters']['field_pv_priority_index']['field'] = 'field_pv_priority_index';
  $handler->display->display_options['filters']['field_pv_priority_index']['value'] = array();
  $handler->display->display_options['filters']['field_pv_priority_index']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pv_priority_index']['expose']['operator_id'] = 'field_pv_priority_index_op';
  $handler->display->display_options['filters']['field_pv_priority_index']['expose']['label'] = 'priority';
  $handler->display->display_options['filters']['field_pv_priority_index']['expose']['operator'] = 'field_pv_priority_index_op';
  $handler->display->display_options['filters']['field_pv_priority_index']['expose']['identifier'] = 'priority';
  $handler->display->display_options['filters']['field_pv_priority_index']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_pv_priority_index']['expose']['reduce'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'provide-listing-data';
  $export['provider_listing'] = $view;

  $view = new view();
  $view->name = 'provider_manager';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_node_index';
  $view->human_name = 'Provider Manager';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Provider Manager';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<a href="/node/add/provider?destination=provider-manager">+ Add new provider</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<a href="/node/add/provider?destination=provider-manager">+ Add new provider</a>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Indexed Node: NPI */
  $handler->display->display_options['fields']['field_pv_npi']['id'] = 'field_pv_npi';
  $handler->display->display_options['fields']['field_pv_npi']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_npi']['field'] = 'field_pv_npi';
  /* Field: Indexed Node: Type */
  $handler->display->display_options['fields']['field_pv_type']['id'] = 'field_pv_type';
  $handler->display->display_options['fields']['field_pv_type']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_type']['field'] = 'field_pv_type';
  $handler->display->display_options['fields']['field_pv_type']['label'] = 'Entity Type';
  $handler->display->display_options['fields']['field_pv_type']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_pv_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_pv_type']['bypass_access'] = 0;
  /* Field: Indexed Node: Provider Organization Name */
  $handler->display->display_options['fields']['field_pv_og_name']['id'] = 'field_pv_og_name';
  $handler->display->display_options['fields']['field_pv_og_name']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_og_name']['field'] = 'field_pv_og_name';
  $handler->display->display_options['fields']['field_pv_og_name']['label'] = 'Provider Name';
  /* Field: Indexed Node: Practice Address */
  $handler->display->display_options['fields']['field_pv_practice_address']['id'] = 'field_pv_practice_address';
  $handler->display->display_options['fields']['field_pv_practice_address']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_practice_address']['field'] = 'field_pv_practice_address';
  $handler->display->display_options['fields']['field_pv_practice_address']['label'] = 'Practice Location Address';
  /* Field: Indexed Node: City */
  $handler->display->display_options['fields']['field_pv_city']['id'] = 'field_pv_city';
  $handler->display->display_options['fields']['field_pv_city']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_city']['field'] = 'field_pv_city';
  $handler->display->display_options['fields']['field_pv_city']['label'] = 'City Name';
  $handler->display->display_options['fields']['field_pv_city']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_pv_city']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_pv_city']['bypass_access'] = 0;
  /* Field: Indexed Node: State */
  $handler->display->display_options['fields']['field_pv_state']['id'] = 'field_pv_state';
  $handler->display->display_options['fields']['field_pv_state']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_state']['field'] = 'field_pv_state';
  $handler->display->display_options['fields']['field_pv_state']['label'] = 'State Name';
  $handler->display->display_options['fields']['field_pv_state']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_pv_state']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_pv_state']['bypass_access'] = 0;
  /* Field: Indexed Node: Telephone */
  $handler->display->display_options['fields']['field_pv_telephone']['id'] = 'field_pv_telephone';
  $handler->display->display_options['fields']['field_pv_telephone']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_telephone']['field'] = 'field_pv_telephone';
  $handler->display->display_options['fields']['field_pv_telephone']['label'] = 'Telephone Number';
  /* Field: Indexed Node: Status */
  $handler->display->display_options['fields']['field_pv_status']['id'] = 'field_pv_status';
  $handler->display->display_options['fields']['field_pv_status']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_pv_status']['field'] = 'field_pv_status';
  $handler->display->display_options['fields']['field_pv_status']['empty'] = 'New';
  $handler->display->display_options['fields']['field_pv_status']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_pv_status']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_pv_status']['bypass_access'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  /* Contextual filter: Indexed Node: Author */
  $handler->display->display_options['arguments']['author']['id'] = 'author';
  $handler->display->display_options['arguments']['author']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['arguments']['author']['field'] = 'author';
  $handler->display->display_options['arguments']['author']['default_action'] = 'default';
  $handler->display->display_options['arguments']['author']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['author']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['author']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['author']['not'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'provider-manager';
  $export['provider_manager'] = $view;

  return $export;
}
