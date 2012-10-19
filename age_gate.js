var AgeGate = {};

(function ($) {
  AgeGate.init = function(context, settings) {
    switch (Drupal.settings.AgeGate.widget) {
      case 'javascript':
        var popup = prompt(Drupal.settings.AgeGate.message, 'mm/dd/yyyy');
        AgeGate.verify(popup);
        return;
        break;

      default:
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
      break;
    }
  }

  AgeGate.verify = function(inputDate) {
    var today = new Date();
    var now = today.getTime();
    var limit = now - (Drupal.settings.AgeGate.minimumAge * 31536000);

    switch (Drupal.settings.AgeGate.widget) {
      case 'javascript':
        if (!inputDate.match(/^[0-9]{2}\/[0-9]{2}\/[0-9]{4}$/)) {
          AgeGate.deny();
        }
        else {
          var birthday = inputDate.split('/');
          var age = new Date(birthday[2], birthday[0], birthday[1]).getTime();
          alert(age);
          if (age > limit) {
            AgeGate.deny();
          }
          else {
            AgeGate.confirm();
          }
        }
        break;
    }
    return false;
  }

  AgeGate.confirm = function() {
    // Set Cookie.
    AgeGate.popup.fadeOut(250);
    AgeGate.overlay.fadeOut(500);
    $.cookie('age_gate', 1, { expires: Drupal.settings.AgeGate.cookieLifespan });
    return false;
  }

  AgeGate.deny = function() {
    // Redirect user elsewhere.
    window.location = Drupal.settings.AgeGate.denyRedirect;
    return false;
  }

  // Attach behaviors to Drupal.
  Drupal.behaviors.AgeGate = {
    attach : AgeGate.init
  }
})(jQuery);
