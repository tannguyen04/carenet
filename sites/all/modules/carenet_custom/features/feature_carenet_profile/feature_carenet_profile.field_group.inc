<?php
/**
 * @file
 * feature_carenet_profile.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feature_carenet_profile_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_attestation_questions|profile2|main|form';
  $field_group->group_name = 'group_attestation_questions';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_facilityinfo';
  $field_group->data = array(
    'label' => 'Attestation Questions',
    'weight' => '28',
    'children' => array(
      0 => 'field_profile_osha_regulations',
      1 => 'field_profile_ada_standard',
      2 => 'field_profile_wheelchair',
      3 => 'field_profile_elevator_access',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Attestation Questions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group_attestation_questions group_profile clearfix',
        'description' => 'If you answer “YES” to any of the following questions, please include a typed explanation on an additional sheet of paper. Please include details of the violation, location, date, and disposition. Please also explain any liability claims owed or pending for malpractice.',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_attestation_questions|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_experience_certifications|profile2|main|form';
  $field_group->group_name = 'group_experience_certifications';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_prostaff';
  $field_group->data = array(
    'label' => 'Experience and Certifications',
    'weight' => '79',
    'children' => array(
      0 => 'field_prostaff_prev_experience',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Experience and Certifications',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group_profile clearfix',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_experience_certifications|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_facility_capabilities|profile2|main|form';
  $field_group->group_name = 'group_facility_capabilities';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_facilityinfo';
  $field_group->data = array(
    'label' => 'Facility Capabilities',
    'weight' => '27',
    'children' => array(
      0 => 'field_profile_facility_cap',
      1 => 'field_profile_audiology',
      2 => 'field_profile_ansi_standards',
      3 => 'field_profile_whois',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Facility Capabilities',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group_facility_capabilities group_profile clearfix',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_facility_capabilities|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_facility_general|profile2|main|form';
  $field_group->group_name = 'group_facility_general';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_facilityinfo';
  $field_group->data = array(
    'label' => 'General Information',
    'weight' => '25',
    'children' => array(
      0 => 'field_profile_internet_security',
      1 => 'field_profile_doc_electron',
      2 => 'field_profile_os',
      3 => 'field_profile_specify',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'General Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'service_general_info group_profile clearfix',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_facility_general|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hour_operation|profile2|main|form';
  $field_group->group_name = 'group_hour_operation';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_facilityinfo';
  $field_group->data = array(
    'label' => 'Hours of Operation',
    'weight' => '26',
    'children' => array(
      0 => 'field_profile_mon_fri',
      1 => 'field_profile_sat',
      2 => 'field_profile_sun',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Hours of Operation',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group_hour_operation group_profile clearfix',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_hour_operation|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page1|profile2|main|form';
  $field_group->group_name = 'group_page1';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_profile';
  $field_group->data = array(
    'label' => 'Operations Staff',
    'weight' => '18',
    'children' => array(
      0 => 'field_adminstaff',
      1 => 'field_clinical_support_staff',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Operations Staff',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_page1|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prostaff_attestation_ques|profile2|main|form';
  $field_group->group_name = 'group_prostaff_attestation_ques';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_prostaff';
  $field_group->data = array(
    'label' => 'Attestation Questions',
    'weight' => '78',
    'children' => array(
      0 => 'field_prostaff_current_state',
      1 => 'field_prostaff_denied_license',
      2 => 'field_prostaff_malpractice',
      3 => 'field_prostaff_convicted',
      4 => 'field_prostaff_being_treated',
      5 => 'field_prostaff_convictedof',
      6 => 'field_prostaff_exclude',
      7 => 'field_prostaff_federal_federally',
      8 => 'field_prostaff_medicare',
      9 => 'field_prostaf_federal_government',
      10 => 'field_prostaff_part_or_fulltime',
      11 => 'field_prostaff_medicaid',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Attestation Questions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'group_prostaff_attestation_ques',
        'classes' => 'group_profile clearfix',
        'description' => 'If you answer “YES” to any of the following questions, please include a typed explanation on an additional sheet of paper. Please include details of the violation, location, date, and disposition. Please also explain any liability claims owed or pending for malpractice.',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_prostaff_attestation_ques|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prostaff_info|profile2|main|form';
  $field_group->group_name = 'group_prostaff_info';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_prostaff';
  $field_group->data = array(
    'label' => 'Professional staff',
    'weight' => '76',
    'children' => array(
      0 => 'field_prostaff_first_name',
      1 => 'field_prostaff_last_name',
      2 => 'field_prostaff_dob',
      3 => 'field_prostaff_npi_number',
      4 => 'field_profile_email',
      5 => 'field_prostaff_primary_office',
      6 => 'field_prostaff_license',
      7 => 'field_prostaff_license_number',
      8 => 'field_prostaff_license_state',
      9 => 'field_prostaff_board_certified',
      10 => 'field_prostaff_veteran',
      11 => 'field_prostaff_languages_spoken',
      12 => 'field_if_yes',
      13 => 'field_prostaff_boardcert_spec',
      14 => 'field_prostaff_license_other',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Professional staff',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group_profile clearfix',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_prostaff_info|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prostaff_multistate|profile2|main|form';
  $field_group->group_name = 'group_prostaff_multistate';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_prostaff';
  $field_group->data = array(
    'label' => 'Multi-state License Questions',
    'weight' => '77',
    'children' => array(
      0 => 'field_prostaff_traveling',
      1 => 'field_prostaff_state',
      2 => 'field_prostaff_currently_maintai',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Multi-state License Questions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group_profile clearfix',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_prostaff_multistate|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_businessinfo|profile2|main|form';
  $field_group->group_name = 'group_user_businessinfo';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_profile';
  $field_group->data = array(
    'label' => ' Business Information',
    'weight' => '17',
    'children' => array(
      0 => 'field_business_information',
      1 => 'field_business_administrator',
      2 => 'field_business_classification',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_user_businessinfo|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_facilityinfo|profile2|main|form';
  $field_group->group_name = 'group_user_facilityinfo';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_profile';
  $field_group->data = array(
    'label' => 'Service Facility Information',
    'weight' => '20',
    'children' => array(
      0 => 'field_facility_location',
      1 => 'field_office_administrator',
      2 => 'group_facility_general',
      3 => 'group_hour_operation',
      4 => 'group_facility_capabilities',
      5 => 'group_attestation_questions',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_user_facilityinfo|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_profile|profile2|main|form';
  $field_group->group_name = 'group_user_profile';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Profiles',
    'weight' => '0',
    'children' => array(
      0 => 'group_user_businessinfo',
      1 => 'group_user_prostaff',
      2 => 'group_user_facilityinfo',
      3 => 'group_page1',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_user_profile|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_prostaff|profile2|main|form';
  $field_group->group_name = 'group_user_prostaff';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_profile';
  $field_group->data = array(
    'label' => 'Professional Staff Questionnaire',
    'weight' => '19',
    'children' => array(
      0 => 'field_professional_staff',
      1 => 'group_prostaff_multistate',
      2 => 'group_prostaff_attestation_ques',
      3 => 'group_experience_certifications',
      4 => 'group_prostaff_info',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_user_prostaff|profile2|main|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t(' Business Information');
  t('Attestation Questions');
  t('Experience and Certifications');
  t('Facility Capabilities');
  t('General Information');
  t('Hours of Operation');
  t('Multi-state License Questions');
  t('Operations Staff');
  t('Professional Staff Questionnaire');
  t('Professional staff');
  t('Profiles');
  t('Service Facility Information');

  return $field_groups;
}
