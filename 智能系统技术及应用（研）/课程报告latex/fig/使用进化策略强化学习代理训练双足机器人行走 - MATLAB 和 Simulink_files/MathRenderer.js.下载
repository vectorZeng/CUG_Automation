// Copyright 2013-2023 The MathWorks, Inc.
/**
    Wrapper for StandaloneEqnRenderer which takes care of loading the equation renderer.

    Usage: just include this script from HTML. By default it selects all <math> elements
           on a page and replaces them by the rendered output.

        <script type="text/javascript"
                src="<matlab root path>/ui/equationrenderer/release/MathRenderer.js"></script>
 **/

(function () {
    // These are the configuration parameters which are passed through to the
    // StandaloneEqnRenderer by default.
    const equationrendererDefaultConfig = {
        flavor: 'MathType',
        equationFormat: 'mathml',
        equationEncoding: 'element',
        equationRootElement: 'math',
        cacheFontMetrics: false
    };

    (function () {
        const head = document.getElementsByTagName('head')[0];

        // first hide existing math elements to avoid flickering equations
        const style = document.createElement('style');
        style.type = 'text/css';
        style.textContent = equationrendererDefaultConfig.equationRootElement +
            ' { visibility: hidden; }';
        head.appendChild(style);

        // find the script tag which loads this file and extract the path
        let basePath = '';
        const scriptTags = (document.documentElement || document).getElementsByTagName('script');
        for (let i = scriptTags.length - 1; i >= 0; i = i - 1) {
            const srcStr = scriptTags[i].getAttribute('src') || '';
            if (srcStr.match(/(^.*)enderer.js$/)) {
                // pick up the begin of the path and use it below to load the built equationrenderer
                basePath = srcStr.slice(0, -15);
                break;
            }
        }

        const link = document.createElement('link');
        link.type = 'text/css';
        link.rel = 'stylesheet';
        link.href = basePath + 'index-css.css';
        head.appendChild(link);

        const script = document.createElement('script');
        script.type = 'text/javascript';
        script.src = basePath + 'bundle.index.js';
        head.appendChild(script);
    }());
}());
