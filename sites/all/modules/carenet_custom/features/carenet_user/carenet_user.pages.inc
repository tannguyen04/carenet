<?php
/*
 * Page callback /admin/carenet-manage
 */
function carenet_manage_page() {
  $items = array(
    l('Manage card rate', 'admin/carenet-manage/card-rate'),
    l('Manage providers', 'admin/carenet-manage/provider'),
  );
  return theme('item_list',array('items' => $items, 'type' => 'ul', 'title' => ''));
}