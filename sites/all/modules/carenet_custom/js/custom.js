(function ($) {
  $( document ).ready(function() {
  	var fields = JSON.parse(Drupal.settings.carenet_custom_list_data_fields);
  	var datatable = $('#carenet_custom_list_data').DataTable( {
        dom: "Bfrtip",
        ajax: {
            url: "/provider-get-data",
            type: "POST"
        },
        serverSide: true,
        processing: true,
        columns: fields,
        select: true,
        
    } );

    var data = get_value_all();
    var url = '/provider-get-data?npi='+data['npi']+'&city='+data['city']+'&state='+data['state']+'&county='+data['county']+'&status='+data['status'];
    datatable.ajax.url(url).load();
     
    $('#npi').keyup(function(event) {
      var data = get_value_all();
      var url = '/provider-get-data?npi='+data['npi']+'&city='+data['city']+'&state='+data['state']+'&county='+data['county']+'&status='+data['status'];
      datatable.ajax.url(url).load();
    });

    $('#city').change(function(event) {
      var data = get_value_all();
      var url = '/provider-get-data?npi='+data['npi']+'&city='+data['city']+'&state='+data['state']+'&county='+data['county']+'&status='+data['status'];
      datatable.ajax.url(url).load();
      $.get( "/get_data_county?city="+data['city'], function( data ) {
        $('#city').html(data);
      });
    });

    $('#state').change(function(event) {
      var data = get_value_all();
      var url = '/provider-get-data?npi='+data['npi']+'&city='+data['city']+'&state='+data['state']+'&county='+data['county']+'&status='+data['status'];
      datatable.ajax.url(url).load();
      $.get( "/get_data_city?state="+data['state'], function( data ) {
        $('#city').html(data);
      });
    });

    $('#county').change(function(event) {
      var data = get_value_all();
      var url = '/provider-get-data?npi='+data['npi']+'&city='+data['city']+'&state='+data['state']+'&county='+data['county']+'&status='+data['status'];
      datatable.ajax.url(url).load();
    });

    $('#status').change(function(event) {
      var data = get_value_all();
      var url = '/provider-get-data?npi='+data['npi']+'&city='+data['city']+'&state='+data['state']+'&county='+data['county']+'&status='+data['status'];
      datatable.ajax.url(url).load();
    });

    function get_value_all(){
      var data = [];
      data['npi'] = $('#npi').val();
      data['city'] = $('#city').val();
      data['state'] = $('#state').val();
      data['county'] = $('#county').val();
      data['status'] = $('#status').val();
      return data;
    }

  });
}(jQuery));

          