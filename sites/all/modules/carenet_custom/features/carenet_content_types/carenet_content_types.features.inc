<?php
/**
 * @file
 * carenet_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function carenet_content_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function carenet_content_types_node_info() {
  $items = array(
    'card_rate' => array(
      'name' => t('Card Rate'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'discuss' => array(
      'name' => t('Discuss'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'provider' => array(
      'name' => t('Provider'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
