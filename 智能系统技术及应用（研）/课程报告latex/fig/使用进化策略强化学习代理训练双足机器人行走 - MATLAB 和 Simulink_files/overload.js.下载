$(document).ready( function() {
    /* Windows load */
    $(window).on("load", function() {
        if (typeof requestHttpOverloadCommand === 'function') {
            requestHttpOverloadCommand(); 
        }
    });
});

function requestHttpOverloadCommand(){
    if($.getParameterByName("overload")) {
        var overloadCommand = $.getParameterByName("overload");

        var overloadRegex = /^(.*)[\s+](true|false)$/;
        var commandMatch = overloadCommand.match(overloadRegex);

        if (commandMatch.length <= 1) {
            return;
        }
        var helpTopic = commandMatch[1];

        getOverloadData().then(function(data) {
            findOverloads(helpTopic, data);
        });
    }
}

//===============================================================================
////==================overload page templates======================================

window.JST = window.JST || {};

// Overload function message bar
JST['messagebar'] = _.template(
    '<div id="message_bar">' +
    '<div class="alert alert-dismissible alert-info" role="alert">' +
     '<p class="alert_heading">' +
        '<a href="#" id="overload_message_bar_title" data-bs-toggle="modal" data-bs-target="#helpcenter-overload-function-dialog"><%= linktext %></a>' +
        '</p>' +
    '<button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close">' +
        '</button>' +
    '</div>'
);

// Modal Dialog with overload function list body
JST['overloaddialog'] = _.template(
    '<div class="modal fade" id="helpcenter-overload-function-dialog" tabindex="-1" role="dialog" aria-labelledby="helpcenterOverloadFunctionDialog" aria-hidden="true">' +
        '<div class="modal-dialog modal-lg" role="document">' +
            '<div class="modal-content">' +
                '<div class="modal-header">' +
                    '<h3 class="overload-dialog-title modal-title" id="helpcenterOverloadFunctionDialog" style="color:#C45400"><%= overloadData.title %></h3>' +
                    '<button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>' +
                '</div>' +
                '<div class="modal-body">' +
                    '<pre id="dialog-overload">' +
                        '<% _.each(overloadData.products, function(product) { %>' +
                            '<p style="font-weight:bold; font-size:11px;"><%= product.name %></p>' +
                            '<ul class="list-unstyled" style="margin-bottom:0px;">' +
                                '<% _.each(product.overloads, function(overload, i) { %>' +
                                '<li class="overload_func" style="margin-left: 25px; font-size:12px;">' +
                                    '<% var parameterSeparator = overload.Path.indexOf("?") !== -1 ? "&" : "?"; %>' +
                                    '<span class="icon-<%= getEntityTypeIconClass(overload.Type)%> icon_16" style="padding-right:4px;"></span>' +
                                    '<a class="overload_func_link" href="<%= overload.fullPath %>">' +
                                      '<%= overloadData.topic %>' +
                                    '</a>' +
                                    '<span> - <%= overload.Purpose %></span>' +
                                '</li>' +
                                '<% }) %>' +
                            '</ul>' +
                        '<% }) %>' +
                    '</pre>' +
                '</div>' +
                '<div class="modal-footer">' +
                    '<button type="button" class="btn btn_color_blue btn-outline" data-bs-dismiss="modal" data-test-id="overload-close-button">CLOSE</button>' +
                '</div>' +
            '</div>' +
        '</div>' +
    '</div>'
);

function getOverloadData() {
    const url = findDocRoot() + '/overloads/overloads.json';
    return fetch(url).then(function (response) {
        if (response.ok) {
            return response.json();
        } else {
            return {};
        }
    });
}

function findDocRoot() {
    var docRootMatches = document.location.href.match(/^.*\/help(\/releases\/R20\d\d[ab])?(\/prereleases\/R20\d\d[ab])?/);
    return docRootMatches.length > 0 ? docRootMatches[0] : "/help";
}

function findOverloads(helpTopic, data) {
    const topicEntry = data.find(item => item.name === helpTopic);
    if (topicEntry) {
        groupOverloads(topicEntry);
    }
}

function groupOverloads(topicEntry) {
    const products = [];
    const docroot = findDocRoot();
    for (let overload of topicEntry.refitems) {
        overload.fullPath = docroot + '/' + overload.HelpLocation + '/' + overload.Path;
        
        let product = products.find(product => product.name === overload.ProductName);
        if (product) {
            product.overloads.push(overload);
        } else {
            products.push({
                'name' : overload.ProductName,
                'overloads' : [overload]
            });
        }
    }
    
    products.sort(compareProducts);
    const title = getLocalizedString('overloads_title').replace(/\{0\}/, topicEntry.name);
    const otheruses = getLocalizedString('overloads_other_uses').replace(/\{0\}/, topicEntry.name);
    const overloadData = {
        'topic' : topicEntry.name,
        'other_uses' : otheruses,
        'title' : title,
        'products' : products
    };
    populateOverloadStrings(overloadData);
}

function compareProducts(prod1, prod2) {
    let name1 = prod1.name;
    let name2 = prod2.name;
    if (name1 === 'MATLAB' || name1 === 'Simulink') {
        name1 = '0_' + name1;
    }
    if (name2 === 'MATLAB' || name2 === 'Simulink') {
        name2 = '0_' + name2;
    }
    return name1.localeCompare(name2);
}

function getOverloadFunctionsListHtml(overloadFunctionsJson) {
    var jsonData = {overloadData: overloadFunctionsJson};
    return JST['overloaddialog'](jsonData);
}

function getOverloadMessageBarInfo(overloadFunctionsJson) {
    var jsonData = {linktext: overloadFunctionsJson.other_uses};
    return JST['messagebar'](jsonData);
}

function storeMessagebarStatus() {
    sessionStorage.setItem('overloadmessagebar', 'hide');
}

function loadMessagebarStatus() {
    return sessionStorage.getItem('overloadmessagebar');
}

function getEntityTypeIconClass(type) {
    switch (type) {
        case "function" :
        case "method" :
        case "class" : return "function";
        case "block" : return "block";
        case "sysobj" : return "systemobject";
        case "app" : return "app";
        default : return "function";
    }
}

function populateOverloadStrings(overloadData) {
    var messagebarVisible = loadMessagebarStatus();
    if (overloadData !== 'undefined' && overloadData !== null && messagebarVisible !== 'hide') {        
        var messagebar = getOverloadMessageBarInfo(overloadData);
        if ($('#message_bar').length === 0) {
            $('#localnav').addClass("messagebar_active"); // fix the left nav breadcrumb scroll fixed top
            $('#localnav').prepend(messagebar);
            $("#message_bar").show();   
            $(window).trigger('content_resize'); // fix the scroll
            $('div#message_bar').on('close.bs.alert', function () {
                //
                storeMessagebarStatus();
                $('#localnav').removeClass("messagebar_active");  // fix the left nav breadcrumb scroll fixed top
                $(window).trigger('content_resize'); // fix the scroll
            });
        }

        var  html = getOverloadFunctionsListHtml(overloadData);
        $('#content_container').prepend(html);
    }   
}