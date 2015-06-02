<?php

/**
 * @file
 * Provides the admin interface for the Basic Auth module
 */

function basic_auth_admin_form($form, &$form_state) {
  $form['basic_auth_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Basic Auth Enabled'),
    '#description' => t('Unticking this will disabled Basic Auth on the site.'),
    '#default_value' => basic_auth_variable_get('basic_auth_enabled'),
  );

  $form['basic_auth_allow_cli'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow CLI to bypass Basic Auth'),
    '#description' => t('Unticking this will require systems like Drush to need HTTP Auth. Very rare!'),
    '#default_value' => basic_auth_variable_get('basic_auth_allow_cli'),
  );

  $form['basic_auth_role_denied_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Access Denied Message for Roles'),
    '#description' => t('If access is denied due to role, this message is returned in the realm.'),
    '#default_value' => basic_auth_variable_get('basic_auth_role_denied_message'),
  );

  return system_settings_form($form);
}