/**
 * Created by Trang on 07/06/2016.
 */
(function ($) {
console.log('test');
    Drupal.behaviors.carenet_profile = {
        attach: function (context, settings) {
            console.log(context);
            console.log(settings);
            //disable form
            var disable = $('#edit-profile-main-field-profile-sign-und-0-value').val();
            if (disable == 1) {
                $('#user-profile-form').find('input').attr('disabled', true);
            }

            //confirm sign button
            var events = $('#edit-sign').data('events'); // Get the jQuery events.
            $('#edit-sign').unbind('click'); // Remove the click events.
            $('#edit-sign').click(function () {
                console.log('.form-submit');
                if (confirm('Are you sure you want to sign that?')) {
                    $.each(events.click, function() {
                        this.handler(); // Invoke the click handlers that was removed.
                    });
                }
                // Prevent default action.
                return false;
            });

            //confirm sign button
            var events = $('#field-professional-staff-values .form-submit').data('events'); // Get the jQuery events.
            $('#field-professional-staff-values .form-submit').unbind('click'); // Remove the click events.
            $('#field-professional-staff-values .form-submit').click(function () {
                console.log('.form-submit');
                if (confirm('Are you sure you want to sign that?')) {
                    $.each(events.click, function() {
                        this.handler(); // Invoke the click handlers that was removed.
                    });
                }
                // Prevent default action.
                return false;
            });
            /*
            $('#edit-profile-main-field-prostaff-license-other-und-0-value').click(function() {
                console.log('field-professional-staff-values .ajax-processed');
            });*/

        }
    };

    $('#edit-sign').click(function(e){
        console.log('edit-sign');
        //e.preventDefault();
        if (e.originalEvent.defaultPrevented) return;
        $('#edit-profile-main-field-profile-sign-und-0-value').val(1);
        document.getElementById("user-profile-form").submit();
    });
    $('.form-item-profile-main-field-prostaff-license-und-3').click(function(e){
        console.log('edit-profile-main-field-prostaff-license-und-3');
        $('#edit-profile-main-field-prostaff-license-other').hide();
    });
    /*
    console.log(document.getElementById('edit-profile-main-field-prostaff-license-und-3').checked);
    if (document.getElementById('edit-profile-main-field-prostaff-license-und-3').checked) {
    //if (document.getElementById('edit-profile-main-field-prostaff-license-und-3').is(':checked')) {
        console.log("checked");
    } else {
        $('#edit-profile-main-field-prostaff-license-other').hide();
    }*/
}(jQuery));
