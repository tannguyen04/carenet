jQuery(document).ready(function($) {

	$('#edit-date-time').datetimepicker({
		 format:'m/d/Y H:i',
		 minDate:'-1970/01/02',
		 timepicker:true,
	});
	
	function hide_all(){
		$('#carenet-custom-provider-action .form-item-reason').hide();
		$('#carenet-custom-provider-action .form-item-date-time').hide();
		$('#carenet-custom-provider-action .form-item-comment').hide();
		$('#carenet-custom-provider-action .form-item-card-rate').hide();
		$('#carenet-custom-provider-action .form-item-method-contact').hide();
		$('#carenet-custom-provider-action .form-item-fax').hide();
		$('#carenet-custom-provider-action .form-item-custom-price').hide();
		$('#carenet-custom-provider-action .form-item-comment').hide();
	}

	var status_id = $('.form-item-status select').val();
	if(status_id == 4848){
		hide_all();
		$('#carenet-custom-provider-action .form-item-reason').show();
	}else if(status_id == 4850 || status_id == 4920){
		hide_all();
		$('#carenet-custom-provider-action .form-item-person').hide();
		$('#carenet-custom-provider-action .form-item-email').hide();
		$('#carenet-custom-provider-action .form-item-phone').hide();
		$('#carenet-custom-provider-action .form-item-designation').hide();

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
	}else if(status_id == 4921){
		hide_all();
		$('#carenet-custom-provider-action .form-item-comment').show();
	}else{
		hide_all();
	}

	// $('#carenet-custom-provider-action .form-item-person').show();
	// $('#carenet-custom-provider-action .form-item-email').show();
	// $('#carenet-custom-provider-action .form-item-phone').show();
	// $('#carenet-custom-provider-action .form-item-designation').show();

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
			$('#carenet-custom-provider-action .form-item-date-time').show();
		}else if($(this).val() == 4919){
			hide_all();
			$('#carenet-custom-provider-action .form-item-card-rate').show();
			$('#carenet-custom-provider-action .form-item-method-contact').show();
		}else if($(this).val() == 4920){
			$('#carenet-custom-provider-action .form-item-date-time').show();
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

	$('#carenet-custom-provider-action .form-item-method-contact input').click(function() {
	   if($('#edit-method-contact-fax').is(':checked')) { 
	   		$('#carenet-custom-provider-action .form-item-fax').show();
	   		$('#carenet-custom-provider-action .form-item-comment').show();	
	   }else{
	   		$('#carenet-custom-provider-action .form-item-fax').hide();
	   }
	});

	if($('#edit-method-contact-fax').is(':checked') && $('#carenet-custom-provider-action .form-item-method-contact').css('display') == 'block') { 
		$('#carenet-custom-provider-action .form-item-fax').show();
		$('#carenet-custom-provider-action .form-item-comment').show();	
	}

	$('#carenet-custom-provider-action .form-item-card-rate select').change(function(event) {
		if($(this).val() != 'All'){
			var price = $('#card_rate_price_'+$(this).val()+' input').val();
			$('#carenet-custom-provider-action .form-item-custom-price').val(price);
			$('#carenet-custom-provider-action .form-item-custom-price').show();
		}else{
			$('#carenet-custom-provider-action .form-item-custom-price').hide();
		}
	});

	var card_rate = $('#carenet-custom-provider-action .form-item-card-rate select').val();
	if(card_rate != 'All' && status_id == 4919){
		var price = $('#card_rate_price_'+$(this).val()+' input').val();
		$('#carenet-custom-provider-action .form-item-custom-price').val(price);
		$('#carenet-custom-provider-action .form-item-custom-price').show();
	}else{
		$('#carenet-custom-provider-action .form-item-custom-price').hide();
	}

});