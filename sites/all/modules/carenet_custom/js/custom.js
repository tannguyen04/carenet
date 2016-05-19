(function ($) {
  $( document ).ready(function() {
  	var fields = JSON.parse(Drupal.settings.carenet_custom_list_data_fields);
  	$('#carenet_custom_list_data').DataTable( {
        dom: "Bfrtip",
        ajax: {
            url: "/provider-get-data",
            type: "POST"
        },
        serverSide: true,
        columns: fields,
        select: true,
        
    } );
  });
}(jQuery));

          