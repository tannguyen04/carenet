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

/*
 * Page callback user/%/edit/card-rate
 */
function carenet_card_rate_user($account) {
  $account_wrapper = entity_metadata_wrapper('user', $account);
  $card_rate = $account_wrapper->field_card_rate_ref->value();
  $card_rate_wrapper = entity_metadata_wrapper('node', $card_rate);
  if ($card_rate) {
    $header = array(
      t('Line item'),
      t('Description'),
      t('Price (USD)'),
    );
    $rows = array();
    //Title card rate
    $title = $card_rate_wrapper->title->value();
    $rows[] = array('', array('data' => $title, 'class' => 'label-card-rate'), '');
    //Description card rate
    $description = $card_rate_wrapper->body->value->value();
    if (!empty($description)) {
      $rows[] = array('', array('data' => $description, 'class' => 'description-card-rate'), '');
    }
    //Line item card rate
    $line_items = $card_rate_wrapper->field_card_rate_item->value();
    if (!empty($line_items)) {
      foreach ($line_items as $key => $item) {
        $collection_wrapper = entity_metadata_wrapper('field_collection_item', $item);
        $label = $collection_wrapper->field_text_title->value();
        $price = $collection_wrapper->field_price->value();
        $rows[] = array(
          $key+1,
          $label,
          '$ '. $price,
        );
      }
    }

    $build['rate_card'] = array(
      '#theme' => 'table',
      '#header' => $header,
      '#rows' => $rows,
      '#attributes' => array(
        'class' => array('table table-hover table-bordered')
      ),
    );
    return $build;
  }
  return t('You do not have any card rate');
}