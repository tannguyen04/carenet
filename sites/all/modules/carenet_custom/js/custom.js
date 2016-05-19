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
    
    $('#npi').keyup(function(event) {
      var npi = $(this).val();
      datatable.ajax.url( '/provider-get-data?npi='+npi ).load();
    });

  });
}(jQuery));

          