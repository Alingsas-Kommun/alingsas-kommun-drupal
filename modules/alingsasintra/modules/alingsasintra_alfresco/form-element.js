window.aldialog = '';
window.alfield = '';

jQuery(window).resize(function () {
    fluidDialog();
});

// catch dialog if opened within a viewport smaller than the dialog width
jQuery(document).delegate(".ui-dialog", "open", function (event, ui) {
    fluidDialog();
});

function fluidDialog() {
    var $visible = jQuery(".ui-dialog:visible");
    // each open dialog
    $visible.each(function () {
        var $this = jQuery(this);
        var dialog = $this.find(".ui-dialog-content").data("dialog");
        // if fluid option == true
        if (dialog.options.fluid) {
            var wWidth = jQuery(window).width();
            // check window width against dialog width
            if (wWidth < dialog.options.maxWidth + 50) {
                // keep dialog from filling entire screen
                $this.css("max-width", "90%");
            } else {
                // fix maxWidth bug
                $this.css("max-width", dialog.options.maxWidth);
            }
            //reposition dialog
            dialog.option("position", dialog.options.position);
        }
    });

}

jQuery(function(){
	jQuery('form').delegate('a.al-browse', 'click', function(event) {
		window.alfield = jQuery(this);
		if(window.aldialog.length) {
			window.aldialog.dialog();
		}
		else {
			window.aldialog = jQuery('<div/>', {id: 'al-dialog'});
			window.aldialog.html('<div class="al-loading">Laddar...</div>');
			window.aldialog.load('/alfresco/browse/get').dialog({
			      width: 500,
			      maxWidth: 500,
			      height: 500,
			      modal: true,
			      fluid: true,
			      title: 'Välj dokument'
			    });
		}
		return false;
	});
});