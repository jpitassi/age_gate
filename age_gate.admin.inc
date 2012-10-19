<?php

/**
 * @file
 * Admin functionality for age_gate module.
 */

/**
 * Form callback for age_gate admin settings.
 */
function age_gate_admin_form() {
  // Message options for age gate.
  $form['message'] = array(
    '#title' => t('Age Gate Message'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['message']['age_gate_header'] = array(
    '#title' => t('Popup Header'),
    '#type' => 'textfield',
    '#default_value' => variable_get('age_gate_header', t('Please verify your age')),
    '#description' => t("A short message to display in the header of the age gate popup (leave blank for no header)."),
  );

  $message = variable_get('age_gate_message', array('value' => '', 'format' => NULL));
  $form['message']['age_gate_message'] = array(
    '#title' => t('Popup Message'),
    '#type' => 'text_format',
    '#rows' => 6,
    '#default_value' => $message['value'],
    '#description' => t('The message displayed to the user, explaining the terms of the age verification.'),
    '#format' => $message['format'],
  );

  // Verification options for age gate.
  $form['options'] = array(
    '#title' => t('Age Gate Options'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['options']['age_gate_minimum_age'] = array(
    '#title' => t('Minimum Age'),
    '#type' => 'textfield',
    '#size' => 3,
    '#default_value' => variable_get('age_gate_minimum_age', 18),
    '#description' => t('The minimum age a user can be to pass the age gate.'),
  );

  $form['options']['age_gate_use_overlay'] = array(
    '#title' => t('Use overlay to hide content?'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('age_gate_use_overlay', TRUE),
    '#description' => t('If checked, an overlay will be used to hide site content until age verification has been established.'),
  );

  $form['options']['age_gate_cookie_lifespan'] = array(
    '#title' => t('Cookie Lifespan'),
    '#type' => 'textfield',
    '#field_suffix' => t('Days'),
    '#size' => 6,
    '#default_value' => variable_get('age_gate_cookie_lifespan', 0),
    '#description' => t('The number of days before the cookie set by age gate module expires, and the user must verify their age again (0 days will expire at end of session).'),
  );

  $form['options']['age_gate_deny_redirect'] = array(
    '#title' => t('Redirect URL'),
    '#type' => 'textfield',
    '#default_value' => variable_get('age_gate_deny_redirect', '/'),
    '#description' => t('The URL to redirect the user to if their age verification fails.'),
  );

  $form['options']['age_gate_widget'] = array(
    '#title' => t('Age Gate Widget'),
    '#type' => 'select',
    '#options' => array(
      'boolean' => t('Yes/No Buttons'),
      //'dateselect' => t('Date Dropdown Selector'),
      //'datepicker' => t('jQuery Datepicker'),
      //'javascript' => t('Javascript Confirm Box'),
    ),
    '#default_value' => variable_get('age_gate_widget', 'boolean'),
    '#description' => t('The type of age verification the user must complete in order to pass the age gate.'),
  );

  $form['options']['age_gate_visibility'] = array(
    '#type' => 'radios',
    '#title' => t('Display an Age Gate on:'),
    '#options' => array(
      AGE_GATE_VISIBILITY_NOTLISTED => t('All pages except those listed'),
      AGE_GATE_VISIBILITY_LISTED => t('Only the listed pages'),
    ),
    '#default_value' => variable_get('age_gate_visibility', AGE_GATE_VISIBILITY_NOTLISTED),
  );

  $form['options']['age_gate_pages'] = array(
    '#type' => 'textarea',
    '#title' => t('Pages'),
    '#default_value' => variable_get('age_gate_pages', ''),
    '#description' => t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are blog for the blog page and blog/* for every personal blog. <front> is the front page."),
  );

  $form['options']['age_gate_content_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content Types'),
    '#options' => node_type_get_names(),
    '#default_value' => variable_get('age_gate_content_types', array()),
    '#description' => t('Show the age gate only on nodes of the given type(s). If you select no types, there will be no type-specific limitation.'),
  );

  return system_settings_form($form);
}
