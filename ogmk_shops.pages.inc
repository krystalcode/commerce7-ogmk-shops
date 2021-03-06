<?php

/**
 * @file
 * Page callback file for the ogmk_shops module.
 */

/**
 * Page callback for the shop management page.
 *
 * @param object $shop
 *   The shop for which to display the management page.
 */
function _ogmk_shops_shop_manage_page($shop) {
  drupal_set_title('Shop Management');

  $shopTeaser = node_view($shop, 'ogmk_manage_teaser');
  $pendingOrdersBlock = views_embed_view('ogmk_shop_manage_orders', 'block', $shop->nid);

  /**
   * @Issue(
   *   "Implement and display a 'Revenue this month' block"
   *   type="feature"
   *   priority="normal"
   * )
   */

  return theme('shop_manage_page', array(
      'shop_teaser' => $shopTeaser,
      'pending_orders_block' => $pendingOrdersBlock,
  ));
}

/**
 * Page callback for menu placeholder page.
 */
function _ogmk_shops_placeholder_page() {
  drupal_goto('/');
}
