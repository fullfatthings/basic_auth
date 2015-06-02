<?php

/**
 * @file
 * Provides the admin interface for the Basic Auth module
 */


/**
 * Basic Auth Admin Form.
 *
 * Lets users configure the Basic Auth settings.
 *
 * @param array $form
 *   Initialised Form from Drupal
 * @param array $form_state
 *   Form State passed to the form
 *
 * @return mixed
 *   The form with all elements populated
 */
function basic_auth_admin_form($form, &$form_state) {
  $form['basic_auth_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Basic Auth enabled'),
    '#description' => t('Unticking this will disabled Basic Auth on the site.'),
    '#default_value' => basic_auth_variable_get('basic_auth_enabled'),
  );

  $form['basic_auth_allow_cli'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow CLI to bypass Basic Auth'),
    '#description' => t('Unticking this will require systems like Drush to need HTTP Auth. Very rare!'),
    '#default_value' => basic_auth_variable_get('basic_auth_allow_cli'),
  );

  $form['basic_auth_allow_anonymous'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow anonymous visitors'),
    '#description' => t('When ticked, anonymous users can access the site. Basic Auth will be accepted if provided in the header to authorize.'),
    '#default_value' => basic_auth_variable_get('basic_auth_allow_anonymous'),
  );

  $form['basic_auth_enable_force_login_path'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable force login path'),
    '#description' => t('When ticked, a !path path will be provided to force HTTP Auth on.', array('!path' => l('/basicauth', 'basicauth'))),
    '#default_value' => basic_auth_variable_get('basic_auth_enable_force_login_path'),
  );

  $form['basic_auth_trigger_on_access_denied'] = array(
    '#type' => 'checkbox',
    '#title' => t('Trigger on access denied pages'),
    '#description' => t('If checked, any anonymous attempt to get to an access denied page will cause a basic auth prompt.'),
    '#default_value' => basic_auth_variable_get('basic_auth_trigger_on_access_denied'),
  );

  $form['basic_auth_realm'] = array(
    '#type' => 'textfield',
    '#title' => t('Basic Auth Realm'),
    '#description' => t('The default realm to show the user when prompted for login.'),
    '#default_value' => basic_auth_variable_get('basic_auth_realm'),
  );

  return system_settings_form($form);
}
