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
		$('#carenet-custom-provider-action .form-item-email-sent').hide();
		$('#carenet-custom-provider-action .form-item-card-rate').hide();
		$('#carenet-custom-provider-action .form-item-method-contact').hide();
		$('#carenet-custom-provider-action .form-item-fax').hide();
		
	}

	var status_id = $('.form-item-status select').val();
	if(status_id == 4848){
		hide_all();
		$('#carenet-custom-provider-action .form-item-reason').show();
	}else if(status_id == 4850){
		hide_all();
		$('#carenet-custom-provider-action .form-item-date-time').show();
	}else if(status_id == 4851){
		hide_all();
		$('#carenet-custom-provider-action .form-item-person').show();
		$('#carenet-custom-provider-action .form-item-email').show();
		$('#carenet-custom-provider-action .form-item-phone').show();
		$('#carenet-custom-provider-action .form-item-designation').show();
		$('#carenet-custom-provider-action .form-item-date-time').show();
	}else if(status_id == 4919){
		hide_all();
		$('#carenet-custom-provider-action .form-item-card-rate').show();
		$('#carenet-custom-provider-action .form-item-method-contact').show();
		$('#carenet-custom-provider-action .form-item-email-sent').show();
	}else{
		hide_all();
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
		}else if($(this).val() == 4919){
			hide_all();
			$('#carenet-custom-provider-action .form-item-card-rate').show();
			$('#carenet-custom-provider-action .form-item-method-contact').show();
			$('#carenet-custom-provider-action .form-item-email-sent').show();
		}else{
			hide_all();
		}

	});

	

	$('#carenet-custom-provider-action .form-item-reason select').change(function(event) {
		if($(this).val() == 4918){
			hide_all();
			$('#carenet-custom-provider-action .form-item-reason').show();
			$('#carenet-custom-provider-action .form-item-comment').show();	
		}else{
			hide_all();
			$('#carenet-custom-provider-action .form-item-reason').show();
		}
	});

	var reason = $('#carenet-custom-provider-action .form-item-reason select').val();
	if(reason == 4918){
			$('#carenet-custom-provider-action .form-item-reason').show();
			$('#carenet-custom-provider-action .form-item-comment').show();	
	}

	$('#carenet-custom-provider-action .form-item-method-contact select').change(function(event) {
		if($(this).val() == 'fax'){
			hide_all();
			$('#carenet-custom-provider-action .form-item-card-rate').show();
			$('#carenet-custom-provider-action .form-item-method-contact').show();
			$('#carenet-custom-provider-action .form-item-fax').show();
		}else{
			hide_all();
			$('#carenet-custom-provider-action .form-item-card-rate').show();
			$('#carenet-custom-provider-action .form-item-method-contact').show();
			$('#carenet-custom-provider-action .form-item-email-sent').show();
		}
	});

	var method_contact = $('#carenet-custom-provider-action .form-item-method-contact select').val();
	if(method_contact == 'fax'){
		$('#carenet-custom-provider-action .form-item-email-sent').hide();
		$('#carenet-custom-provider-action .form-item-fax').show();
	}

});