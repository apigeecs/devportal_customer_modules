<?php
/**
 * @file
 * Allows administration of canonical hostname settings.
 */

/**
 * Creates the settings form for this module.
 *
 * @return array
 *   The fully-constructed admin form.
 */
function canonical_hostname_tokens_admin_form() {
  $form['canonical_hostname_tokens_hostname'] = array(
    '#type' => 'textfield',
    '#title' => t('Hostname'),
    '#description' => t('This hostname will be substituted in all URL tokens. Do not include scheme or path.'),
    '#maxlength' => 64,
    '#required' => TRUE,
    '#default_value' => variable_get('canonical_hostname_tokens_hostname', NULL),
  );
  $form['canonical_hostname_tokens_enforce_https'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enforce https for all URL tokens'),
    '#default_value' => variable_get('canonical_hostname_tokens_enforce_https', FALSE),
  );
  return system_settings_form($form);
}
