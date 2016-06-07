/**
 * Created by Trang on 07/06/2016.
 */
(function ($) {
console.log('test');
    $('#edit-sign').click(function(e){
        e.preventDefault();
        $('#edit-profile-main-field-profile-sign-und-0-value').val(1);
        document.getElementById("user-profile-form").submit();
    });
    //if (document.getElementById('edit-profile-main-field-prostaff-license-und-3').checked) {
    if (document.getElementById('edit-profile-main-field-prostaff-license-und-3').is(':checked')) {
        console.log("checked");
    } else {
        $('#edit-profile-main-field-prostaff-license-other').hide();
    }
}(jQuery));
