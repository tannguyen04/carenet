<?php
/**
 * @file
 * carenet_user.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function carenet_user_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'administrator' => 'administrator',
      'teller' => 'teller',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrator' => 'administrator',
      'teller' => 'teller',
    ),
    'module' => 'system',
  );

  return $permissions;
}
