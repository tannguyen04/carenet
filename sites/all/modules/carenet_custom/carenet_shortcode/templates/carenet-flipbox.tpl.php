<?php
if (strtolower(trim($type)) == 'icon') {
  $place_holder = '<i class="'.$icon.'">&nbsp;</i>';
}
if (strtolower(trim($type)) == 'img') {
  $place_holder = '<img alt="" src="'.$image.'">';
}
?>

<div class="services-box services-box-animated">
  <div class="inner">
    <div class="front"> <?php print $place_holder;?>
      <h3><?php print $front_title;?></h3>
      <p><?php print $front_content ?></p>
    </div>
    <div class="back">
      <h3><?php print $back_title;?></h3>
      <p><?php print $back_content;?></p>
    </div>
  </div>
</div>
