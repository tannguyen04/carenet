jQuery(document).ready(function($) {
	$('.form-item-field-pv-state-und select').change(function(event) {

		$('.form-item-field-pv-county-und select').prop('disabled', true);
		$('.form-item-field-pv-city-und select').prop('disabled', true);
		
		$.get( "/get_data_county?state="+$(this).val(), function( data ) {
      $('.form-item-field-pv-county-und select').html(data);
      $('.form-item-field-pv-county-und select').prop('disabled', false);
    });
	});

	$('.form-item-field-pv-county-und select').change(function(event) {
		$('.form-item-field-pv-city-und select').prop('disabled', true);
		$.get( "/get_data_city?county="+$(this).val(), function( data ) {
      $('.form-item-field-pv-city-und select').html(data);
      $('.form-item-field-pv-city-und select').prop('disabled', false);
    });
	});

});