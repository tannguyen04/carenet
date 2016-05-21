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
    var url = '/provider-get-data?priority='+data['priority']+'&city='+data['city']+'&state='+data['state']+'&county='+data['county']+'&status='+data['status']+'&date='+data['date'];
    datatable.ajax.url(url).load();
     
    $('#priority').change(function(event) {
      var data = get_value_all();
      var url = '/provider-get-data?priority='+data['priority']+'&city='+data['city']+'&state='+data['state']+'&county='+data['county']+'&status='+data['status']+'&date='+data['date'];
      datatable.ajax.url(url).load();
    });

    $('#date_pick').keyup(function(event) {
      var data = get_value_all();
      var url = '/provider-get-data?priority='+data['priority']+'&city='+data['city']+'&state='+data['state']+'&county='+data['county']+'&status='+data['status']+'&date='+data['date'];
      datatable.ajax.url(url).load();
    });

    $('#city').change(function(event) {
      var data = get_value_all();
      var url = '/provider-get-data?priority='+data['priority']+'&city='+data['city']+'&state='+data['state']+'&county='+data['county']+'&status='+data['status']+'&date='+data['date'];
      datatable.ajax.url(url).load();
      $('#county').prop('disabled', true);
      $.get( "/get_data_county?city="+data['city'], function( data ) {
        $('#county').html(data);
        $('#county').prop('disabled', false);
      });
    });

    $('#state').change(function(event) {
      var data = get_value_all();
      var url = '/provider-get-data?priority='+data['priority']+'&city='+data['city']+'&state='+data['state']+'&county='+data['county']+'&status='+data['status']+'&date='+data['date'];
      datatable.ajax.url(url).load();
      $('#city').prop('disabled', true);
      $.get( "/get_data_city?state="+data['state'], function( data ) {
        $('#city').html(data);
        $('#city').prop('disabled', false);
      });
    });

    $('#county').change(function(event) {
      var data = get_value_all();
      var url = '/provider-get-data?priority='+data['priority']+'&city='+data['city']+'&state='+data['state']+'&county='+data['county']+'&status='+data['status']+'&date='+data['date'];
      datatable.ajax.url(url).load();
    });

    $('#status').change(function(event) {
      var data = get_value_all();
      var url = '/provider-get-data?priority='+data['priority']+'&city='+data['city']+'&state='+data['state']+'&county='+data['county']+'&status='+data['status']+'&date='+data['date'];
      datatable.ajax.url(url).load();

      if($(this).val() == 4851 || $(this).val() == 4850 || $(this).val() == 4920){
        $('.filter_date').css('display','inline-block');
      }else{
        $('.filter_date').css('display','none');
      }

    });

    function get_value_all(){
      var data = [];
      data['priority'] = $('#priority').val();
      data['city'] = $('#city').val();
      data['state'] = $('#state').val();
      data['county'] = $('#county').val();
      data['status'] = $('#status').val();
      data['date'] = $('#date_pick').val();
      return data;
    }

    $('#date_tick').datetimepicker({
       format:'m/d/Y H:i',
       minDate:'-1970/01/02'
    });

  });
}(jQuery));

          