<?php
/**
 * @file
 * comment_delete.admin.inc
 */

/**
 * Page callback for comment deletion settings form.
 */
function comment_delete_settings_form() {
  $form['comment_delete_default'] = array(
    '#type' => 'radios',
    '#title' => t('Default Delete Option'),
    '#description' => t('Choose which option to use as the selected default when deleting comments.'),
    '#options' => array(
      0 => t('Delete comment and replies'),
      1 => t('Delete comment and move replies'),
      2 => t('Delete comment and keep replies'),
    ),
    '#required' => TRUE,
    '#default_value' => variable_get('comment_delete_default', 0),
  );
  $form['comment_delete_threshold'] = array(
    '#type' => 'textfield',
    '#title' => t('Delete Threshold'),
    '#description' => t('Define allowable comment deletion threshold in seconds.'),
    '#size' => 10,
    '#default_value' => variable_get('comment_delete_threshold', 0),
  );
  return system_settings_form($form);
}

/**
 * Validation callback for comment deletion settings form.
 */
function comment_delete_settings_form_validate($form, &$form_state) {

  // Validate deletion threshold input.
  if (!($form_state['values']['comment_delete_threshold'] > 0)) {
    form_set_error('comment_delete_threshold', t('Threshold must be greater then zero (0).'));
  }
}
