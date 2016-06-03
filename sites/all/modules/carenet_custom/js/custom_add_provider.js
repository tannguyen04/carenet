jQuery(document).ready(function($) {
	$('.form-item-field-pv-state-und select').change(function(event) {
		$('.form-item-field-pv-city-und select').prop('disabled', true);
		$.get( "/get_data_city?state="+$(this).val(), function( data ) {
      $('.form-item-field-pv-city-und select').html(data);
      $('.form-item-field-pv-city-und select').prop('disabled', false);
    });
	});

	$('.form-item-field-pv-city-und select').change(function(event) {
		$('.form-item-field-pv-county-und select').prop('disabled', true);
		$.get( "/get_data_county?city="+$(this).val(), function( data ) {
      $('.form-item-field-pv-county-und select').html(data);
      $('.form-item-field-pv-county-und select').prop('disabled', false);
    });
	});

});