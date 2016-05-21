jQuery(document).ready(function($) {

	//$('.form-item-date-time input').datetimepicker();

	
	
	function hide_all(){
		$('#carenet-custom-provider-action .form-item-reason').hide();
		$('#carenet-custom-provider-action .form-item-person').hide();
		$('#carenet-custom-provider-action .form-item-email').hide();
		$('#carenet-custom-provider-action .form-item-phone').hide();
		$('#carenet-custom-provider-action .form-item-designation').hide();
		$('#carenet-custom-provider-action .form-item-date-time').hide();
		$('#carenet-custom-provider-action .form-item-comment').hide();
	}

	$('.form-item-status select').change(function(event) {
		/* Act on the event */
		if($(this).val() == 4848){
			hide_all();
			$('#carenet-custom-provider-action .form-item-reason').show();
		}else if($(this).val() == 4850){
			hide_all();
			$('#carenet-custom-provider-action .form-item-date-time').show();
		}else if($(this).val() == 4851){
			hide_all();
			$('#carenet-custom-provider-action .form-item-person').show();
			$('#carenet-custom-provider-action .form-item-email').show();
			$('#carenet-custom-provider-action .form-item-phone').show();
			$('#carenet-custom-provider-action .form-item-designation').show();
			$('#carenet-custom-provider-action .form-item-date-time').show();
		}else{
			hide_all();
		}

	});

	$('#carenet-custom-provider-action .form-item-reason').change(function(event) {
		if($(this).val() == 4918){
			$('#carenet-custom-provider-action .form-item-comment').show();	
		}else{
			$('#carenet-custom-provider-action .form-item-comment').hide();
		}
	});

});