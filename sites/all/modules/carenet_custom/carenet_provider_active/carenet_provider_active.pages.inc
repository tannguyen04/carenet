<?php

/*
 * Step provider active form
 */
function _carenet_provider_active_form_steps() {
  return array(
    1 => array(
      'form' => 'carenet_provider_active_form_program_review',
      'title' => t('Program Review'),
    ),
    2 => array(
      'form' => 'carenet_provider_active_form_rate_card',
      'title' => t('Rate Card Information'),
    ),
    3 => array(
      'form' => 'carenet_provider_active_form_contract',
      'title' => t('Contract Information'),
    ),
    4 => array(
      'form' => 'carenet_provider_active_form_signature_execute',
      'title' => t('Approval'),
    ),
  );
}

function carenet_provider_active_form_program_review($form, &$form_state) {
  $form = array(
    '#type' => 'container'
  );

  $markup = '<h3>Program Summary</h3>
    <p>Established in 2001, Infinite is a globally established organization with over 5000 employees across 16 locations. Infinite provides a multitude of solutions and services, specializing in the Healthcare, Banking & Finance, Telecommunications & Technology and Media & Publishing industries for Fortune 1000 companies including Federal Government. For more information visit <a href="http://www.infinite.com/">www.infinite.com.</a></p>
    <p>Infinite CareNET (<a href="http://www.infinitecarenet.com/">www.infinitecarenet.com</a>) is a strategic business unit under Infinite’s Healthcare division that has established its provider network to provide health assessments for Veterans across the USA. Our strong network of physicians and medical staff conduct evaluations and capture information required by referring organizations. Our healthcare providers work with the details of each individual to ensure that matters are handled with the respect and sensitivity they deserve. </p>
    <p>Due to the increase in demand of CareNET’s services, we are rapidly enhancing our network of healthcare providers.  We are looking for healthcare providers across most specialties including General Practitioners, Audiologist, Psychiatrist, Neurologist, Dentist, etc. </p>
    <p>Our team will be working very closely to make sure that the process remains simple and easy to follow for the network with online tools, training and a help desk to mitigate any issues.</p>
    <p>Once you express interest in getting more detail, Infinite will provide all the reimbursement rates and contract details through our automated portal.  Rates are dependent on the complexity of the health assessment being conducted.</p>
    <h3>Key Highlights</h3>
    <ul>
        <li>The assessments are single sessions of 30-60 minutes that involve no therapeutic intervention, follow-ups or prescriptions.</li>
        <li>Payments will be made directly by Infinite within 30 days of uploading of completed a requested Benefits Questionnaire (DBQ) and other required information</li>
        <li>All examinations are to be performed in an OSHA/ADA compliant facility.</li>
        <li>Examinations can be provided by a physician, physician assistant or Nurse Practitioner.</li>
        <li>All providers need to be State licensed and have active certifications.</li>
        <li>Typically, each Veteran’s assessment request will include 1-2 questionnaires while others might have additional forms depending on their medical history and condition. Examples of DBQs -
            <ul>
                <li>General Medicine - <a href="http://www.vba.va.gov/pubs/forms/VBA-21-0960M-10-ARE.pdf">Muscle Injuries</a></li>
                <li>Ophthalmology - <a href="http://www.vba.va.gov/pubs/forms/VBA-21-0960N-2-ARE.pdf">Eye Conditions</a></li>
                <li>Psychiatry - <a href="http://www.vba.va.gov/pubs/forms/VBA-21-0960P-3-ARE.pdf">Review Post Traumatic Stress Disorder (PTSD)</a></li>
                <li>Audiology - <a href="http://www.vba.va.gov/pubs/forms/VBA-21-0960N-1-ARE.pdf">Ear Conditions (including Vestibular and Infectious Conditions)</a></li>
            </ul>
        </li>
        <li>The entire process is managed via Infinite CareNET’s state-of-the-art provider portal where you will be able to submit responses against each of the DBQs online. Infinite CareNet team will provide training, dedicated IT support and assign a relationship manager to your practice.</li>
        <li>Should a computer-centric approach not be practical, although it is more HIPAA compliant and less cumbersome, Infinite CareNet will fax documents to your office and mail copies to the Veteran. The evaluation may then be faxed to a designated fax number.</li>
        <li>Appointment scheduling is completed between 7-10 days giving you the option of setting your own pace and accepting as many or as few appointments as you wish to accommodate on your schedule.</li>
    </ul>
    <h3>The Process</h3>
    <ul>
        <li>Infinite will train the medical network on how to manage evaluations</li>
        <li>Schedule Veteran Appointment</li>
        <li>Provider will conduct the examinations based on the health condition being assessed</li>
        <li>Provider will also receive a list of diagnostic tests to be conducted on order to make the evaluation</li>
        <li>Provider will submit paperwork post assessment via the online portal</li>
        <li>Infinite CareNET will provide payment per contract terms</li>
    </ul>
    <h3>Key Benefits</h3>
    <ul>
        <li>Opportunity to augment revenue stream with low overhead</li>
        <li>No interface with insurance companies</li>
        <li>Robust volume</li>
        <li>Ability to see additional patients as part of the normal work day</li>
        <li>Evaluations may be conducted by physicians, physician extenders, or independent licensed practitioners to allow for optimization of services provided with cost to deliver the service</li>
        <li>Online tools and workflows creating a simplified process to follow</li>
        <li>Great opportunity to serve Veterans who have served our country</li>
    </ul>
  ';

  $form['program_review'] = array(
    '#markup' => variable_get('carenet_provider_active_program_review', ''),
  );
  $form['program_review'] = array(
    '#markup' => $markup,
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
  $header = array(
    t('Line item'),
    t('Description'),
    t('Price (USD)'),
  );
  $rows = array();
  //Title card rate
  $title = $card_rate_wrapper->title->value();
  $rows[] = array('', array('data' => $title, 'class' => 'label-card-rate'), '');
  //Description card rate
  $description = $card_rate_wrapper->body->value->value();
  if (!empty($description)) {
    $rows[] = array('', array('data' => $description, 'class' => 'description-card-rate'), '');
  }
  //Line item card rate
  $line_items = $card_rate_wrapper->field_card_rate_item->value();
  if (!empty($line_items)) {
    foreach ($line_items as $key => $item) {
      $collection_wrapper = entity_metadata_wrapper('field_collection_item', $item);
      $label = $collection_wrapper->field_text_title->value();
      $price = $collection_wrapper->field_price->value();
      $rows[] = array(
        $key+1,
        $label,
        '$ '. $price,
      );
    }
  }

  $form = array(
    '#type' => 'container'
  );
  $form['rate_card'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#attributes' => array(
      'class' => array('table table-hover table-bordered')
    ),
  );
  return $form;
}

function carenet_provider_active_form_contract($form, &$form_state) {
  $card_rate = $form['#card_rate'];

  $form = array(
    '#type' => 'container'
  );
  $form['contract'] = array(
    '#markup' => variable_get('carenet_provider_active_contract', ''),
  );
  //FILE PDF contract
//  $pdf_render = field_view_field('node', $card_rate, 'field_document', array(
//    'label' => 'hidden',
//    'type' => 'pdf_default',
//    'settings' => array(
//      'keep_pdfjs' => TRUE,
//      'width' => '100%',
//      'height' => '600px',
//    ),
//  ));
  $contract_file = file_load(variable_get('carenet_contract_file', 0));
  $contract_file = file_uri_to_object('public://infinite_contract/Participation__AGREEMENT_Final.pdf');
  if ($contract_file) {
    $form['pdf_contract'] = array(
      '#theme' => 'pdf_formatter_default',
      '#file' => $contract_file,
      '#keep_pdfjs' => TRUE,
      '#width' => '100%',
      '#height' => '600px',
    );
  }


  return $form;
}

function carenet_provider_active_pdf_generate($source, $destination, $full_name, $organization_name, $job_title, $address, $rows, $row2=array()) {
  //$pdffile = file_create_url('public://doc.pdf');
  require_once(libraries_get_path('fpdf').'/fpdf.php');
  require_once(libraries_get_path('fpdi').'/fpdi.php');
  $full_path = DRUPAL_ROOT. '/'.drupal_get_path('module', 'carenet_provider_active');

  $time = time();
  $path_pdf_table_rate_tmp = drupal_realpath('public://table_rate_tmp_'. $time. '.pdf');

  $pdf = new PDF();
  $header = array('Item', 'Description', 'Price');
  $pdf->SetFont('Arial','',14);
  $pdf->AddPage();
  $pdf->FancyTable($header,$rows);
  if (count($row2) > 0) {
    $pdf->AddPage();
    $pdf->FancyTable($header,$rows,2);
  }
  $pdf->Output('F', $path_pdf_table_rate_tmp);

  // initiate FPDI
  $pdf = new FPDI();
  // get the page count
  $pageCount = $pdf->setSourceFile($source);
  // iterate through all pages
  for ($pageNo = 1; $pageNo <= $pageCount; $pageNo++) {
    // import a page
    $templateId = $pdf->importPage($pageNo);
    // get the size of the imported page
    $size = $pdf->getTemplateSize($templateId);

    // create a page (landscape or portrait depending on the imported page size)
    if ($size['w'] > $size['h']) {
      $pdf->AddPage('L', array($size['w'], $size['h']));
    } else {
      $pdf->AddPage('P', array($size['w'], $size['h']));
    }
    // use the imported page
    $pdf->useTemplate($templateId);
    $pdf->SetFont('Arial','',10);
    $full_name = trim($full_name);
    $organization_name = trim($organization_name);
    $job_title = trim($job_title);
    if ($pageNo == 1) {
      //Organization name
      $pdf->SetTextColor(0);
      $pdf->SetXY(70, 46);
      $pdf->Write(0, $organization_name);
      // address
      $pdf->SetTextColor(0);
      $pdf->SetXY(20, 50);
      $pdf->Write(0, $address);

    } elseif($pageNo == 6) {
      // now write some text above the imported page
      $pdf->SetFont('Arial','',10);
      //Full name
      $pdf->SetTextColor(0);
      $pdf->SetXY(35, 243);
      $pdf->Write(0, $full_name);

      //Organization name
      $pdf->SetTextColor(0);
      $pdf->SetXY(35, 234);
      $pdf->Write(0, $organization_name);

      //Job title
      $pdf->SetTextColor(0);
      $pdf->SetXY(35, 239);
      $pdf->Write(0, $job_title);

      // Date
      $pdf->SetTextColor(0);
      $pdf->SetXY(35, 247);
      $pdf->Write(0, format_date(REQUEST_TIME, 'custom', 'm/d/Y'));

      //Add image signature
      $fid = variable_get('carenet_signature', '');
      if ($file = file_load($fid)) {
        $signature_image_url = file_create_url($file->uri);
        $pdf->Image($signature_image_url, 125, 229, 20, 6);
      }
    } elseif ($pageNo == $pageCount) {

      //Full name
      $pdf->SetTextColor(0);
      $pdf->SetXY(30, 143);
      $pdf->Write(0, $full_name);
      //Job title
      $pdf->SetTextColor(0);
      $pdf->SetXY(30, 152);
      $pdf->Write(0, $job_title);
      // Date
      $pdf->SetTextColor(0);
      $pdf->SetXY(30, 161);
      $pdf->Write(0, format_date(REQUEST_TIME, 'custom', 'm/d/Y'));
    }
  }
  $pageCount = $pdf->setSourceFile($path_pdf_table_rate_tmp);
  $tplIdx = $pdf->importPage(1, '/MediaBox');
  $pdf->addPage();
  $pdf->useTemplate($tplIdx, 0, 0, 0);
  $pdf->Output($destination, 'F');

  file_unmanaged_delete($path_pdf_table_rate_tmp);
  return $destination;
}


function carenet_provider_active_form_signature_execute($form, &$form_state) {
  $discussion_wrapper = entity_metadata_wrapper('node', $form['#discussion']);
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
  $form['signature_execute']['aggreement'] = array(
    '#markup' => '<div id="actions-buttons-container"><br/><br/><p>I have reviewed the program overview, the contract and applicable rate card(s).</p>',
  );
  $form['signature_execute']['signature_execute_show_accept'] = array(
    '#markup' => '<div id="actions-buttons"><a class="dexp-shortcodes-button btn btn-lg btn-link" id="show-accept" href="#"> ' . t('Accept') . ' </a>',
  );
  $form['signature_execute']['signature_execute_show_ask_question'] = array(
    '#markup' => '<a class="dexp-shortcodes-button btn btn-lg btn-link" id="show-ask-question" href="#"> ' . t('Ask a Question') . ' </a></div></div>',
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
    '#default_value' => !empty($form_state['values']['mail']) ? $form_state['values']['mail'] : $discussion_wrapper->field_dc_email->value(),
  );
  $form['signature_execute']['accept']['full_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Full Name'),
    '#attributes' => array('class' => array('full-name')),
    '#required' => TRUE,
    '#default_value' =>  !empty($form_state['values']['full_name']) ? $form_state['values']['full_name'] : $discussion_wrapper->field_dc_person->value(),
  );
  $form['signature_execute']['accept']['organization_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Organization Name'),
    '#attributes' => array('class' => array('organization-name')),
    '#required' => TRUE,
    '#default_value' =>  !empty($form_state['values']['organization_name']) ? $form_state['values']['organization_name'] : '',
  );
  $form['signature_execute']['accept']['job_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Job title'),
    '#attributes' => array('class' => array('job-title')),
    '#required' => TRUE,
    '#default_value' =>  !empty($form_state['values']['job_title']) ? $form_state['values']['job_title'] : '',
  );
  $form['signature_execute']['accept']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Sign'),
    '#submit' => array('carenet_provider_active_form_signature_execute_accept_submit'),
    '#validate' => array('carenet_provider_active_form_signature_execute_accept_validate'),
    '#name' => 'op_accept',
    '#limit_validation_errors' => array(
      array('mail'), //Only validate email and username when click submit
      array('name'),
      array('full_name'),
      array('organization_name'),
      array('job_title'),
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
    '#value' => t('Send'),
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
  $roles = array(5); //Provider role

  $discussion = $form['#discussion'];
  $discussion_wrapper = entity_metadata_wrapper('node', $discussion);
  $card_rate = $discussion_wrapper->field_card_rate_ref->value();
  $card_rate_wrapper = entity_metadata_wrapper('node', $card_rate);
  $providers = $discussion_wrapper->field_list_provider->value();
  $address = '';
  if ($providers) {
    $provider = $providers[0];
    $provider_wrapper = entity_metadata_wrapper('node', $provider);
    $address = $provider_wrapper->field_pv_practice_address->value();
  }
  //use card rate
  $rows = array();
  $row2 = array();
  $title = strip_tags($card_rate_wrapper->title->value());
  $rows = _cardrate_getdata($card_rate_wrapper, $rows);
  if (strpos($title,'General Medical Examination') === false) {
    $tmp = node_load(1155);
    $rows[] = array('','','');
    $rows = _cardrate_getdata(entity_metadata_wrapper('node', $tmp), $rows);
  }
    $time_generate_pdf = REQUEST_TIME;
    $dest = drupal_realpath('private://contract_'.$time_generate_pdf.'.pdf');
    //$source = drupal_realpath('public://infinite_contract/Participation__AGREEMENT_Final_1463949571.pdf');
    $source = drupal_realpath('public://infinite_contract/Participation__AGREEMENT_Final.pdf');

    carenet_provider_active_pdf_generate($source, $dest, $values['full_name'], $values['organization_name'], $values['job_title'], $address,$rows,$row2);

    // We have complete file path.
    $file = new stdClass;
    $file->uid = 1;
    $file->filename = pathinfo($dest, PATHINFO_BASENAME);
    $file->uri = 'private://contract_'.$time_generate_pdf.'.pdf';
    $file->filemime = file_get_mimetype($dest);
    $file->display = 1;
    // Make it permanent, otherwise it will get deleted later.
    $file->status = FILE_STATUS_PERMANENT;

    // Save file object to make it a 'managed file'.
    file_save($file);

    // We will save file under this location.
    $destination = 'private://contract_signed/';

    // Make sure destination directory exists before moving files to that path.
    // This will create directory if it does not exists.
    file_prepare_directory($destination, FILE_CREATE_DIRECTORY);
    //print_r($file);
    //die;

  //}

  //Create user
  $new_username = entity_create('user', array());
  $new_username->name = $username;
  $new_username->status = 1;
  $new_username->roles = drupal_map_assoc($roles + array(DRUPAL_AUTHENTICATED_RID));
  $new_username->init = $mail;
  $new_username->mail = $mail;
  $new_username->pass = $pass;
  $new_username->timezone = date_default_timezone();
  $new_username->field_contract['und'][0] = (array) $file;

  $new_username_wrapper = entity_metadata_wrapper('user', $new_username);
  $new_username_wrapper->field_full_name->set($values['full_name']);
  $new_username_wrapper->field_pv_og_name->set($values['organization_name']);
  $new_username_wrapper->field_job_title->set($values['job_title']);
  $new_username_wrapper->field_card_rate_ref->set($card_rate_wrapper->getIdentifier());
  $new_username_wrapper->save();


  if (!$new_username) {
    drupal_set_message(t("Error saving"), 'error');
    return;
  }
  $uid = $new_username_wrapper->getIdentifier();
  if ($uid) {
    //Send mail
    $new_username = user_load($uid);
    //Attachment file
    $attachment = isset($file) ? $file : NULL;
    $sent = _carenet_provider_active_mail_notify('email_provider_accept', $new_username, $attachment);
    if ($sent) {
      drupal_set_message(t('A welcome message with further instructions has been sent to your e-mail address.'));
    }
    //Update again status discussion
    $discussion_wrapper->field_dc_status->set(4921); //Accpeted
    $discussion_wrapper->save();
    $form_state['redirect'] = 'node/1100';
  }
}

function _cardrate_getdata($card_rate_wrapper, $rows) {
  //Title card rate
  $title = strip_tags($card_rate_wrapper->title->value());
  $tmp = explode('_', $title);
  if (count($tmp) > 1) {
    $title = '';
    for($i=0;$i<count($tmp)-1;$i++) {
      $title .= $tmp[$i];
    }
  }
  $rows[] = array('', $title, '');
  //Description card rate
  $description = $card_rate_wrapper->body->value->value();
  if (!empty($description)) {
    $rows[] = array('', strip_tags($description), '');
  }
  //Line item card rate
  $line_items = $card_rate_wrapper->field_card_rate_item->value();
  if (!empty($line_items)) {
    foreach ($line_items as $key => $item) {
      $collection_wrapper = entity_metadata_wrapper('field_collection_item', $item);
      $label = $collection_wrapper->field_text_title->value();
      $price = $collection_wrapper->field_price->value();
      $rows[] = array(
          $key+1,
          $label,
          '$ '. $price,
      );
    }
  }
  return $rows;
}

/*
 * Handler submit ask question
 */
function carenet_provider_active_form_signature_execute_ask_question_submit($form, $form_state) {
  $discussion_wrapper = entity_metadata_wrapper('node', $form['#discussion']);

  //Send to provider
  $provider = drupal_anonymous_user();
  $provider->ask_question = $form_state['values']['question'];
  $provider->name = $discussion_wrapper->field_dc_person->value();
  $provider->mail = $discussion_wrapper->field_dc_email->value();
  $sent = _carenet_provider_active_mail_notify('email_provider_ask_question', $provider);
  if ($sent) {
    drupal_set_message(t('Your question has been sent, we will review and get back to you as soon as possible.'));
  }
}


/*
 * Form provider active
 */
function carenet_provider_active_form($form, &$form_state, $token) {
  //Get discussion
  $discussion = _carenet_provider_active_get_discussion_by_token($token);
  if (!$discussion) {
    drupal_set_message(t('Sorry, token invalid'), 'error');
    drupal_goto('<front>');
  }
  $form['#discussion'] = ($discussion) ? $discussion : NULL;
  $discussion_wrapper = entity_metadata_wrapper('node', $discussion);
  $price_custom = $discussion_wrapper->field_dc_price->value();
  $card_rate = $discussion_wrapper->field_card_rate_ref->value();
  $form['#card_rate'] = ($card_rate) ? $card_rate : NULL;

  //Init step
  if (empty($form_state['step'])) {
    $form_state['step'] = 1;
    $form_state['step_information'] = _carenet_provider_active_form_steps();
  }
  $step = &$form_state['step'];
  drupal_set_title(t('Provider activation: @step', array('@step' => $form_state['step_information'][$step]['title'])));
  $form['#user'] = drupal_anonymous_user();

  //Progress bar


  foreach ($form_state['step_information'] as $step_id => $values) {
    $progress_bar_items[$step_id] = array(
      'data' => $values['title'],
    );

    if($step_id < $step){
      $progress_bar_items[$step_id]['class'] = array('progress-item dexp-shortcodes-button gray btn');
    } elseif($step_id == $step){
      $progress_bar_items[$step_id]['class'] = array('progress-item dexp-shortcodes-button btn');
    } else {
      $progress_bar_items[$step_id]['class'] = array('progress-item dexp-shortcodes-button light-gray btn');
    }
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