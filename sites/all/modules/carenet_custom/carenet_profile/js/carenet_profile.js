/**
 * Created by Trang on 07/06/2016.
 */
(function ($) {
console.log('test');
    if (document.getElementById('edit-profile-main-field-prostaff-license-und-3').checked) {
        console.log("checked");
    } else {
        $('#edit-profile-main-field-prostaff-license-other').hide();
    }
}(jQuery));
