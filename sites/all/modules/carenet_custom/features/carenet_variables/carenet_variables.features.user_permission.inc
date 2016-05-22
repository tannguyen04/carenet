<?php
/**
 * @file
 * carenet_variables.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function carenet_variables_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer providers'.
  $permissions['administer providers'] = array(
    'name' => 'administer providers',
    'roles' => array(
      'administrator' => 'administrator',
      'teller' => 'teller',
    ),
    'module' => 'carenet_custom',
  );

  return $permissions;
}
