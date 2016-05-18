<?php

/*
 * Step provider active form
 */
function _carenet_provider_active_form_steps() {
  return array(
    1 => array(
      'form' => 'carenet_provider_active_form_program_review',
    ),
    2 => array(
      'form' => 'carenet_provider_active_form_rate_card',
    ),
    3 => array(
      'form' => 'carenet_provider_active_form_contract',
    ),
    4 => array(
      'form' => 'carenet_provider_active_form_signature_execute'
    ),
  );
}

function carenet_provider_active_form_program_review($form, &$form_state) {
  $form = array();
  $form['program_review'] = array(
    '#markup' => variable_get('carenet_provider_active_program_review', ''),
  );
  return $form;
}

function carenet_provider_active_form_rate_card($form, &$form_state) {
  $form = array();
  $form['rate_card'] = array(
    '#markup' => 'This is card',
  );
  return $form;
}

function carenet_provider_active_form_contract($form, &$form_state) {
  $form = array();
  $form['contract'] = array(
    '#markup' => variable_get('carenet_provider_active_contract', ''),
  );
  return $form;
}

function carenet_provider_active_form_signature_execute($form, &$form_state) {
  $form = array();
  $form['signature_execute'] = array(
    '#type' => 'container'
  );
  //Accept
  $form['signature_execute']['accept'] = array(
    '#type' => 'fieldset',
    '#title' => t('Accept'),
    '#description' => t('Please enter below fields before submit'),
  );
  $form['signature_execute']['accept']['username'] = array(
    '#type' => 'textfield',
    '#title' => t('User name')
  );
  $form['signature_execute']['accept']['birthday'] = array(
    '#type' => 'textfield',
    '#title' => t('Birthday'),
  );
  $form['signature_execute']['accept']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Accept'),
    '#submit' => array('carenet_provider_active_form_signature_execute_accept_submit'),
  );
  //Ask question
  $form['signature_execute']['ask_question'] = array(
    '#type' => 'fieldset',
    '#title' => t('Ask question'),
    '#description' => t('Please enter question before you submit'),
  );
  $form['signature_execute']['ask_question']['question'] = array(
    '#type' => 'textarea',
    '#title' => t('Ask questions')
  );
  $form['signature_execute']['ask_question']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Ask question'),
    '#submit' => array('carenet_provider_active_form_signature_execute_ask_question_submit'),
  );
  return $form;
}

/*
 * Function handler submit accept
 */
function carenet_provider_active_form_signature_execute_accept_submit($form, $form_state) {
  print_r($form_state);
  die;
}

/*
 * Handler submit ask question
 */
function carenet_provider_active_form_signature_execute_ask_question_submit($form, $form_state) {
  print_r($form_state);
  die;
}


/*
 * Form provider active
 */
function carenet_provider_active_form($form, &$form_state) {
  //Init step
  if (empty($form_state['step'])) {
    $form_state['step'] = 1;
    $form_state['step_information'] = _carenet_provider_active_form_steps();
  }
  $step = &$form_state['step'];
  drupal_set_title(t('Extensible Wizard: Step @step', array('@step' => $step)));

  $form = $form_state['step_information'][$step]['form']($form, $form_state);

  //Show prev submit
  $form['actions'] = array(
    '#type' => 'actions',
  );
  if ($step > 1) {
    $form['actions']['prev'] = array(
      '#type' => 'submit',
      '#value' => t('Previous'),
      '#name' => 'prev',
      '#submit' => array('carenet_provider_active_form_previous_submit'),
      '#limit_validation_errors' => array(),
    );
  }
  //Show next submit
  if ($step < count($form_state['step_information'])) {
    $form['actions']['next'] = array(
      '#type' => 'submit',
      '#value' => t('Next'),
      '#name' => 'next',
      '#submit' => array('carenet_provider_active_form_next_submit'),
    );
  }
  return $form;
}

/**
 * Provider active handler prev submit
 */
function carenet_provider_active_form_previous_submit($form, &$form_state) {
  $current_step = &$form_state['step'];
  $form_state['step_information'][$current_step]['stored_values'] = $form_state['values'];
  if ($current_step > 1) {
    $current_step--;
    $form_state['values'] = $form_state['step_information'][$current_step]['stored_values'];
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Provider active handler next submit
 */
function carenet_provider_active_form_next_submit($form, &$form_state) {
  $current_step = &$form_state['step'];
  $form_state['step_information'][$current_step]['stored_values'] = $form_state['values'];

  if ($current_step < count($form_state['step_information'])) {
    $current_step++;
    if (!empty($form_state['step_information'][$current_step]['stored_values'])) {
      $form_state['values'] = $form_state['step_information'][$current_step]['stored_values'];
    }
    else {
      $form_state['values'] = array();
    }
    // Force rebuild with next step.
    $form_state['rebuild'] = TRUE;
    return;
  }
}