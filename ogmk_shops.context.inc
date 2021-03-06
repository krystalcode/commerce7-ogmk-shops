<?php

/**
 * @file
 * ogmk_shops.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ogmk_shops_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ogmk_shop_manage';
  $context->description = '';
  $context->tag = 'ogmk-shop';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ogmk_product' => 'ogmk_product',
        'ogmk_shop' => 'ogmk_shop',
      ),
      'options' => array(
        'node_form' => '2',
      ),
    ),
    'path' => array(
      'values' => array(
        'node/*/manage' => 'node/*/manage',
        'node/*/manage/*' => 'node/*/manage/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-ogmk-shop-manage' => array(
          'module' => 'menu',
          'delta' => 'ogmk-shop-manage',
          'region' => 'navigation',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('ogmk-shop');
  $export['ogmk_shop_manage'] = $context;

  return $export;
}
