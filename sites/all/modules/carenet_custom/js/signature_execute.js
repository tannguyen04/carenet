(function ($) {
    Drupal.behaviors.signature_execute = {
        attach: function (context, settings) {
            $('#show-accept').click(function() {
                $('.signature-execute-accept').removeClass('element-invisible');
                $('.signature-execute-ask-question').addClass('element-invisible');
                $('#show-ask-question').removeClass('active');
                $(this).addClass('active');
            });
            $('#show-ask-question').click(function() {
                $('.signature-execute-accept').addClass('element-invisible');
                $('.signature-execute-ask-question').removeClass('element-invisible');
                $('#show-accept').removeClass('active');
                $(this).addClass('active');
            });
        }
    };
}(jQuery));