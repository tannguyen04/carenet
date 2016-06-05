jQuery(document).ready(function($) {

	$('#edit-date-time').datetimepicker({
		 format:'m/d/Y H:i',
		 minDate:'-1970/01/02',
		 timepicker:true,
	});

	
	function hide_all(){
		$('#carenet-custom-provider-action .form-item-designation').hide();
		$('#carenet-custom-provider-action .form-item-date-time').hide();
		$('#carenet-custom-provider-action .form-item-card-rate').hide();
		$('#carenet-custom-provider-action .form-item-custom-price').hide();
		$('#carenet-custom-provider-action .form-item-method-contact').hide();
		$('#carenet-custom-provider-action .form-item-fax').hide();
		$('#carenet-custom-provider-action .form-item-reason').hide();
		$('#carenet-custom-provider-action #card_rate_item_wrapper').hide();
		$('#carenet-custom-provider-action .form-item-fax-number').hide();
		
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
			$('#carenet-custom-provider-action #card_rate_item_wrapper').show();

			if($('#edit-method-contact-fax').is(':checked')){
				$('#carenet-custom-provider-action .form-item-fax').show();
				$('#carenet-custom-provider-action .form-item-fax-number').show();
			}else{
				$('#carenet-custom-provider-action .form-item-fax').hide();
				$('#carenet-custom-provider-action .form-item-fax-number').hide();
			}
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

	

	$('#carenet-custom-provider-action .form-item-status select').change(function(event) {
		var status = $(this).val();
		//Accepted
		status_getshow(status);
	});

	var status = $('#carenet-custom-provider-action .form-item-status select').val();
	console.log(status);
	status_getshow(status);

	$('#edit-method-contact-fax').click(function(event) {
		if($(this).is(':checked')){
				$('#carenet-custom-provider-action .form-item-fax').show();
				$('#carenet-custom-provider-action .form-item-fax-number').show();
		}
	});

	$('#edit-method-contact-mail').click(function(event) {
		$('#carenet-custom-provider-action .form-item-fax').hide();
		$('#carenet-custom-provider-action .form-item-fax-number').hide();
	});

});

function unlock_provider(){
  var r = confirm("Are you sure ?");
  if (r == true) {
  	jQuery(document).ready(function($) {
  		$.ajax({
			  url: "/unlock_provider"
			}).done(function() {
			  //window.location.href = "/providers";
			});
  	});
  }
}