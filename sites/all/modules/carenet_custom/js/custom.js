(function ($) {
  $( document ).ready(function() {

    var data = get_value_all();
    var url = '/provider-get-data?priority='+data['priority']+'&city='+data['city']+'&state='+data['state']+'&county='+data['county']+'&status='+data['status']+'&hpt='+data['hpt']+'&my_quee='+data['my_quee'];
  	var fields = JSON.parse(Drupal.settings.carenet_custom_list_data_fields);
  	var datatable = $('#carenet_custom_list_data').DataTable( {
        dom: "Bfrtip",
        ajax: {
            url: url,
            type: "POST"
        },
        serverSide: true,
        processing: true,
        columns: fields,
        select: true,
        
    } );

    
    //datatable.ajax.url(url).load();
     
    $('#priority').change(function(event) {
      var data = get_value_all();
      var url = '/provider-get-data?priority='+data['priority']+'&city='+data['city']+'&state='+data['state']+'&county='+data['county']+'&status='+data['status']+'&date='+data['date']+'&hpt='+data['hpt']+'&my_quee='+data['my_quee'];
      datatable.ajax.url(url).load();
    });

    $('#city').change(function(event) {
      var data = get_value_all();
      var url = '/provider-get-data?priority='+data['priority']+'&city='+data['city']+'&state='+data['state']+'&county='+data['county']+'&status='+data['status']+'&date='+data['date']+'&hpt='+data['hpt']+'&my_quee='+data['my_quee'];
      datatable.ajax.url(url).load();
      
    });

    $('#hpt').change(function(event) {
      var data = get_value_all();
      var url = '/provider-get-data?priority='+data['priority']+'&city='+data['city']+'&state='+data['state']+'&county='+data['county']+'&status='+data['status']+'&date='+data['date']+'&hpt='+data['hpt']+'&my_quee='+data['my_quee'];
      datatable.ajax.url(url).load();
      
    });

    $('#my_quee').click(function(event) {
      var data = get_value_all();
      var url = '/provider-get-data?priority='+data['priority']+'&city='+data['city']+'&state='+data['state']+'&county='+data['county']+'&status='+data['status']+'&date='+data['date']+'&hpt='+data['hpt']+'&my_quee='+data['my_quee'];
      datatable.ajax.url(url).load();
    });

    $('#state').change(function(event) {
      var data = get_value_all();
      var url = '/provider-get-data?priority='+data['priority']+'&city='+data['city']+'&state='+data['state']+'&county='+data['county']+'&status='+data['status']+'&date='+data['date']+'&hpt='+data['hpt']+'&my_quee='+data['my_quee'];
      datatable.ajax.url(url).load();
      $('#county').prop('disabled', true);
      $.get( "/get_data_county?state="+data['state'], function( data ) {
        $('#county').html(data);
        $('#county').prop('disabled', false);
      });
    });

    $('#county').change(function(event) {
      var data = get_value_all();
      var url = '/provider-get-data?priority='+data['priority']+'&city='+data['city']+'&state='+data['state']+'&county='+data['county']+'&status='+data['status']+'&date='+data['date']+'&hpt='+data['hpt']+'&my_quee='+data['my_quee'];
      datatable.ajax.url(url).load();
      $('#city').prop('disabled', true);
      $.get( "/get_data_city?county="+data['county'], function( data ) {
        $('#city').html(data);
        $('#city').prop('disabled', false);
      });
    });

    $('#status').change(function(event) {
      var data = get_value_all();
      var url = '/provider-get-data?priority='+data['priority']+'&city='+data['city']+'&state='+data['state']+'&county='+data['county']+'&status='+data['status']+'&date='+data['date']+'&hpt='+data['hpt']+'&my_quee='+data['my_quee'];
      datatable.ajax.url(url).load();

      if($(this).val() == 4851 || $(this).val() == 4850 || $(this).val() == 4920){
        $('.filter_date').css('display','inline-block');
        $('#date_pick').val('');
      }else{
        $('.filter_date').css('display','none');
        $('#date_pick').val('');
      }

    });

    var status_show = $('#status').val();
    if(status_show == 4851 || status_show == 4850 || status_show == 4920){
      $('.filter_date').css('display','inline-block');
      $('#date_pick').val('');
    }else{
      $('.filter_date').css('display','none');
      $('#date_pick').val('');
    }

    function get_value_all(){
      var data = [];
      data['priority'] = $('#priority').val();
      data['city'] = $('#city').val();
      data['state'] = $('#state').val();
      data['county'] = $('#county').val();
      data['status'] = $('#status').val();
      data['date'] = $('#date_pick').val();
      data['hpt'] = $('#hpt').val();
      
      if($("#my_quee"). prop("checked") == true){
        data['my_quee'] = 1;
      }else{
        data['my_quee'] = 0;
      }
      return data;
    }

    $('#date_tick').datetimepicker({
       format:'m/d/Y',
       timepicker:false,
       onChangeDateTime:function(dp,$input){
          var data = get_value_all();
          var url = '/provider-get-data?priority='+data['priority']+'&city='+data['city']+'&state='+data['state']+'&county='+data['county']+'&status='+data['status']+'&date='+$input.val()+'&hpt='+data['hpt']+'&my_quee='+data['my_quee'];
          datatable.ajax.url(url).load();
        }
    });

  });

}(jQuery));

          