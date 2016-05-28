jQuery(document).ready(function($) {

	$('#edit-date-time').datetimepicker({
		 format:'m/d/Y H:i',
		 minDate:'-1970/01/02',
		 timepicker:true,
	});

	
	function hide_all(){
		$('#carenet-custom-provider-action .form-item-person').hide();
		$('#carenet-custom-provider-action .form-item-title').hide();
		$('#carenet-custom-provider-action .form-item-email').hide();
		$('#carenet-custom-provider-action .form-item-phone').hide();
		$('#carenet-custom-provider-action .form-item-designation').hide();
		$('#carenet-custom-provider-action .form-item-date-time').hide();
		$('#carenet-custom-provider-action .form-item-card-rate').hide();
		$('#carenet-custom-provider-action .form-item-custom-price').hide();
		$('#carenet-custom-provider-action .form-item-method-contact').hide();
		$('#carenet-custom-provider-action .form-item-fax').hide();
		$('#carenet-custom-provider-action .form-item-comment').hide();
		$('#carenet-custom-provider-action .form-item-reason').hide();
		
	}

	function status_getshow(status){
		if(status == 4921){
			hide_all();
			$('#carenet-custom-provider-action .form-item-person').show();
			$('#carenet-custom-provider-action .form-item-title').show();
			$('#carenet-custom-provider-action .form-item-email').show();
			$('#carenet-custom-provider-action .form-item-phone').show();
			$('#carenet-custom-provider-action .form-item-comment').show();
		//CallBack
		}else if(status == 4851){
			hide_all();
			$('#carenet-custom-provider-action .form-item-person').show();
			$('#carenet-custom-provider-action .form-item-title').show();
			$('#carenet-custom-provider-action .form-item-email').show();
			$('#carenet-custom-provider-action .form-item-phone').show();
			$('#carenet-custom-provider-action .form-item-comment').show();
			$('#carenet-custom-provider-action .form-item-date-time').show();
		//Follow up
		}else if(status == 4920){
			hide_all();
			$('#carenet-custom-provider-action .form-item-person').show();
			$('#carenet-custom-provider-action .form-item-title').show();
			$('#carenet-custom-provider-action .form-item-email').show();
			$('#carenet-custom-provider-action .form-item-phone').show();
			$('#carenet-custom-provider-action .form-item-date-time').show();
		//Interested
		}else if(status == 4919){
			hide_all();
			$('#carenet-custom-provider-action .form-item-person').show();
			$('#carenet-custom-provider-action .form-item-title').show();
			$('#carenet-custom-provider-action .form-item-email').show();
			$('#carenet-custom-provider-action .form-item-phone').show();
			$('#carenet-custom-provider-action .form-item-method-contact').show();
			$('#carenet-custom-provider-action .form-item-card-rate').show();
		//Rejected
		}else if(status == 4849){
			hide_all();
			$('#carenet-custom-provider-action .form-item-person').show();
			$('#carenet-custom-provider-action .form-item-title').show();
			$('#carenet-custom-provider-action .form-item-email').show();
			$('#carenet-custom-provider-action .form-item-phone').show();
			$('#carenet-custom-provider-action .form-item-reason').show();
			$('#carenet-custom-provider-action .form-item-comment').show();
			
		//No Response / Voice Message
		}else if(status == 4850){
			hide_all();
			$('#carenet-custom-provider-action .form-item-date-time').show();
		}else{
			hide_all();
		}
	}

	hide_all();

	var status = $('#carenet-custom-provider-action .form-item-status select').val();
	status_getshow(status);

	$('#carenet-custom-provider-action .form-item-status select').change(function(event) {
		var status = $(this).val();
		//Accepted
		status_getshow(status);
	});

});