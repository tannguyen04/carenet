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

  // Exported permission: 'access navbar'.
  $permissions['access navbar'] = array(
    'name' => 'access navbar',
    'roles' => array(
      'administrator' => 'administrator',
      'teller' => 'teller',
    ),
    'module' => 'navbar',
  );

  // Exported permission: 'create card_rate content'.
  $permissions['create card_rate content'] = array(
    'name' => 'create card_rate content',
    'roles' => array(
      'administrator' => 'administrator',
      'teller' => 'teller',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create provider content'.
  $permissions['create provider content'] = array(
    'name' => 'create provider content',
    'roles' => array(
      'provider' => 'provider',
      'teller' => 'teller',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any card_rate content'.
  $permissions['delete any card_rate content'] = array(
    'name' => 'delete any card_rate content',
    'roles' => array(
      'administrator' => 'administrator',
      'teller' => 'teller',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any provider content'.
  $permissions['delete any provider content'] = array(
    'name' => 'delete any provider content',
    'roles' => array(
      'provider' => 'provider',
      'teller' => 'teller',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own card_rate content'.
  $permissions['delete own card_rate content'] = array(
    'name' => 'delete own card_rate content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own provider content'.
  $permissions['delete own provider content'] = array(
    'name' => 'delete own provider content',
    'roles' => array(
      'provider' => 'provider',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any card_rate content'.
  $permissions['edit any card_rate content'] = array(
    'name' => 'edit any card_rate content',
    'roles' => array(
      'administrator' => 'administrator',
      'teller' => 'teller',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any provider content'.
  $permissions['edit any provider content'] = array(
    'name' => 'edit any provider content',
    'roles' => array(
      'teller' => 'teller',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own card_rate content'.
  $permissions['edit own card_rate content'] = array(
    'name' => 'edit own card_rate content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own provider content'.
  $permissions['edit own provider content'] = array(
    'name' => 'edit own provider content',
    'roles' => array(
      'provider' => 'provider',
    ),
    'module' => 'node',
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
