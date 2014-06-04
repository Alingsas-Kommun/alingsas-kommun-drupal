<?php
/**
 * @file
 * alingsasintra_texteditor.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function alingsasintra_texteditor_filter_default_formats() {
  $formats = array();

  // Exported format: html.
  $formats['html'] = array(
    'format' => 'html',
    'name' => 'html',
    'cache' => '1',
    'status' => '1',
    'weight' => '0',
    'filters' => array(
      'filter_html' => array(
        'weight' => '-10',
        'status' => '1',
        'settings' => array(
          'allowed_html' => '<p> <a> <h2> <h3> <h4> <h5> <img> <ul> <ol> <li> <strong> <b> <i> <br> <div><table> <tr> <td> <th> <thead> <tbody>',
          'filter_html_help' => 0,
          'filter_html_nofollow' => 0,
        ),
      ),
    ),
  );

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => '1',
    'status' => '1',
    'weight' => '10',
    'filters' => array(
      'filter_html' => array(
        'weight' => '-10',
        'status' => '1',
        'settings' => array(
          'allowed_html' => '<br> <p>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_url' => array(
        'weight' => '1',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => '72',
        ),
      ),
      'filter_autop' => array(
        'weight' => '2',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
