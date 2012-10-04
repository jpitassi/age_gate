<?php

/**
 * @file
 * Default template file for age gate popup.
 *
 * Available variables:
 * - $header: The header text to output in the popup.
 * - $message: The age verificatio message to display to the user.
 * - $widget: The age verification widget.
 */
?>

<div id="age_gate_verification_popup">
  <?php if ($header): ?>
    <div id="age_gate_header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>
  <div id="age_gate_message">
    <?php print $message; ?>
  </div>
  <div id="age_gate_widget">
    <?php print $widget; ?>
  </div>
</div>
