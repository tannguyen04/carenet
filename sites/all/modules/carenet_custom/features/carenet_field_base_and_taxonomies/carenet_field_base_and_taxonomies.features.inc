<?php
/**
 * @file
 * carenet_field_base_and_taxonomies.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function carenet_field_base_and_taxonomies_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
