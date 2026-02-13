function setCookiesFromParams(params = parseQueryString()) {
    for (const key of Object.keys(params)) {
        if (_isParamSupportedCookie(key)) {
            _saveDocParam(key, params[key]);
        }
    }
}

function _isParamSupportedCookie(param) {
    const supportedCookies = ["searchPort"];
    const isSupported = supportedCookies.findIndex(item => param.toLowerCase() === item.toLowerCase());
    return (isSupported !== -1);
}

function parseQueryString() {
    let params = {};
    let qs = window.location.search;
    if (qs && qs.length > 0) {
        const paramsArray = qs.replace(/^\?/,"").split("&");
        for (let i = 0; i < paramsArray.length; i++) {
            let nameValPair = paramsArray[i].split("=");
            const name = nameValPair[0];
            const value = nameValPair.length > 1 ? decodeURIComponent(nameValPair[1].replace(/\+/g," ")) : "";
            params[name] = value;
        }
    }
    return params;
}

function getDocParam(name) {
    if (isLocalStorageEnabled()) {
        const itemStr = window.localStorage.getItem(name);
        if (!itemStr) {
            return null;
        }
        const item = JSON.parse(itemStr);
        const now = new Date();
        // Compare the expire time of the item with the current time.
        // If the item is expired, delete the it from storage and return null.
        if (now.getTime() > item.expireTime) {
            localStorage.removeItem(name);
            return null;
        }
        return item.value;
    } else {
        const cookies = document.cookie.split(';');
        for (let i = 0; i < cookies.length; i++) {
            const cookie = cookies[i].replace(/^\s+|\s+$/g, '');
            if (cookie.indexOf(name) === 0) {
                return cookie.substring(name.length + 1, cookie.length);
            }
        }
    }
    return null;
}

function hasDocParam(name) {
    return (getDocParam(name) ? true : false);
}

function _saveDocParam(name, value) {
    let date = new Date();
    // This sets the expiration date to 1 day from now.
    // TODO: Is that the right expiration date/time?
    date.setTime(date.getTime() + (24 * 60 * 60 * 1000));

    if (isLocalStorageEnabled()) {
        const item = {
            value: value,
            expireTime: date.getTime()
        }
        window.localStorage.setItem(name, JSON.stringify(item));
    } else {
        const expireDate = date.toGMTString();
        document.cookie = name + "=" + value
            + "; expires=" + expireDate
            + "; path=/";
    }
}

function isLocalStorageEnabled() {
    return !!window.localStorage;
}

// Copyright 2024 The MathWorks, Inc.
