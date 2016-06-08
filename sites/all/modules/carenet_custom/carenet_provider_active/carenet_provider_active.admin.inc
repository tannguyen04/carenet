<?php

/*
 * Form admin provider active
 */
function carenet_admin_provider_active_form($form, &$form_state) {
  $form['carenet_signature'] = array(
    '#type' => 'managed_file',
    '#title' => t('Signature'),
    '#description' => t('Allowed extensions: gif png jpg jpeg'),
    '#default_value' => variable_get('carenet_signature', ''),
    '#upload_location' => 'public://infinite_signature',
    '#upload_validators' => array(
      'file_validate_extensions' => array('gif png jpg jpeg'),
    ),
  );
  $form['carenet_contract_file'] = array(
    '#type' => 'managed_file',
    '#title' => t('Contract file'),
    '#description' => t('Allowed extensions: pdf'),
    '#default_value' => variable_get('carenet_contract_file', ''),
    '#upload_location' => 'public://infinite_contract',
    '#upload_validators' => array(
      'file_validate_extensions' => array('pdf'),
    ),
  );
  $form['carenet_provider_active_program_review'] = array(
    '#type' => 'text_format',
    '#title' => t('Program Review'),
    '#default_value' => variable_get('carenet_provider_active_program_review', ''),
    '#format' => variable_get('carenet_provider_active_program_review_format', 'full_html'),
    //'#required' => TRUE,
  );
  $form['carenet_provider_active_contract'] = array(
    '#type' => 'text_format',
    '#title' => t('Contract'),
    '#default_value' => variable_get('carenet_provider_active_contract', ''),
    '#format' => variable_get('carenet_provider_active_contract_format', 'full_html'),
    //'#required' => TRUE,
  );
  //List email
  $form['email'] = array(
    '#type' => 'vertical_tabs',
  );
  $email_token_help = t('Available variables are: [site:name], [site:url], [user:name], [user:mail], [site:login-url], [site:url-brief], [user:edit-url], [user:one-time-login-url], [user:cancel-url].');
  $form['email_provider_accept'] = array(
    '#type' => 'fieldset',
    '#title' => t('Email was sent when provider accept'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('Edit the welcome e-mail messages sent when provider accept') . ' ' . $email_token_help,
    '#group' => 'email',
  );
  $form['email_provider_accept']['email_provider_accept_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => variable_get('email_provider_accept_subject', ''),
    '#maxlength' => 180,
  );
  $form['email_provider_accept']['email_provider_accept_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#default_value' => variable_get('email_provider_accept_body', ''),
    '#rows' => 15,
  );
  $form['email_provider_ask_question'] = array(
    '#type' => 'fieldset',
    '#title' => t('Email was sent when provider ask question'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('Edit the welcome e-mail messages sent when provider ask question') . ' ' . $email_token_help,
    '#group' => 'email',
  );
  $form['email_provider_ask_question']['email_provider_ask_question_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => variable_get('email_provider_ask_question_subject', ''),
    '#maxlength' => 180,
  );
  $form['email_provider_ask_question']['email_provider_ask_question_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#default_value' => variable_get('email_provider_ask_question_body', ''),
    '#rows' => 15,
  );
//  $form['email_provider_receive_when_ask_question'] = array(
//    '#type' => 'fieldset',
//    '#title' => t('Email was sent to provider when ask question'),
//    '#collapsible' => TRUE,
//    '#collapsed' => TRUE,
//    '#description' => t('Edit the welcome e-mail messages sent when provider ask question') . ' ' . $email_token_help,
//    '#group' => 'email',
//  );
//  $form['email_provider_receive_when_ask_question']['email_provider_receive_when_ask_question_subject'] = array(
//    '#type' => 'textfield',
//    '#title' => t('Subject'),
//    '#default_value' => variable_get('email_provider_receive_when_ask_question_subject', ''),
//    '#maxlength' => 180,
//  );
//  $form['email_provider_receive_when_ask_question']['email_provider_receive_when_ask_question_body'] = array(
//    '#type' => 'textarea',
//    '#title' => t('Body'),
//    '#default_value' => variable_get('email_provider_receive_when_ask_question_body', ''),
//    '#rows' => 15,
//  );

  $form['actions'] = array(
    '#type' => 'actions'
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  $form['#submit'][] = 'carenet_admin_provider_active_form_submit';
  return $form;
}

/*
 * Submit form admin provide active
 */

function carenet_admin_provider_active_form_submit($form, $form_state) {
  $values = $form_state['values'];
  //Signature file
  if ($values['carenet_signature']) {
    //Save new file
    $file = file_load($values['carenet_signature']);
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);
    file_usage_add($file, 'file', 'user', 1);
    if ($file) {
      //Delete olfile
      $fid_rm = variable_get('carenet_signature', 0);
      $file_rm = file_load($fid_rm);
      if ($file_rm && ($fid_rm != $file->fid)) {
        file_delete($file_rm, TRUE);
      }
      variable_set('carenet_signature', $file->fid);
    }
  }else {
    $fid_rm = variable_get('carenet_signature', 0);
    $file_rm = file_load($fid_rm);
    if ($file_rm) {
      file_delete($file_rm, TRUE);
    }
    variable_set('carenet_signature', 0);
  }

  //Contract file
  if ($values['carenet_contract_file']) {
    //Save new file
    $file = file_load($values['carenet_contract_file']);
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);
    file_usage_add($file, 'file', 'user', 1);
    if ($file) {
      //Delete old file
      $fid_rm = variable_get('carenet_contract_file', 0);
      $file_rm = file_load($fid_rm);
      if ($file_rm && ($fid_rm != $file->fid)) {
        file_delete($file_rm, TRUE);
      }
      variable_set('carenet_contract_file', $file->fid);
    }
  }else {
    //Delete
    $fid_rm = variable_get('carenet_contract_file', 0);
    $file_rm = file_load($fid_rm);
    if ($file_rm) {
      file_delete($file_rm, TRUE);
    }
    variable_set('carenet_contract_file', 0);
  }

  variable_set('carenet_provider_active_program_review', $values['carenet_provider_active_program_review']['value']);
  variable_set('carenet_provider_active_program_review_format', $values['carenet_provider_active_program_review']['format']);
  variable_set('carenet_provider_active_contract', $values['carenet_provider_active_contract']['value']);
  variable_set('carenet_provider_active_contract_format', $values['carenet_provider_active_contract']['format']);

  //Email
  variable_set('email_provider_ask_question_subject', $values['email_provider_ask_question_subject']);
  variable_set('email_provider_ask_question_body', $values['email_provider_ask_question_body']);
  variable_set('email_provider_accept_subject', $values['email_provider_accept_subject']);
  variable_set('email_provider_accept_body', $values['email_provider_accept_body']);
  drupal_set_message('Saved');
  //variable_set('email_provider_receive_when_ask_question_subject', $values['email_provider_receive_when_ask_question_subject']);
  //variable_set('email_provider_receive_when_ask_question_body', $values['email_provider_receive_when_ask_question_body']);
}




