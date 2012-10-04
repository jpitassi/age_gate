var AgeGate = {};

(function ($) {
  AgeGate.init = function(context, settings) {
    switch (Drupal.settings.AgeGate.widget) {
      case 'boolean':
        break;

      case 'javascript':
        var popup = prompt(Drupal.settings.AgeGate.message, 'mm/dd/yyyy');
        console.log(popup);
        return;
        break;
    }

    return;

    AgeGate.overlay = $('<div id="age_gate_overlay"></div>');
    AgeGate.popup = $('#age_gate_verification_popup');
    var popup_width = AgeGate.popup.css('width').split('px')[0];
    var popup_height = AgeGate.popup.css('height').split('px')[0];

    AgeGate.popup.css('left', '50%');
    AgeGate.popup.css('top', '50%');
    AgeGate.popup.css('margin-left', '-' + (popup_width / 2) + 'px');
    AgeGate.popup.css('margin-top', '-' + (popup_height / 2) + 'px');

    if (Drupal.settings.AgeGate.useOverlay) {
      $('body').append(AgeGate.overlay);
      AgeGate.overlay.fadeIn(500, function() {
        AgeGate.popup.fadeIn(250);
      });
    }
    else {
      AgeGate.popup.fadeIn(500);
    }
  }

  AgeGate.verify = function() {
    switch (Drupal.settings.AgeGate.widget) {
      case 'boolean':
        break;
    }
    AgeGate.popup.fadeOut(250);
    AgeGate.overlay.fadeOut(500);
    return false;
  }

  AgeGate.confirm = function() {
    // Set Cookie.
    AgeGate.popup.fadeOut(250);
    AgeGate.overlay.fadeOut(500);
    return false;
  }

  AgeGate.deny = function() {
    // Redirect user elsewhere.
  }

  // Attach behaviors to Drupal.
  Drupal.behaviors.AgeGate = {
    attach : AgeGate.init
  }
})(jQuery);
