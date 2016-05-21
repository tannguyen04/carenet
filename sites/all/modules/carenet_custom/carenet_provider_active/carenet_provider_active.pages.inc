<?php

/*
 * Step provider active form
 */
function _carenet_provider_active_form_steps() {
  return array(
    1 => array(
      'form' => 'carenet_provider_active_form_program_review',
      'title' => t('Program review'),
    ),
    2 => array(
      'form' => 'carenet_provider_active_form_rate_card',
      'title' => t('Rate card information'),
    ),
    3 => array(
      'form' => 'carenet_provider_active_form_contract',
      'title' => t('Contract information'),
    ),
    4 => array(
      'form' => 'carenet_provider_active_form_signature_execute',
      'title' => t('Signature execute'),
    ),
  );
}

function carenet_provider_active_form_program_review($form, &$form_state) {
  $form = array(
    '#type' => 'container'
  );
  $form['program_review'] = array(
    '#markup' => variable_get('carenet_provider_active_program_review', ''),
  );
  return $form;
}

function carenet_provider_active_form_rate_card($form, &$form_state) {

  //Discussion and card rate
  $discussion = $form['#discussion'];
  $discussion_wrapper = entity_metadata_wrapper('node', $discussion);
  $price_custom = $discussion_wrapper->field_dc_price->value();
  $card_rate = $discussion_wrapper->field_card_rate_ref->value();
  $card_rate_wrapper = entity_metadata_wrapper('node', $card_rate);

  //Title card rate
  $title_card = $card_rate_wrapper->title->value(array('sanitize' => TRUE));

  //Price
  $price = 0;
  if (empty($price_custom)) {
    if (!empty($card_rate)) {
      $price = $card_rate_wrapper->field_card_rate_price->value();
    }
  }else {
    $price = $price_custom;
  }

  //Description card rate
  $description_card = $card_rate_wrapper->body->value(array('decode' => TRUE));
  $description_card_value = $description_card['value'];
  $output = '<div> ' . $title_card . ' </div>';
  $output .= '<div>'.$description_card_value.'</div>';
  $output .= '<div>Price: $'.$price.'</div>';

  $form = array(
    '#type' => 'container'
  );
  $form['rate_card'] = array(
    '#markup' => $output,
    '#type' => 'item',
  );
  return $form;
}

function carenet_provider_active_form_contract($form, &$form_state) {
  $form = array(
    '#type' => 'container'
  );
  $form['contract'] = array(
    '#markup' => variable_get('carenet_provider_active_contract', ''),
  );
  return $form;
}

function carenet_provider_active_form_signature_execute($form, &$form_state) {
  $form = array(
    '#type' => 'container',
    '#attached' => array(
      'js' => array(
        drupal_get_path('module', 'carenet_provider_active') . '/js/signature_execute.js'
      ),
    ),
  );
  //Accept
  $form['signature_execute'] = array(
    '#type' => 'container',
  );
  //
  $form['signature_execute']['signature_execute_show_accept'] = array(
    '#markup' => '<a class="btn" id="show-accept" href="#"> ' . t('Accept') . ' </a>',
  );
  $form['signature_execute']['signature_execute_show_ask_question'] = array(
    '#markup' => '<a class="btn" id="show-ask-question" href="#"> ' . t('Ask question') . ' </a>',
  );
  $form['signature_execute']['accept'] = array(
    '#type' => 'container',
    '#description' => t('Please enter below fields before submit'),
    '#attributes' => array(
      'class' => array('element-invisible', 'signature-execute-accept'),
    ),
    '#after_build' => array('_after_build_signature_execute_accept'),
  );

  $form['signature_execute']['accept']['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#maxlength' => USERNAME_MAX_LENGTH,
    '#description' => t('Spaces are allowed; punctuation is not allowed except for periods, hyphens, apostrophes, and underscores.'),
    '#required' => TRUE,
    '#attributes' => array('class' => array('username')),
    '#default_value' => !empty($form_state['values']['name']) ? $form_state['values']['name'] : '',
  );
  $form['signature_execute']['accept']['mail'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail address'),
    '#maxlength' => EMAIL_MAX_LENGTH,
    '#description' => t('A valid e-mail address. All e-mails from the system will be sent to this address. The e-mail address is not made public and will only be used if you wish to receive a new password or wish to receive certain news or notifications by e-mail.'),
    '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['mail']) ? $form_state['values']['mail'] : '',
  );
  $form['signature_execute']['accept']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Accept'),
    '#submit' => array('carenet_provider_active_form_signature_execute_accept_submit'),
    '#validate' => array('carenet_provider_active_form_signature_execute_accept_validate'),
    '#name' => 'op_accept',
    '#limit_validation_errors' => array(
      array('mail'), //Only validate email and username when click submit
      array('name'),
    ),
  );

  //Ask question
  $form['signature_execute']['ask_question'] = array(
    '#type' => 'container',
    '#description' => t('Please enter question before you submit'),
    '#attributes' => array(
      'class' => array('element-invisible', 'signature-execute-ask-question'),
    ),
    '#after_build' => array('_after_build_signature_execute_ask_question'),
  );
  $form['signature_execute']['ask_question']['question'] = array(
    '#type' => 'textarea',
    '#title' => t('Ask questions'),
    '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['question']) ? $form_state['values']['question'] : '',
  );
  $form['signature_execute']['ask_question']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Ask question'),
    '#submit' => array('carenet_provider_active_form_signature_execute_ask_question_submit'),
    '#limit_validation_errors' => array(
      array('question'), //Only validate question when click submit
    ),
    '#name' => 'op_ask_question',
  );
  return $form;
}

/*
 * After rebuild, remove class "element-invisible" if clicked button submit
 */

function _after_build_signature_execute_accept(&$element, $form_state) {
  if (isset($form_state['triggering_element'])) {
    if ($form_state['triggering_element']['#name'] == 'op_accept') {
      unset($element['#attributes']['class'][0]);
    }
  }
  return $element;
}
/*
 * After rebuild, remove class "element-invisible" if clicked button submit
 */
function _after_build_signature_execute_ask_question(&$element, $form_state) {
  if (isset($form_state['triggering_element'])) {
    if ($form_state['triggering_element']['#name'] == 'op_ask_question') {
      unset($element['#attributes']['class'][0]);
    }
  }
  return $element;
}

/*
 * Handler validate when user click accept
 */
function carenet_provider_active_form_signature_execute_accept_validate($form, &$form_state) {
  $account = $form['#user'];
  if (isset($form_state['values']['name'])) {
    if ($error = user_validate_name($form_state['values']['name'])) {
      form_set_error('name', $error);
    }elseif ((bool) db_select('users')->fields('users', array('uid'))->condition('uid', $account->uid, '<>')->condition('name', db_like($form_state['values']['name']), 'LIKE')->range(0, 1)->execute()->fetchField()) {
      form_set_error('name', t('The name %name is already taken.', array('%name' => $form_state['values']['name'])));
    }
  }
  $mail = trim($form_state['values']['mail']);
  form_set_value($form['step']['signature_execute']['accept']['mail'], $mail, $form_state);
  if ($error = user_validate_mail($mail)) {
    form_set_error('mail', $error);
  }elseif ((bool) db_select('users')->fields('users', array('uid'))->condition('uid', $account->uid, '<>')->condition('mail', db_like($form_state['values']['mail']), 'LIKE')->range(0, 1)->execute()->fetchField()) {
    // Format error message dependent on whether the user is logged in or not.
    if ($GLOBALS['user']->uid) {
      form_set_error('mail', t('The e-mail address %email is already taken.', array('%email' => $form_state['values']['mail'])));
    }
    else {
      form_set_error('mail', t('The e-mail address %email is already registered. <a href="@password">Have you forgotten your password?</a>', array('%email' => $form_state['values']['mail'], '@password' => url('user/password'))));
    }
  }
}

/*
 * Function handler submit accept
 */
function carenet_provider_active_form_signature_execute_accept_submit($form, &$form_state) {
  require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');
  $values = $form_state['values'];
  //Init user information
  $pass = user_password(8);
  $username = $values['name'];
  $pass = user_hash_password(trim($pass));
  $mail = $values['mail'];
  $roles = array();

  //Create user
  $new_username = entity_create('user', array());
  $new_username->name = $username;
  $new_username->status = 1;
  $new_username->roles = drupal_map_assoc($roles + array(DRUPAL_AUTHENTICATED_RID));
  $new_username->init = $mail;
  $new_username->mail = $mail;
  $new_username->pass = $pass;
  $new_username->timezone = date_default_timezone();
  $new_username = entity_metadata_wrapper('user', $new_username);
  $new_username->save();
  if (!$new_username) {
    drupal_set_message(t("Error saving"), 'error');
    return;
  }
  $uid = $new_username->getIdentifier();
  if ($uid) {
    //Send mail
    $new_username = user_load($uid);
    //Attachment file
    $attachment = file_load(83);
    $sent = _carenet_provider_active_mail_notify('email_provider_accept', $new_username, $attachment);
    if ($sent) {
      drupal_set_message(t('A welcome message with further instructions has been sent to your e-mail address.'));
    }
    $form_state['redirect'] = '<front>';
  }
}

/*
 * Handler submit ask question
 */
function carenet_provider_active_form_signature_execute_ask_question_submit($form, $form_state) {
  //Send mail for admin
  $admin_load = user_load(1);
  $admin_load->ask_question = $form_state['values']['question'];
  $sent = _carenet_provider_active_mail_notify('email_provider_ask_question', $admin_load);
  if ($sent) {
    drupal_set_message(t('A message with further instructions has been sent to ADMIN e-mail address.'));
  }
}


/*
 * Form provider active
 */
function carenet_provider_active_form($form, &$form_state, $token) {

  //Get discussion
  $discussion = _carenet_provider_active_get_discussion_by_token($token);
  if (!$discussion) {
    drupal_set_message(t('Sorry, token invalid'));
    drupal_goto('<front>');
  }
  $form['#discussion'] = ($discussion) ? $discussion : NULL;

  //Init step
  if (empty($form_state['step'])) {
    $form_state['step'] = 1;
    $form_state['step_information'] = _carenet_provider_active_form_steps();
  }
  $step = &$form_state['step'];
  drupal_set_title(t('Provider active: Step @step', array('@step' => $step)));
  $form['#user'] = drupal_anonymous_user();

  //Progress bar
  foreach ($form_state['step_information'] as $step_id => $values) {
    $progress_bar_items[] = array(
      'data' => $values['title'],
      'class' => ($step_id == $step) ? array('active', 'progress-item') : array('progress-item'),
    );
  }
  //Build form
  $form['progress_bar'] = array(
    '#markup' => theme_item_list(array('type' => 'ul' ,'title' => t('Progress bar'), 'items' => $progress_bar_items, 'attributes' => array())),
    '#type' => 'item',
  );


  //$form = $form_state['step_information'][$step]['form']($form, $form_state);
  $form['step'] = $form_state['step_information'][$step]['form']($form, $form_state);
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