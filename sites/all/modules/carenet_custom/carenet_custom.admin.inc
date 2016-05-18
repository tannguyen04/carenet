<?php

/*
 * Form admin provider active
 */
function carenet_admin_provider_active_form($form, &$form_state) {
  $form['carenet_provider_active_program_review'] = array(
    '#type' => 'text_format',
    '#title' => t('Program Review'),
    '#default_value' => variable_get('carenet_provider_active_program_review', ''),
    '#format' => variable_get('carenet_provider_active_program_review_format', 'full_html'),
    '#required' => TRUE,
  );
  $form['carenet_provider_active_contract'] = array(
    '#type' => 'text_format',
    '#title' => t('Program Review'),
    '#default_value' => variable_get('carenet_provider_active_contract', ''),
    '#format' => variable_get('carenet_provider_active_contract_format', 'full_html'),
    '#required' => TRUE,
  );
  $form['actions'] = array(
    '#type' => 'actions'
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

/*
 * Submit form admin provide active
 */

function carenet_admin_provider_active_form_submit($form, $form_state) {
  $values = $form_state['values'];

  variable_set('carenet_provider_active_program_review', $values['carenet_provider_active_program_review']['value']);
  variable_set('carenet_provider_active_program_review_format', $values['carenet_provider_active_program_review']['format']);
  variable_set('carenet_provider_active_contract', $values['carenet_provider_active_contract']['value']);
  variable_set('carenet_provider_active_contract_format', $values['carenet_provider_active_contract']['format']);
}