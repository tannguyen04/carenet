<?php
/**
 * @file
 * carenet_variables.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function carenet_variables_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'carenet_provider_active_contract';
  $strongarm->value = '<p><img alt="" src="/sites/default/files/img-iphone02.png" style="float: right; height: 178px; width: 200px;" /></p>

<p><span style="color: rgb(0, 0, 0); font-family: \'Open Sans\', Arial, sans-serif; font-size: 14px; text-align: justify;">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin pretium nibh ut tincidunt viverra. Sed rhoncus, neque non vulputate convallis, nunc justo blandit mauris, vel interdum lectus leo at tellus. Sed ac euismod magna. Etiam blandit dolor nulla, non condimentum lacus accumsan luctu.</span></p>

<p><span style="color: rgb(0, 0, 0); font-family: \'Open Sans\', Arial, sans-serif; font-size: 14px; text-align: justify;">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin pretium nibh ut tincidunt viverra. Sed rhoncus, neque non vulputate convallis, nunc justo blandit mauris, vel interdum lectus leo at tellus. Sed ac euismod magna. Etiam blandit dolor nulla, non condimentum lacus accumsan luctu</span></p>

<p><span style="color: rgb(0, 0, 0); font-family: \'Open Sans\', Arial, sans-serif; font-size: 14px; text-align: justify;">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin pretium nibh ut tincidunt viverra. Sed rhoncus, neque non vulputate convallis, nunc justo blandit mauris, vel interdum lectus leo at tellus. Sed ac euismod magna. Etiam blandit dolor nulla, non condimentum lacus accumsan luctu</span></p>

<p><span style="color: rgb(0, 0, 0); font-family: \'Open Sans\', Arial, sans-serif; font-size: 14px; text-align: justify;">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin pretium nibh ut tincidunt viverra. Sed rhoncus, neque non vulputate convallis, nunc justo blandit mauris, vel interdum lectus leo at tellus. Sed ac euismod magna. Etiam blandit dolor nulla, non condimentum lacus accumsan luctu</span></p>
';
  $export['carenet_provider_active_contract'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'carenet_provider_active_contract_format';
  $strongarm->value = 'full_html';
  $export['carenet_provider_active_contract_format'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'carenet_provider_active_program_review';
  $strongarm->value = '<p><span style="color: rgb(0, 0, 0); font-family: \'Open Sans\', Arial, sans-serif; font-size: 14px; text-align: justify;"><img alt="" src="/sites/default/files/5467slider04-img02.png" style="height: 210px; width: 200px; float: left;" />Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin pretium nibh ut tincidunt viverra. Sed rhoncus, neque non vulputate convallis, nunc justo blandit mauris, vel interdum lectus leo at tellus. Sed ac euismod magna. Etiam blandit dolor nulla, non condimentum lacus accumsan luctu.</span></p>

<p><span style="color: rgb(0, 0, 0); font-family: \'Open Sans\', Arial, sans-serif; font-size: 14px; text-align: justify;">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin pretium nibh ut tincidunt viverra. Sed rhoncus, neque non vulputate convallis, nunc justo blandit mauris, vel interdum lectus leo at tellus. Sed ac euismod magna. Etiam blandit dolor nulla, non condimentum lacus accumsan luctu</span></p>

<p><span style="color: rgb(0, 0, 0); font-family: \'Open Sans\', Arial, sans-serif; font-size: 14px; text-align: justify;">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin pretium nibh ut tincidunt viverra. Sed rhoncus, neque non vulputate convallis, nunc justo blandit mauris, vel interdum lectus leo at tellus. Sed ac euismod magna. Etiam blandit dolor nulla, non condimentum lacus accumsan luctu</span></p>

<p><span style="color: rgb(0, 0, 0); font-family: \'Open Sans\', Arial, sans-serif; font-size: 14px; text-align: justify;">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin pretium nibh ut tincidunt viverra. Sed rhoncus, neque non vulputate convallis, nunc justo blandit mauris, vel interdum lectus leo at tellus. Sed ac euismod magna. Etiam blandit dolor nulla, non condimentum lacus accumsan luctu</span></p>
';
  $export['carenet_provider_active_program_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'carenet_provider_active_program_review_format';
  $strongarm->value = 'full_html';
  $export['carenet_provider_active_program_review_format'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'email_provider_accept_body';
  $strongarm->value = '[user:name],

Thank you for registering at [site:name]. You may now log in by clicking this link or copying and pasting it to your browser:

[user:one-time-login-url]

This link can only be used once to log in and will lead you to a page where you can set your password.

After setting your password, you will be able to log in at [site:login-url] in the future using:

username: [user:name]
password: Your password

--  [site:name] team';
  $export['email_provider_accept_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'email_provider_accept_subject';
  $strongarm->value = 'Account details for [user:name] at [site:name]';
  $export['email_provider_accept_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'email_provider_ask_question_body';
  $strongarm->value = 'Hi [user:name],
Provider just ask question for you:

[user:ask_question]

--  [site:name] team';
  $export['email_provider_ask_question_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'email_provider_ask_question_subject';
  $strongarm->value = 'Provider jus ask question';
  $export['email_provider_ask_question_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mimemail_format';
  $strongarm->value = 'full_html';
  $export['mimemail_format'] = $strongarm;

  return $export;
}
