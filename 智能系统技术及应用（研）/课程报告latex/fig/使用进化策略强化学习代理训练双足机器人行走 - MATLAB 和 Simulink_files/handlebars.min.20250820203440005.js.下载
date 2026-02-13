/**!

 @license
 handlebars v4.7.8

Copyright (C) 2011-2019 by Yehuda Katz

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/
(function webpackUniversalModuleDefinition(root, factory) {
	if(typeof exports === 'object' && typeof module === 'object')
		module.exports = factory();
	else if(typeof define === 'function' && define.amd)
		define([], factory);
	else if(typeof exports === 'object')
		exports["Handlebars"] = factory();
	else
		root["Handlebars"] = factory();
})(this, function() {
return /******/ (function(modules) { // webpackBootstrap
/******/ 	// The module cache
/******/ 	var installedModules = {};

/******/ 	// The require function
/******/ 	function __webpack_require__(moduleId) {

/******/ 		// Check if module is in cache
/******/ 		if(installedModules[moduleId])
/******/ 			return installedModules[moduleId].exports;

/******/ 		// Create a new module (and put it into the cache)
/******/ 		var module = installedModules[moduleId] = {
/******/ 			exports: {},
/******/ 			id: moduleId,
/******/ 			loaded: false
/******/ 		};

/******/ 		// Execute the module function
/******/ 		modules[moduleId].call(module.exports, module, module.exports, __webpack_require__);

/******/ 		// Flag the module as loaded
/******/ 		module.loaded = true;

/******/ 		// Return the exports of the module
/******/ 		return module.exports;
/******/ 	}


/******/ 	// expose the modules object (__webpack_modules__)
/******/ 	__webpack_require__.m = modules;

/******/ 	// expose the module cache
/******/ 	__webpack_require__.c = installedModules;

/******/ 	// __webpack_public_path__
/******/ 	__webpack_require__.p = "";

/******/ 	// Load entry module and return exports
/******/ 	return __webpack_require__(0);
/******/ })
/************************************************************************/
/******/ ([
/* 0 */
/***/ (function(module, exports, __webpack_require__) {

	'use strict';

	var _interopRequireWildcard = __webpack_require__(1)['default'];

	var _interopRequireDefault = __webpack_require__(2)['default'];

	exports.__esModule = true;

	var _handlebarsBase = __webpack_require__(3);

	var base = _interopRequireWildcard(_handlebarsBase);

	// Each of these augment the Handlebars object. No need to setup here.
	// (This is done to easily share code between commonjs and browse envs)

	var _handlebarsSafeString = __webpack_require__(76);

	var _handlebarsSafeString2 = _interopRequireDefault(_handlebarsSafeString);

	var _handlebarsException = __webpack_require__(5);

	var _handlebarsException2 = _interopRequireDefault(_handlebarsException);

	var _handlebarsUtils = __webpack_require__(4);

	var Utils = _interopRequireWildcard(_handlebarsUtils);

	var _handlebarsRuntime = __webpack_require__(77);

	var runtime = _interopRequireWildcard(_handlebarsRuntime);

	var _handlebarsNoConflict = __webpack_require__(82);

	var _handlebarsNoConflict2 = _interopRequireDefault(_handlebarsNoConflict);

	// For compatibility and usage outside of module systems, make the Handlebars object a namespace
	function create() {
	  var hb = new base.HandlebarsEnvironment();

	  Utils.extend(hb, base);
	  hb.SafeString = _handlebarsSafeString2['default'];
	  hb.Exception = _handlebarsException2['default'];
	  hb.Utils = Utils;
	  hb.escapeExpression = Utils.escapeExpression;

	  hb.VM = runtime;
	  hb.template = function (spec) {
	    return runtime.template(spec, hb);
	  };

	  return hb;
	}

	var inst = create();
	inst.create = create;

	_handlebarsNoConflict2['default'](inst);

	inst['default'] = inst;

	exports['default'] = inst;
	module.exports = exports['default'];

/***/ }),
/* 1 */
/***/ (function(module, exports) {

	"use strict";

	exports["default"] = function (obj) {
	  if (obj && obj.__esModule) {
	    return obj;
	  } else {
	    var newObj = {};

	    if (obj != null) {
	      for (var key in obj) {
	        if (Object.prototype.hasOwnProperty.call(obj, key)) newObj[key] = obj[key];
	      }
	    }

	    newObj["default"] = obj;
	    return newObj;
	  }
	};

	exports.__esModule = true;

/***/ }),
/* 2 */
/***/ (function(module, exports) {

	"use strict";

	exports["default"] = function (obj) {
	  return obj && obj.__esModule ? obj : {
	    "default": obj
	  };
	};

	exports.__esModule = true;

/***/ }),
/* 3 */
/***/ (function(module, exports, __webpack_require__) {

	'use strict';

	var _interopRequireDefault = __webpack_require__(2)['default'];

	exports.__esModule = true;
	exports.HandlebarsEnvironment = HandlebarsEnvironment;

	var _utils = __webpack_require__(4);

	var _exception = __webpack_require__(5);

	var _exception2 = _interopRequireDefault(_exception);

	var _helpers = __webpack_require__(9);

	var _decorators = __webpack_require__(69);

	var _logger = __webpack_require__(71);

	var _logger2 = _interopRequireDefault(_logger);

	var _internalProtoAccess = __webpack_require__(72);

	var VERSION = '4.7.8';
	exports.VERSION = VERSION;
	var COMPILER_REVISION = 8;
	exports.COMPILER_REVISION = COMPILER_REVISION;
	var LAST_COMPATIBLE_COMPILER_REVISION = 7;

	exports.LAST_COMPATIBLE_COMPILER_REVISION = LAST_COMPATIBLE_COMPILER_REVISION;
	var REVISION_CHANGES = {
	  1: '<= 1.0.rc.2', // 1.0.rc.2 is actually rev2 but doesn't report it
	  2: '== 1.0.0-rc.3',
	  3: '== 1.0.0-rc.4',
	  4: '== 1.x.x',
	  5: '== 2.0.0-alpha.x',
	  6: '>= 2.0.0-beta.1',
	  7: '>= 4.0.0 <4.3.0',
	  8: '>= 4.3.0'
	};

	exports.REVISION_CHANGES = REVISION_CHANGES;
	var objectType = '[object Object]';

	function HandlebarsEnvironment(helpers, partials, decorators) {
	  this.helpers = helpers || {};
	  this.partials = partials || {};
	  this.decorators = decorators || {};

	  _helpers.registerDefaultHelpers(this);
	  _decorators.registerDefaultDecorators(this);
	}

	HandlebarsEnvironment.prototype = {
	  constructor: HandlebarsEnvironment,

	  logger: _logger2['default'],
	  log: _logger2['default'].log,

	  registerHelper: function registerHelper(name, fn) {
	    if (_utils.toString.call(name) === objectType) {
	      if (fn) {
	        throw new _exception2['default']('Arg not supported with multiple helpers');
	      }
	      _utils.extend(this.helpers, name);
	    } else {
	      this.helpers[name] = fn;
	    }
	  },
	  unregisterHelper: function unregisterHelper(name) {
	    delete this.helpers[name];
	  },

	  registerPartial: function registerPartial(name, partial) {
	    if (_utils.toString.call(name) === objectType) {
	      _utils.extend(this.partials, name);
	    } else {
	      if (typeof partial === 'undefined') {
	        throw new _exception2['default']('Attempting to register a partial called "' + name + '" as undefined');
	      }
	      this.partials[name] = partial;
	    }
	  },
	  unregisterPartial: function unregisterPartial(name) {
	    delete this.partials[name];
	  },

	  registerDecorator: function registerDecorator(name, fn) {
	    if (_utils.toString.call(name) === objectType) {
	      if (fn) {
	        throw new _exception2['default']('Arg not supported with multiple decorators');
	      }
	      _utils.extend(this.decorators, name);
	    } else {
	      this.decorators[name] = fn;
	    }
	  },
	  unregisterDecorator: function unregisterDecorator(name) {
	    delete this.decorators[name];
	  },
	  /**
	   * Reset the memory of illegal property accesses that have already been logged.
	   * @deprecated should only be used in handlebars test-cases
	   */
	  resetLoggedPropertyAccesses: function resetLoggedPropertyAccesses() {
	    _internalProtoAccess.resetLoggedProperties();
	  }
	};

	var log = _logger2['default'].log;

	exports.log = log;
	exports.createFrame = _utils.createFrame;
	exports.logger = _logger2['default'];

/***/ }),
/* 4 */
/***/ (function(module, exports) {

	'use strict';

	exports.__esModule = true;
	exports.extend = extend;
	exports.indexOf = indexOf;
	exports.escapeExpression = escapeExpression;
	exports.isEmpty = isEmpty;
	exports.createFrame = createFrame;
	exports.blockParams = blockParams;
	exports.appendContextPath = appendContextPath;
	var escape = {
	  '&': '&amp;',
	  '<': '&lt;',
	  '>': '&gt;',
	  '"': '&quot;',
	  "'": '&#x27;',
	  '`': '&#x60;',
	  '=': '&#x3D;'
	};

	var badChars = /[&<>"'`=]/g,
	    possible = /[&<>"'`=]/;

	function escapeChar(chr) {
	  return escape[chr];
	}

	function extend(obj /* , ...source */) {
	  for (var i = 1; i < arguments.length; i++) {
	    for (var key in arguments[i]) {
	      if (Object.prototype.hasOwnProperty.call(arguments[i], key)) {
	        obj[key] = arguments[i][key];
	      }
	    }
	  }

	  return obj;
	}

	var toString = Object.prototype.toString;

	exports.toString = toString;
	// Sourced from lodash
	// https://github.com/bestiejs/lodash/blob/master/LICENSE.txt
	/* eslint-disable func-style */
	var isFunction = function isFunction(value) {
	  return typeof value === 'function';
	};
	// fallback for older versions of Chrome and Safari
	/* istanbul ignore next */
	if (isFunction(/x/)) {
	  exports.isFunction = isFunction = function (value) {
	    return typeof value === 'function' && toString.call(value) === '[object Function]';
	  };
	}
	exports.isFunction = isFunction;

	/* eslint-enable func-style */

	/* istanbul ignore next */
	var isArray = Array.isArray || function (value) {
	  return value && typeof value === 'object' ? toString.call(value) === '[object Array]' : false;
	};

	exports.isArray = isArray;
	// Older IE versions do not directly support indexOf so we must implement our own, sadly.

	function indexOf(array, value) {
	  for (var i = 0, len = array.length; i < len; i++) {
	    if (array[i] === value) {
	      return i;
	    }
	  }
	  return -1;
	}

	function escapeExpression(string) {
	  if (typeof string !== 'string') {
	    // don't escape SafeStrings, since they're already safe
	    if (string && string.toHTML) {
	      return string.toHTML();
	    } else if (string == null) {
	      return '';
	    } else if (!string) {
	      return string + '';
	    }

	    // Force a string conversion as this will be done by the append regardless and
	    // the regex test will do this transparently behind the scenes, causing issues if
	    // an object's to string has escaped characters in it.
	    string = '' + string;
	  }

	  if (!possible.test(string)) {
	    return string;
	  }
	  return string.replace(badChars, escapeChar);
	}

	function isEmpty(value) {
	  if (!value && value !== 0) {
	    return true;
	  } else if (isArray(value) && value.length === 0) {
	    return true;
	  } else {
	    return false;
	  }
	}

	function createFrame(object) {
	  var frame = extend({}, object);
	  frame._parent = object;
	  return frame;
	}

	function blockParams(params, ids) {
	  params.path = ids;
	  return params;
	}

	function appendContextPath(contextPath, id) {
	  return (contextPath ? contextPath + '.' : '') + id;
	}

/***/ }),
/* 5 */
/***/ (function(module, exports, __webpack_require__) {

	'use strict';

	var _Object$defineProperty = __webpack_require__(6)['default'];

	exports.__esModule = true;
	var errorProps = ['description', 'fileName', 'lineNumber', 'endLineNumber', 'message', 'name', 'number', 'stack'];

	function Exception(message, node) {
	  var loc = node && node.loc,
	      line = undefined,
	      endLineNumber = undefined,
	      column = undefined,
	      endColumn = undefined;

	  if (loc) {
	    line = loc.start.line;
	    endLineNumber = loc.end.line;
	    column = loc.start.column;
	    endColumn = loc.end.column;

	    message += ' - ' + line + ':' + column;
	  }

	  var tmp = Error.prototype.constructor.call(this, message);

	  // Unfortunately errors are not enumerable in Chrome (at least), so `for prop in tmp` doesn't work.
	  for (var idx = 0; idx < errorProps.length; idx++) {
	    this[errorProps[idx]] = tmp[errorProps[idx]];
	  }

	  /* istanbul ignore else */
	  if (Error.captureStackTrace) {
	    Error.captureStackTrace(this, Exception);
	  }

	  try {
	    if (loc) {
	      this.lineNumber = line;
	      this.endLineNumber = endLineNumber;

	      // Work around issue under safari where we can't directly set the column value
	      /* istanbul ignore next */
	      if (_Object$defineProperty) {
	        Object.defineProperty(this, 'column', {
	          value: column,
	          enumerable: true
	        });
	        Object.defineProperty(this, 'endColumn', {
	          value: endColumn,
	          enumerable: true
	        });
	      } else {
	        this.column = column;
	        this.endColumn = endColumn;
	      }
	    }
	  } catch (nop) {
	    /* Ignore if the browser is very particular */
	  }
	}

	Exception.prototype = new Error();

	exports['default'] = Exception;
	module.exports = exports['default'];

/***/ }),
/* 6 */
/***/ (function(module, exports, __webpack_require__) {

	module.exports = { "default": __webpack_require__(7), __esModule: true };

/***/ }),
/* 7 */
/***/ (function(module, exports, __webpack_require__) {

	var $ = __webpack_require__(8);
	module.exports = function defineProperty(it, key, desc){
	  return $.setDesc(it, key, desc);
	};

/***/ }),
/* 8 */
/***/ (function(module, exports) {

	var $Object = Object;
	module.exports = {
	  create:     $Object.create,
	  getProto:   $Object.getPrototypeOf,
	  isEnum:     {}.propertyIsEnumerable,
	  getDesc:    $Object.getOwnPropertyDescriptor,
	  setDesc:    $Object.defineProperty,
	  setDescs:   $Object.defineProperties,
	  getKeys:    $Object.keys,
	  getNames:   $Object.getOwnPropertyNames,
	  getSymbols: $Object.getOwnPropertySymbols,
	  each:       [].forEach
	};

/***/ }),
/* 9 */
/***/ (function(module, exports, __webpack_require__) {

	'use strict';

	var _interopRequireDefault = __webpack_require__(2)['default'];

	exports.__esModule = true;
	exports.registerDefaultHelpers = registerDefaultHelpers;
	exports.moveHelperToHooks = moveHelperToHooks;

	var _helpersBlockHelperMissing = __webpack_require__(10);

	var _helpersBlockHelperMissing2 = _interopRequireDefault(_helpersBlockHelperMissing);

	var _helpersEach = __webpack_require__(11);

	var _helpersEach2 = _interopRequireDefault(_helpersEach);

	var _helpersHelperMissing = __webpack_require__(64);

	var _helpersHelperMissing2 = _interopRequireDefault(_helpersHelperMissing);

	var _helpersIf = __webpack_require__(65);

	var _helpersIf2 = _interopRequireDefault(_helpersIf);

	var _helpersLog = __webpack_require__(66);

	var _helpersLog2 = _interopRequireDefault(_helpersLog);

	var _helpersLookup = __webpack_require__(67);

	var _helpersLookup2 = _interopRequireDefault(_helpersLookup);

	var _helpersWith = __webpack_require__(68);

	var _helpersWith2 = _interopRequireDefault(_helpersWith);

	function registerDefaultHelpers(instance) {
	  _helpersBlockHelperMissing2['default'](instance);
	  _helpersEach2['default'](instance);
	  _helpersHelperMissing2['default'](instance);
	  _helpersIf2['default'](instance);
	  _helpersLog2['default'](instance);
	  _helpersLookup2['default'](instance);
	  _helpersWith2['default'](instance);
	}

	function moveHelperToHooks(instance, helperName, keepHelper) {
	  if (instance.helpers[helperName]) {
	    instance.hooks[helperName] = instance.helpers[helperName];
	    if (!keepHelper) {
	      delete instance.helpers[helperName];
	    }
	  }
	}

/***/ }),
/* 10 */
/***/ (function(module, exports, __webpack_require__) {

	'use strict';

	exports.__esModule = true;

	var _utils = __webpack_require__(4);

	exports['default'] = function (instance) {
	  instance.registerHelper('blockHelperMissing', function (context, options) {
	    var inverse = options.inverse,
	        fn = options.fn;

	    if (context === true) {
	      return fn(this);
	    } else if (context === false || context == null) {
	      return inverse(this);
	    } else if (_utils.isArray(context)) {
	      if (context.length > 0) {
	        if (options.ids) {
	          options.ids = [options.name];
	        }

	        return instance.helpers.each(context, options);
	      } else {
	        return inverse(this);
	      }
	    } else {
	      if (options.data && options.ids) {
	        var data = _utils.createFrame(options.data);
	        data.contextPath = _utils.appendContextPath(options.data.contextPath, options.name);
	        options = { data: data };
	      }

	      return fn(context, options);
	    }
	  });
	};

	module.exports = exports['default'];

/***/ }),
/* 11 */
/***/ (function(module, exports, __webpack_require__) {

	'use strict';

	var _Symbol = __webpack_require__(12)['default'];

	var _Symbol$iterator = __webpack_require__(42)['default'];

	var _getIterator = __webpack_require__(54)['default'];

	var _Object$keys = __webpack_require__(59)['default'];

	var _interopRequireDefault = __webpack_require__(2)['default'];

	exports.__esModule = true;

	var _utils = __webpack_require__(4);

	var _exception = __webpack_require__(5);

	var _exception2 = _interopRequireDefault(_exception);

	exports['default'] = function (instance) {
	  instance.registerHelper('each', function (context, options) {
	    if (!options) {
	      throw new _exception2['default']('Must pass iterator to #each');
	    }

	    var fn = options.fn,
	        inverse = options.inverse,
	        i = 0,
	        ret = '',
	        data = undefined,
	        contextPath = undefined;

	    if (options.data && options.ids) {
	      contextPath = _utils.appendContextPath(options.data.contextPath, options.ids[0]) + '.';
	    }

	    if (_utils.isFunction(context)) {
	      context = context.call(this);
	    }

	    if (options.data) {
	      data = _utils.createFrame(options.data);
	    }

	    function execIteration(field, index, last) {
	      if (data) {
	        data.key = field;
	        data.index = index;
	        data.first = index === 0;
	        data.last = !!last;

	        if (contextPath) {
	          data.contextPath = contextPath + field;
	        }
	      }

	      ret = ret + fn(context[field], {
	        data: data,
	        blockParams: _utils.blockParams([context[field], field], [contextPath + field, null])
	      });
	    }

	    if (context && typeof context === 'object') {
	      if (_utils.isArray(context)) {
	        for (var j = context.length; i < j; i++) {
	          if (i in context) {
	            execIteration(i, i, i === context.length - 1);
	          }
	        }
	      } else if (typeof _Symbol === 'function' && context[_Symbol$iterator]) {
	        var newContext = [];
	        var iterator = _getIterator(context);
	        for (var it = iterator.next(); !it.done; it = iterator.next()) {
	          newContext.push(it.value);
	        }
	        context = newContext;
	        for (var j = context.length; i < j; i++) {
	          execIteration(i, i, i === context.length - 1);
	        }
	      } else {
	        (function () {
	          var priorKey = undefined;

	          _Object$keys(context).forEach(function (key) {
	            // We're running the iterations one step out of sync so we can detect
	            // the last iteration without have to scan the object twice and create
	            // an itermediate keys array.
	            if (priorKey !== undefined) {
	              execIteration(priorKey, i - 1);
	            }
	            priorKey = key;
	            i++;
	          });
	          if (priorKey !== undefined) {
	            execIteration(priorKey, i - 1, true);
	          }
	        })();
	      }
	    }

	    if (i === 0) {
	      ret = inverse(this);
	    }

	    return ret;
	  });
	};

	module.exports = exports['default'];

/***/ }),
/* 12 */
/***/ (function(module, exports, __webpack_require__) {

	module.exports = { "default": __webpack_require__(13), __esModule: true };

/***/ }),
/* 13 */
/***/ (function(module, exports, __webpack_require__) {

	__webpack_require__(14);
	__webpack_require__(41);
	module.exports = __webpack_require__(20).Symbol;

/***/ }),
/* 14 */
/***/ (function(module, exports, __webpack_require__) {

	'use strict';
	// ECMAScript 6 symbols shim
	var $              = __webpack_require__(8)
	  , global         = __webpack_require__(15)
	  , has            = __webpack_require__(16)
	  , DESCRIPTORS    = __webpack_require__(17)
	  , $export        = __webpack_require__(19)
	  , redefine       = __webpack_require__(23)
	  , $fails         = __webpack_require__(18)
	  , shared         = __webpack_require__(26)
	  , setToStringTag = __webpack_require__(27)
	  , uid            = __webpack_require__(29)
	  , wks            = __webpack_require__(28)
	  , keyOf          = __webpack_require__(30)
	  , $names         = __webpack_require__(35)
	  , enumKeys       = __webpack_require__(36)
	  , isArray        = __webpack_require__(37)
	  , anObject       = __webpack_require__(38)
	  , toIObject      = __webpack_require__(31)
	  , createDesc     = __webpack_require__(25)
	  , getDesc        = $.getDesc
	  , setDesc        = $.setDesc
	  , _create        = $.create
	  , getNames       = $names.get
	  , $Symbol        = global.Symbol
	  , $JSON          = global.JSON
	  , _stringify     = $JSON && $JSON.stringify
	  , setter         = false
	  , HIDDEN         = wks('_hidden')
	  , isEnum         = $.isEnum
	  , SymbolRegistry = shared('symbol-registry')
	  , AllSymbols     = shared('symbols')
	  , useNative      = typeof $Symbol == 'function'
	  , ObjectProto    = Object.prototype;

	// fallback for old Android, https://code.google.com/p/v8/issues/detail?id=687
	var setSymbolDesc = DESCRIPTORS && $fails(function(){
	  return _create(setDesc({}, 'a', {
	    get: function(){ return setDesc(this, 'a', {value: 7}).a; }
	  })).a != 7;
	}) ? function(it, key, D){
	  var protoDesc = getDesc(ObjectProto, key);
	  if(protoDesc)delete ObjectProto[key];
	  setDesc(it, key, D);
	  if(protoDesc && it !== ObjectProto)setDesc(ObjectProto, key, protoDesc);
	} : setDesc;

	var wrap = function(tag){
	  var sym = AllSymbols[tag] = _create($Symbol.prototype);
	  sym._k = tag;
	  DESCRIPTORS && setter && setSymbolDesc(ObjectProto, tag, {
	    configurable: true,
	    set: function(value){
	      if(has(this, HIDDEN) && has(this[HIDDEN], tag))this[HIDDEN][tag] = false;
	      setSymbolDesc(this, tag, createDesc(1, value));
	    }
	  });
	  return sym;
	};

	var isSymbol = function(it){
	  return typeof it == 'symbol';
	};

	var $defineProperty = function defineProperty(it, key, D){
	  if(D && has(AllSymbols, key)){
	    if(!D.enumerable){
	      if(!has(it, HIDDEN))setDesc(it, HIDDEN, createDesc(1, {}));
	      it[HIDDEN][key] = true;
	    } else {
	      if(has(it, HIDDEN) && it[HIDDEN][key])it[HIDDEN][key] = false;
	      D = _create(D, {enumerable: createDesc(0, false)});
	    } return setSymbolDesc(it, key, D);
	  } return setDesc(it, key, D);
	};
	var $defineProperties = function defineProperties(it, P){
	  anObject(it);
	  var keys = enumKeys(P = toIObject(P))
	    , i    = 0
	    , l = keys.length
	    , key;
	  while(l > i)$defineProperty(it, key = keys[i++], P[key]);
	  return it;
	};
	var $create = function create(it, P){
	  return P === undefined ? _create(it) : $defineProperties(_create(it), P);
	};
	var $propertyIsEnumerable = function propertyIsEnumerable(key){
	  var E = isEnum.call(this, key);
	  return E || !has(this, key) || !has(AllSymbols, key) || has(this, HIDDEN) && this[HIDDEN][key]
	    ? E : true;
	};
	var $getOwnPropertyDescriptor = function getOwnPropertyDescriptor(it, key){
	  var D = getDesc(it = toIObject(it), key);
	  if(D && has(AllSymbols, key) && !(has(it, HIDDEN) && it[HIDDEN][key]))D.enumerable = true;
	  return D;
	};
	var $getOwnPropertyNames = function getOwnPropertyNames(it){
	  var names  = getNames(toIObject(it))
	    , result = []
	    , i      = 0
	    , key;
	  while(names.length > i)if(!has(AllSymbols, key = names[i++]) && key != HIDDEN)result.push(key);
	  return result;
	};
	var $getOwnPropertySymbols = function getOwnPropertySymbols(it){
	  var names  = getNames(toIObject(it))
	    , result = []
	    , i      = 0
	    , key;
	  while(names.length > i)if(has(AllSymbols, key = names[i++]))result.push(AllSymbols[key]);
	  return result;
	};
	var $stringify = function stringify(it){
	  if(it === undefined || isSymbol(it))return; // IE8 returns string on undefined
	  var args = [it]
	    , i    = 1
	    , $$   = arguments
	    , replacer, $replacer;
	  while($$.length > i)args.push($$[i++]);
	  replacer = args[1];
	  if(typeof replacer == 'function')$replacer = replacer;
	  if($replacer || !isArray(replacer))replacer = function(key, value){
	    if($replacer)value = $replacer.call(this, key, value);
	    if(!isSymbol(value))return value;
	  };
	  args[1] = replacer;
	  return _stringify.apply($JSON, args);
	};
	var buggyJSON = $fails(function(){
	  var S = $Symbol();
	  // MS Edge converts symbol values to JSON as {}
	  // WebKit converts symbol values to JSON as null
	  // V8 throws on boxed symbols
	  return _stringify([S]) != '[null]' || _stringify({a: S}) != '{}' || _stringify(Object(S)) != '{}';
	});

	// 19.4.1.1 Symbol([description])
	if(!useNative){
	  $Symbol = function Symbol(){
	    if(isSymbol(this))throw TypeError('Symbol is not a constructor');
	    return wrap(uid(arguments.length > 0 ? arguments[0] : undefined));
	  };
	  redefine($Symbol.prototype, 'toString', function toString(){
	    return this._k;
	  });

	  isSymbol = function(it){
	    return it instanceof $Symbol;
	  };

	  $.create     = $create;
	  $.isEnum     = $propertyIsEnumerable;
	  $.getDesc    = $getOwnPropertyDescriptor;
	  $.setDesc    = $defineProperty;
	  $.setDescs   = $defineProperties;
	  $.getNames   = $names.get = $getOwnPropertyNames;
	  $.getSymbols = $getOwnPropertySymbols;

	  if(DESCRIPTORS && !__webpack_require__(40)){
	    redefine(ObjectProto, 'propertyIsEnumerable', $propertyIsEnumerable, true);
	  }
	}

	var symbolStatics = {
	  // 19.4.2.1 Symbol.for(key)
	  'for': function(key){
	    return has(SymbolRegistry, key += '')
	      ? SymbolRegistry[key]
	      : SymbolRegistry[key] = $Symbol(key);
	  },
	  // 19.4.2.5 Symbol.keyFor(sym)
	  keyFor: function keyFor(key){
	    return keyOf(SymbolRegistry, key);
	  },
	  useSetter: function(){ setter = true; },
	  useSimple: function(){ setter = false; }
	};
	// 19.4.2.2 Symbol.hasInstance
	// 19.4.2.3 Symbol.isConcatSpreadable
	// 19.4.2.4 Symbol.iterator
	// 19.4.2.6 Symbol.match
	// 19.4.2.8 Symbol.replace
	// 19.4.2.9 Symbol.search
	// 19.4.2.10 Symbol.species
	// 19.4.2.11 Symbol.split
	// 19.4.2.12 Symbol.toPrimitive
	// 19.4.2.13 Symbol.toStringTag
	// 19.4.2.14 Symbol.unscopables
	$.each.call((
	  'hasInstance,isConcatSpreadable,iterator,match,replace,search,' +
	  'species,split,toPrimitive,toStringTag,unscopables'
	).split(','), function(it){
	  var sym = wks(it);
	  symbolStatics[it] = useNative ? sym : wrap(sym);
	});

	setter = true;

	$export($export.G + $export.W, {Symbol: $Symbol});

	$export($export.S, 'Symbol', symbolStatics);

	$export($export.S + $export.F * !useNative, 'Object', {
	  // 19.1.2.2 Object.create(O [, Properties])
	  create: $create,
	  // 19.1.2.4 Object.defineProperty(O, P, Attributes)
	  defineProperty: $defineProperty,
	  // 19.1.2.3 Object.defineProperties(O, Properties)
	  defineProperties: $defineProperties,
	  // 19.1.2.6 Object.getOwnPropertyDescriptor(O, P)
	  getOwnPropertyDescriptor: $getOwnPropertyDescriptor,
	  // 19.1.2.7 Object.getOwnPropertyNames(O)
	  getOwnPropertyNames: $getOwnPropertyNames,
	  // 19.1.2.8 Object.getOwnPropertySymbols(O)
	  getOwnPropertySymbols: $getOwnPropertySymbols
	});

	// 24.3.2 JSON.stringify(value [, replacer [, space]])
	$JSON && $export($export.S + $export.F * (!useNative || buggyJSON), 'JSON', {stringify: $stringify});

	// 19.4.3.5 Symbol.prototype[@@toStringTag]
	setToStringTag($Symbol, 'Symbol');
	// 20.2.1.9 Math[@@toStringTag]
	setToStringTag(Math, 'Math', true);
	// 24.3.3 JSON[@@toStringTag]
	setToStringTag(global.JSON, 'JSON', true);

/***/ }),
/* 15 */
/***/ (function(module, exports) {

	// https://github.com/zloirock/core-js/issues/86#issuecomment-115759028
	var global = module.exports = typeof window != 'undefined' && window.Math == Math
	  ? window : typeof self != 'undefined' && self.Math == Math ? self : Function('return this')();
	if(typeof __g == 'number')__g = global; // eslint-disable-line no-undef

/***/ }),
/* 16 */
/***/ (function(module, exports) {

	var hasOwnProperty = {}.hasOwnProperty;
	module.exports = function(it, key){
	  return hasOwnProperty.call(it, key);
	};

/***/ }),
/* 17 */
/***/ (function(module, exports, __webpack_require__) {

	// Thank's IE8 for his funny defineProperty
	module.exports = !__webpack_require__(18)(function(){
	  return Object.defineProperty({}, 'a', {get: function(){ return 7; }}).a != 7;
	});

/***/ }),
/* 18 */
/***/ (function(module, exports) {

	module.exports = function(exec){
	  try {
	    return !!exec();
	  } catch(e){
	    return true;
	  }
	};

/***/ }),
/* 19 */
/***/ (function(module, exports, __webpack_require__) {

	var global    = __webpack_require__(15)
	  , core      = __webpack_require__(20)
	  , ctx       = __webpack_require__(21)
	  , PROTOTYPE = 'prototype';

	var $export = function(type, name, source){
	  var IS_FORCED = type & $export.F
	    , IS_GLOBAL = type & $export.G
	    , IS_STATIC = type & $export.S
	    , IS_PROTO  = type & $export.P
	    , IS_BIND   = type & $export.B
	    , IS_WRAP   = type & $export.W
	    , exports   = IS_GLOBAL ? core : core[name] || (core[name] = {})
	    , target    = IS_GLOBAL ? global : IS_STATIC ? global[name] : (global[name] || {})[PROTOTYPE]
	    , key, own, out;
	  if(IS_GLOBAL)source = name;
	  for(key in source){
	    // contains in native
	    own = !IS_FORCED && target && key in target;
	    if(own && key in exports)continue;
	    // export native or passed
	    out = own ? target[key] : source[key];
	    // prevent global pollution for namespaces
	    exports[key] = IS_GLOBAL && typeof target[key] != 'function' ? source[key]
	    // bind timers to global for call from export context
	    : IS_BIND && own ? ctx(out, global)
	    // wrap global constructors for prevent change them in library
	    : IS_WRAP && target[key] == out ? (function(C){
	      var F = function(param){
	        return this instanceof C ? new C(param) : C(param);
	      };
	      F[PROTOTYPE] = C[PROTOTYPE];
	      return F;
	    // make static versions for prototype methods
	    })(out) : IS_PROTO && typeof out == 'function' ? ctx(Function.call, out) : out;
	    if(IS_PROTO)(exports[PROTOTYPE] || (exports[PROTOTYPE] = {}))[key] = out;
	  }
	};
	// type bitmap
	$export.F = 1;  // forced
	$export.G = 2;  // global
	$export.S = 4;  // static
	$export.P = 8;  // proto
	$export.B = 16; // bind
	$export.W = 32; // wrap
	module.exports = $export;

/***/ }),
/* 20 */
/***/ (function(module, exports) {

	var core = module.exports = {version: '1.2.6'};
	if(typeof __e == 'number')__e = core; // eslint-disable-line no-undef

/***/ }),
/* 21 */
/***/ (function(module, exports, __webpack_require__) {

	// optional / simple context binding
	var aFunction = __webpack_require__(22);
	module.exports = function(fn, that, length){
	  aFunction(fn);
	  if(that === undefined)return fn;
	  switch(length){
	    case 1: return function(a){
	      return fn.call(that, a);
	    };
	    case 2: return function(a, b){
	      return fn.call(that, a, b);
	    };
	    case 3: return function(a, b, c){
	      return fn.call(that, a, b, c);
	    };
	  }
	  return function(/* ...args */){
	    return fn.apply(that, arguments);
	  };
	};

/***/ }),
/* 22 */
/***/ (function(module, exports) {

	module.exports = function(it){
	  if(typeof it != 'function')throw TypeError(it + ' is not a function!');
	  return it;
	};

/***/ }),
/* 23 */
/***/ (function(module, exports, __webpack_require__) {

	module.exports = __webpack_require__(24);

/***/ }),
/* 24 */
/***/ (function(module, exports, __webpack_require__) {

	var $          = __webpack_require__(8)
	  , createDesc = __webpack_require__(25);
	module.exports = __webpack_require__(17) ? function(object, key, value){
	  return $.setDesc(object, key, createDesc(1, value));
	} : function(object, key, value){
	  object[key] = value;
	  return object;
	};

/***/ }),
/* 25 */
/***/ (function(module, exports) {

	module.exports = function(bitmap, value){
	  return {
	    enumerable  : !(bitmap & 1),
	    configurable: !(bitmap & 2),
	    writable    : !(bitmap & 4),
	    value       : value
	  };
	};

/***/ }),
/* 26 */
/***/ (function(module, exports, __webpack_require__) {

	var global = __webpack_require__(15)
	  , SHARED = '__core-js_shared__'
	  , store  = global[SHARED] || (global[SHARED] = {});
	module.exports = function(key){
	  return store[key] || (store[key] = {});
	};

/***/ }),
/* 27 */
/***/ (function(module, exports, __webpack_require__) {

	var def = __webpack_require__(8).setDesc
	  , has = __webpack_require__(16)
	  , TAG = __webpack_require__(28)('toStringTag');

	module.exports = function(it, tag, stat){
	  if(it && !has(it = stat ? it : it.prototype, TAG))def(it, TAG, {configurable: true, value: tag});
	};

/***/ }),
/* 28 */
/***/ (function(module, exports, __webpack_require__) {

	var store  = __webpack_require__(26)('wks')
	  , uid    = __webpack_require__(29)
	  , Symbol = __webpack_require__(15).Symbol;
	module.exports = function(name){
	  return store[name] || (store[name] =
	    Symbol && Symbol[name] || (Symbol || uid)('Symbol.' + name));
	};

/***/ }),
/* 29 */
/***/ (function(module, exports) {

	var id = 0
	  , px = Math.random();
	module.exports = function(key){
	  return 'Symbol('.concat(key === undefined ? '' : key, ')_', (++id + px).toString(36));
	};

/***/ }),
/* 30 */
/***/ (function(module, exports, __webpack_require__) {

	var $         = __webpack_require__(8)
	  , toIObject = __webpack_require__(31);
	module.exports = function(object, el){
	  var O      = toIObject(object)
	    , keys   = $.getKeys(O)
	    , length = keys.length
	    , index  = 0
	    , key;
	  while(length > index)if(O[key = keys[index++]] === el)return key;
	};

/***/ }),
/* 31 */
/***/ (function(module, exports, __webpack_require__) {

	// to indexed object, toObject with fallback for non-array-like ES3 strings
	var IObject = __webpack_require__(32)
	  , defined = __webpack_require__(34);
	module.exports = function(it){
	  return IObject(defined(it));
	};

/***/ }),
/* 32 */
/***/ (function(module, exports, __webpack_require__) {

	// fallback for non-array-like ES3 and non-enumerable old V8 strings
	var cof = __webpack_require__(33);
	module.exports = Object('z').propertyIsEnumerable(0) ? Object : function(it){
	  return cof(it) == 'String' ? it.split('') : Object(it);
	};

/***/ }),
/* 33 */
/***/ (function(module, exports) {

	var toString = {}.toString;

	module.exports = function(it){
	  return toString.call(it).slice(8, -1);
	};

/***/ }),
/* 34 */
/***/ (function(module, exports) {

	// 7.2.1 RequireObjectCoercible(argument)
	module.exports = function(it){
	  if(it == undefined)throw TypeError("Can't call method on  " + it);
	  return it;
	};

/***/ }),
/* 35 */
/***/ (function(module, exports, __webpack_require__) {

	// fallback for IE11 buggy Object.getOwnPropertyNames with iframe and window
	var toIObject = __webpack_require__(31)
	  , getNames  = __webpack_require__(8).getNames
	  , toString  = {}.toString;

	var windowNames = typeof window == 'object' && Object.getOwnPropertyNames
	  ? Object.getOwnPropertyNames(window) : [];

	var getWindowNames = function(it){
	  try {
	    return getNames(it);
	  } catch(e){
	    return windowNames.slice();
	  }
	};

	module.exports.get = function getOwnPropertyNames(it){
	  if(windowNames && toString.call(it) == '[object Window]')return getWindowNames(it);
	  return getNames(toIObject(it));
	};

/***/ }),
/* 36 */
/***/ (function(module, exports, __webpack_require__) {

	// all enumerable object keys, includes symbols
	var $ = __webpack_require__(8);
	module.exports = function(it){
	  var keys       = $.getKeys(it)
	    , getSymbols = $.getSymbols;
	  if(getSymbols){
	    var symbols = getSymbols(it)
	      , isEnum  = $.isEnum
	      , i       = 0
	      , key;
	    while(symbols.length > i)if(isEnum.call(it, key = symbols[i++]))keys.push(key);
	  }
	  return keys;
	};

/***/ }),
/* 37 */
/***/ (function(module, exports, __webpack_require__) {

	// 7.2.2 IsArray(argument)
	var cof = __webpack_require__(33);
	module.exports = Array.isArray || function(arg){
	  return cof(arg) == 'Array';
	};

/***/ }),
/* 38 */
/***/ (function(module, exports, __webpack_require__) {

	var isObject = __webpack_require__(39);
	module.exports = function(it){
	  if(!isObject(it))throw TypeError(it + ' is not an object!');
	  return it;
	};

/***/ }),
/* 39 */
/***/ (function(module, exports) {

	module.exports = function(it){
	  return typeof it === 'object' ? it !== null : typeof it === 'function';
	};

/***/ }),
/* 40 */
/***/ (function(module, exports) {

	module.exports = true;

/***/ }),
/* 41 */
/***/ (function(module, exports) {

	

/***/ }),
/* 42 */
/***/ (function(module, exports, __webpack_require__) {

	module.exports = { "default": __webpack_require__(43), __esModule: true };

/***/ }),
/* 43 */
/***/ (function(module, exports, __webpack_require__) {

	__webpack_require__(44);
	__webpack_require__(50);
	module.exports = __webpack_require__(28)('iterator');

/***/ }),
/* 44 */
/***/ (function(module, exports, __webpack_require__) {

	'use strict';
	var $at  = __webpack_require__(45)(true);

	// 21.1.3.27 String.prototype[@@iterator]()
	__webpack_require__(47)(String, 'String', function(iterated){
	  this._t = String(iterated); // target
	  this._i = 0;                // next index
	// 21.1.5.2.1 %StringIteratorPrototype%.next()
	}, function(){
	  var O     = this._t
	    , index = this._i
	    , point;
	  if(index >= O.length)return {value: undefined, done: true};
	  point = $at(O, index);
	  this._i += point.length;
	  return {value: point, done: false};
	});

/***/ }),
/* 45 */
/***/ (function(module, exports, __webpack_require__) {

	var toInteger = __webpack_require__(46)
	  , defined   = __webpack_require__(34);
	// true  -> String#at
	// false -> String#codePointAt
	module.exports = function(TO_STRING){
	  return function(that, pos){
	    var s = String(defined(that))
	      , i = toInteger(pos)
	      , l = s.length
	      , a, b;
	    if(i < 0 || i >= l)return TO_STRING ? '' : undefined;
	    a = s.charCodeAt(i);
	    return a < 0xd800 || a > 0xdbff || i + 1 === l || (b = s.charCodeAt(i + 1)) < 0xdc00 || b > 0xdfff
	      ? TO_STRING ? s.charAt(i) : a
	      : TO_STRING ? s.slice(i, i + 2) : (a - 0xd800 << 10) + (b - 0xdc00) + 0x10000;
	  };
	};

/***/ }),
/* 46 */
/***/ (function(module, exports) {

	// 7.1.4 ToInteger
	var ceil  = Math.ceil
	  , floor = Math.floor;
	module.exports = function(it){
	  return isNaN(it = +it) ? 0 : (it > 0 ? floor : ceil)(it);
	};

/***/ }),
/* 47 */
/***/ (function(module, exports, __webpack_require__) {

	'use strict';
	var LIBRARY        = __webpack_require__(40)
	  , $export        = __webpack_require__(19)
	  , redefine       = __webpack_require__(23)
	  , hide           = __webpack_require__(24)
	  , has            = __webpack_require__(16)
	  , Iterators      = __webpack_require__(48)
	  , $iterCreate    = __webpack_require__(49)
	  , setToStringTag = __webpack_require__(27)
	  , getProto       = __webpack_require__(8).getProto
	  , ITERATOR       = __webpack_require__(28)('iterator')
	  , BUGGY          = !([].keys && 'next' in [].keys()) // Safari has buggy iterators w/o `next`
	  , FF_ITERATOR    = '@@iterator'
	  , KEYS           = 'keys'
	  , VALUES         = 'values';

	var returnThis = function(){ return this; };

	module.exports = function(Base, NAME, Constructor, next, DEFAULT, IS_SET, FORCED){
	  $iterCreate(Constructor, NAME, next);
	  var getMethod = function(kind){
	    if(!BUGGY && kind in proto)return proto[kind];
	    switch(kind){
	      case KEYS: return function keys(){ return new Constructor(this, kind); };
	      case VALUES: return function values(){ return new Constructor(this, kind); };
	    } return function entries(){ return new Constructor(this, kind); };
	  };
	  var TAG        = NAME + ' Iterator'
	    , DEF_VALUES = DEFAULT == VALUES
	    , VALUES_BUG = false
	    , proto      = Base.prototype
	    , $native    = proto[ITERATOR] || proto[FF_ITERATOR] || DEFAULT && proto[DEFAULT]
	    , $default   = $native || getMethod(DEFAULT)
	    , methods, key;
	  // Fix native
	  if($native){
	    var IteratorPrototype = getProto($default.call(new Base));
	    // Set @@toStringTag to native iterators
	    setToStringTag(IteratorPrototype, TAG, true);
	    // FF fix
	    if(!LIBRARY && has(proto, FF_ITERATOR))hide(IteratorPrototype, ITERATOR, returnThis);
	    // fix Array#{values, @@iterator}.name in V8 / FF
	    if(DEF_VALUES && $native.name !== VALUES){
	      VALUES_BUG = true;
	      $default = function values(){ return $native.call(this); };
	    }
	  }
	  // Define iterator
	  if((!LIBRARY || FORCED) && (BUGGY || VALUES_BUG || !proto[ITERATOR])){
	    hide(proto, ITERATOR, $default);
	  }
	  // Plug for library
	  Iterators[NAME] = $default;
	  Iterators[TAG]  = returnThis;
	  if(DEFAULT){
	    methods = {
	      values:  DEF_VALUES  ? $default : getMethod(VALUES),
	      keys:    IS_SET      ? $default : getMethod(KEYS),
	      entries: !DEF_VALUES ? $default : getMethod('entries')
	    };
	    if(FORCED)for(key in methods){
	      if(!(key in proto))redefine(proto, key, methods[key]);
	    } else $export($export.P + $export.F * (BUGGY || VALUES_BUG), NAME, methods);
	  }
	  return methods;
	};

/***/ }),
/* 48 */
/***/ (function(module, exports) {

	module.exports = {};

/***/ }),
/* 49 */
/***/ (function(module, exports, __webpack_require__) {

	'use strict';
	var $              = __webpack_require__(8)
	  , descriptor     = __webpack_require__(25)
	  , setToStringTag = __webpack_require__(27)
	  , IteratorPrototype = {};

	// 25.1.2.1.1 %IteratorPrototype%[@@iterator]()
	__webpack_require__(24)(IteratorPrototype, __webpack_require__(28)('iterator'), function(){ return this; });

	module.exports = function(Constructor, NAME, next){
	  Constructor.prototype = $.create(IteratorPrototype, {next: descriptor(1, next)});
	  setToStringTag(Constructor, NAME + ' Iterator');
	};

/***/ }),
/* 50 */
/***/ (function(module, exports, __webpack_require__) {

	__webpack_require__(51);
	var Iterators = __webpack_require__(48);
	Iterators.NodeList = Iterators.HTMLCollection = Iterators.Array;

/***/ }),
/* 51 */
/***/ (function(module, exports, __webpack_require__) {

	'use strict';
	var addToUnscopables = __webpack_require__(52)
	  , step             = __webpack_require__(53)
	  , Iterators        = __webpack_require__(48)
	  , toIObject        = __webpack_require__(31);

	// 22.1.3.4 Array.prototype.entries()
	// 22.1.3.13 Array.prototype.keys()
	// 22.1.3.29 Array.prototype.values()
	// 22.1.3.30 Array.prototype[@@iterator]()
	module.exports = __webpack_require__(47)(Array, 'Array', function(iterated, kind){
	  this._t = toIObject(iterated); // target
	  this._i = 0;                   // next index
	  this._k = kind;                // kind
	// 22.1.5.2.1 %ArrayIteratorPrototype%.next()
	}, function(){
	  var O     = this._t
	    , kind  = this._k
	    , index = this._i++;
	  if(!O || index >= O.length){
	    this._t = undefined;
	    return step(1);
	  }
	  if(kind == 'keys'  )return step(0, index);
	  if(kind == 'values')return step(0, O[index]);
	  return step(0, [index, O[index]]);
	}, 'values');

	// argumentsList[@@iterator] is %ArrayProto_values% (9.4.4.6, 9.4.4.7)
	Iterators.Arguments = Iterators.Array;

	addToUnscopables('keys');
	addToUnscopables('values');
	addToUnscopables('entries');

/***/ }),
/* 52 */
/***/ (function(module, exports) {

	module.exports = function(){ /* empty */ };

/***/ }),
/* 53 */
/***/ (function(module, exports) {

	module.exports = function(done, value){
	  return {value: value, done: !!done};
	};

/***/ }),
/* 54 */
/***/ (function(module, exports, __webpack_require__) {

	module.exports = { "default": __webpack_require__(55), __esModule: true };

/***/ }),
/* 55 */
/***/ (function(module, exports, __webpack_require__) {

	__webpack_require__(50);
	__webpack_require__(44);
	module.exports = __webpack_require__(56);

/***/ }),
/* 56 */
/***/ (function(module, exports, __webpack_require__) {

	var anObject = __webpack_require__(38)
	  , get      = __webpack_require__(57);
	module.exports = __webpack_require__(20).getIterator = function(it){
	  var iterFn = get(it);
	  if(typeof iterFn != 'function')throw TypeError(it + ' is not iterable!');
	  return anObject(iterFn.call(it));
	};

/***/ }),
/* 57 */
/***/ (function(module, exports, __webpack_require__) {

	var classof   = __webpack_require__(58)
	  , ITERATOR  = __webpack_require__(28)('iterator')
	  , Iterators = __webpack_require__(48);
	module.exports = __webpack_require__(20).getIteratorMethod = function(it){
	  if(it != undefined)return it[ITERATOR]
	    || it['@@iterator']
	    || Iterators[classof(it)];
	};

/***/ }),
/* 58 */
/***/ (function(module, exports, __webpack_require__) {

	// getting tag from 19.1.3.6 Object.prototype.toString()
	var cof = __webpack_require__(33)
	  , TAG = __webpack_require__(28)('toStringTag')
	  // ES3 wrong here
	  , ARG = cof(function(){ return arguments; }()) == 'Arguments';

	module.exports = function(it){
	  var O, T, B;
	  return it === undefined ? 'Undefined' : it === null ? 'Null'
	    // @@toStringTag case
	    : typeof (T = (O = Object(it))[TAG]) == 'string' ? T
	    // builtinTag case
	    : ARG ? cof(O)
	    // ES3 arguments fallback
	    : (B = cof(O)) == 'Object' && typeof O.callee == 'function' ? 'Arguments' : B;
	};

/***/ }),
/* 59 */
/***/ (function(module, exports, __webpack_require__) {

	module.exports = { "default": __webpack_require__(60), __esModule: true };

/***/ }),
/* 60 */
/***/ (function(module, exports, __webpack_require__) {

	__webpack_require__(61);
	module.exports = __webpack_require__(20).Object.keys;

/***/ }),
/* 61 */
/***/ (function(module, exports, __webpack_require__) {

	// 19.1.2.14 Object.keys(O)
	var toObject = __webpack_require__(62);

	__webpack_require__(63)('keys', function($keys){
	  return function keys(it){
	    return $keys(toObject(it));
	  };
	});

/***/ }),
/* 62 */
/***/ (function(module, exports, __webpack_require__) {

	// 7.1.13 ToObject(argument)
	var defined = __webpack_require__(34);
	module.exports = function(it){
	  return Object(defined(it));
	};

/***/ }),
/* 63 */
/***/ (function(module, exports, __webpack_require__) {

	// most Object methods by ES6 should accept primitives
	var $export = __webpack_require__(19)
	  , core    = __webpack_require__(20)
	  , fails   = __webpack_require__(18);
	module.exports = function(KEY, exec){
	  var fn  = (core.Object || {})[KEY] || Object[KEY]
	    , exp = {};
	  exp[KEY] = exec(fn);
	  $export($export.S + $export.F * fails(function(){ fn(1); }), 'Object', exp);
	};

/***/ }),
/* 64 */
/***/ (function(module, exports, __webpack_require__) {

	'use strict';

	var _interopRequireDefault = __webpack_require__(2)['default'];

	exports.__esModule = true;

	var _exception = __webpack_require__(5);

	var _exception2 = _interopRequireDefault(_exception);

	exports['default'] = function (instance) {
	  instance.registerHelper('helperMissing', function () /* [args, ]options */{
	    if (arguments.length === 1) {
	      // A missing field in a {{foo}} construct.
	      return undefined;
	    } else {
	      // Someone is actually trying to call something, blow up.
	      throw new _exception2['default']('Missing helper: "' + arguments[arguments.length - 1].name + '"');
	    }
	  });
	};

	module.exports = exports['default'];

/***/ }),
/* 65 */
/***/ (function(module, exports, __webpack_require__) {

	'use strict';

	var _interopRequireDefault = __webpack_require__(2)['default'];

	exports.__esModule = true;

	var _utils = __webpack_require__(4);

	var _exception = __webpack_require__(5);

	var _exception2 = _interopRequireDefault(_exception);

	exports['default'] = function (instance) {
	  instance.registerHelper('if', function (conditional, options) {
	    if (arguments.length != 2) {
	      throw new _exception2['default']('#if requires exactly one argument');
	    }
	    if (_utils.isFunction(conditional)) {
	      conditional = conditional.call(this);
	    }

	    // Default behavior is to render the positive path if the value is truthy and not empty.
	    // The `includeZero` option may be set to treat the condtional as purely not empty based on the
	    // behavior of isEmpty. Effectively this determines if 0 is handled by the positive path or negative.
	    if (!options.hash.includeZero && !conditional || _utils.isEmpty(conditional)) {
	      return options.inverse(this);
	    } else {
	      return options.fn(this);
	    }
	  });

	  instance.registerHelper('unless', function (conditional, options) {
	    if (arguments.length != 2) {
	      throw new _exception2['default']('#unless requires exactly one argument');
	    }
	    return instance.helpers['if'].call(this, conditional, {
	      fn: options.inverse,
	      inverse: options.fn,
	      hash: options.hash
	    });
	  });
	};

	module.exports = exports['default'];

/***/ }),
/* 66 */
/***/ (function(module, exports) {

	'use strict';

	exports.__esModule = true;

	exports['default'] = function (instance) {
	  instance.registerHelper('log', function () /* message, options */{
	    var args = [undefined],
	        options = arguments[arguments.length - 1];
	    for (var i = 0; i < arguments.length - 1; i++) {
	      args.push(arguments[i]);
	    }

	    var level = 1;
	    if (options.hash.level != null) {
	      level = options.hash.level;
	    } else if (options.data && options.data.level != null) {
	      level = options.data.level;
	    }
	    args[0] = level;

	    instance.log.apply(instance, args);
	  });
	};

	module.exports = exports['default'];

/***/ }),
/* 67 */
/***/ (function(module, exports) {

	'use strict';

	exports.__esModule = true;

	exports['default'] = function (instance) {
	  instance.registerHelper('lookup', function (obj, field, options) {
	    if (!obj) {
	      // Note for 5.0: Change to "obj == null" in 5.0
	      return obj;
	    }
	    return options.lookupProperty(obj, field);
	  });
	};

	module.exports = exports['default'];

/***/ }),
/* 68 */
/***/ (function(module, exports, __webpack_require__) {

	'use strict';

	var _interopRequireDefault = __webpack_require__(2)['default'];

	exports.__esModule = true;

	var _utils = __webpack_require__(4);

	var _exception = __webpack_require__(5);

	var _exception2 = _interopRequireDefault(_exception);

	exports['default'] = function (instance) {
	  instance.registerHelper('with', function (context, options) {
	    if (arguments.length != 2) {
	      throw new _exception2['default']('#with requires exactly one argument');
	    }
	    if (_utils.isFunction(context)) {
	      context = context.call(this);
	    }

	    var fn = options.fn;

	    if (!_utils.isEmpty(context)) {
	      var data = options.data;
	      if (options.data && options.ids) {
	        data = _utils.createFrame(options.data);
	        data.contextPath = _utils.appendContextPath(options.data.contextPath, options.ids[0]);
	      }

	      return fn(context, {
	        data: data,
	        blockParams: _utils.blockParams([context], [data && data.contextPath])
	      });
	    } else {
	      return options.inverse(this);
	    }
	  });
	};

	module.exports = exports['default'];

/***/ }),
/* 69 */
/***/ (function(module, exports, __webpack_require__) {

	'use strict';

	var _interopRequireDefault = __webpack_require__(2)['default'];

	exports.__esModule = true;
	exports.registerDefaultDecorators = registerDefaultDecorators;

	var _decoratorsInline = __webpack_require__(70);

	var _decoratorsInline2 = _interopRequireDefault(_decoratorsInline);

	function registerDefaultDecorators(instance) {
	  _decoratorsInline2['default'](instance);
	}

/***/ }),
/* 70 */
/***/ (function(module, exports, __webpack_require__) {

	'use strict';

	exports.__esModule = true;

	var _utils = __webpack_require__(4);

	exports['default'] = function (instance) {
	  instance.registerDecorator('inline', function (fn, props, container, options) {
	    var ret = fn;
	    if (!props.partials) {
	      props.partials = {};
	      ret = function (context, options) {
	        // Create a new partials stack frame prior to exec.
	        var original = container.partials;
	        container.partials = _utils.extend({}, original, props.partials);
	        var ret = fn(context, options);
	        container.partials = original;
	        return ret;
	      };
	    }

	    props.partials[options.args[0]] = options.fn;

	    return ret;
	  });
	};

	module.exports = exports['default'];

/***/ }),
/* 71 */
/***/ (function(module, exports, __webpack_require__) {

	'use strict';

	exports.__esModule = true;

	var _utils = __webpack_require__(4);

	var logger = {
	  methodMap: ['debug', 'info', 'warn', 'error'],
	  level: 'info',

	  // Maps a given level value to the `methodMap` indexes above.
	  lookupLevel: function lookupLevel(level) {
	    if (typeof level === 'string') {
	      var levelMap = _utils.indexOf(logger.methodMap, level.toLowerCase());
	      if (levelMap >= 0) {
	        level = levelMap;
	      } else {
	        level = parseInt(level, 10);
	      }
	    }

	    return level;
	  },

	  // Can be overridden in the host environment
	  log: function log(level) {
	    level = logger.lookupLevel(level);

	    if (typeof console !== 'undefined' && logger.lookupLevel(logger.level) <= level) {
	      var method = logger.methodMap[level];
	      // eslint-disable-next-line no-console
	      if (!console[method]) {
	        method = 'log';
	      }

	      for (var _len = arguments.length, message = Array(_len > 1 ? _len - 1 : 0), _key = 1; _key < _len; _key++) {
	        message[_key - 1] = arguments[_key];
	      }

	      console[method].apply(console, message); // eslint-disable-line no-console
	    }
	  }
	};

	exports['default'] = logger;
	module.exports = exports['default'];

/***/ }),
/* 72 */
/***/ (function(module, exports, __webpack_require__) {

	'use strict';

	var _Object$create = __webpack_require__(73)['default'];

	var _Object$keys = __webpack_require__(59)['default'];

	var _interopRequireDefault = __webpack_require__(2)['default'];

	exports.__esModule = true;
	exports.createProtoAccessControl = createProtoAccessControl;
	exports.resultIsAllowed = resultIsAllowed;
	exports.resetLoggedProperties = resetLoggedProperties;

	var _createNewLookupObject = __webpack_require__(75);

	var _logger = __webpack_require__(71);

	var _logger2 = _interopRequireDefault(_logger);

	var loggedProperties = _Object$create(null);

	function createProtoAccessControl(runtimeOptions) {
	  var defaultMethodWhiteList = _Object$create(null);
	  defaultMethodWhiteList['constructor'] = false;
	  defaultMethodWhiteList['__defineGetter__'] = false;
	  defaultMethodWhiteList['__defineSetter__'] = false;
	  defaultMethodWhiteList['__lookupGetter__'] = false;

	  var defaultPropertyWhiteList = _Object$create(null);
	  // eslint-disable-next-line no-proto
	  defaultPropertyWhiteList['__proto__'] = false;

	  return {
	    properties: {
	      whitelist: _createNewLookupObject.createNewLookupObject(defaultPropertyWhiteList, runtimeOptions.allowedProtoProperties),
	      defaultValue: runtimeOptions.allowProtoPropertiesByDefault
	    },
	    methods: {
	      whitelist: _createNewLookupObject.createNewLookupObject(defaultMethodWhiteList, runtimeOptions.allowedProtoMethods),
	      defaultValue: runtimeOptions.allowProtoMethodsByDefault
	    }
	  };
	}

	function resultIsAllowed(result, protoAccessControl, propertyName) {
	  if (typeof result === 'function') {
	    return checkWhiteList(protoAccessControl.methods, propertyName);
	  } else {
	    return checkWhiteList(protoAccessControl.properties, propertyName);
	  }
	}

	function checkWhiteList(protoAccessControlForType, propertyName) {
	  if (protoAccessControlForType.whitelist[propertyName] !== undefined) {
	    return protoAccessControlForType.whitelist[propertyName] === true;
	  }
	  if (protoAccessControlForType.defaultValue !== undefined) {
	    return protoAccessControlForType.defaultValue;
	  }
	  logUnexpecedPropertyAccessOnce(propertyName);
	  return false;
	}

	function logUnexpecedPropertyAccessOnce(propertyName) {
	  if (loggedProperties[propertyName] !== true) {
	    loggedProperties[propertyName] = true;
	    _logger2['default'].log('error', 'Handlebars: Access has been denied to resolve the property "' + propertyName + '" because it is not an "own property" of its parent.\n' + 'You can add a runtime option to disable the check or this warning:\n' + 'See https://handlebarsjs.com/api-reference/runtime-options.html#options-to-control-prototype-access for details');
	  }
	}

	function resetLoggedProperties() {
	  _Object$keys(loggedProperties).forEach(function (propertyName) {
	    delete loggedProperties[propertyName];
	  });
	}

/***/ }),
/* 73 */
/***/ (function(module, exports, __webpack_require__) {

	module.exports = { "default": __webpack_require__(74), __esModule: true };

/***/ }),
/* 74 */
/***/ (function(module, exports, __webpack_require__) {

	var $ = __webpack_require__(8);
	module.exports = function create(P, D){
	  return $.create(P, D);
	};

/***/ }),
/* 75 */
/***/ (function(module, exports, __webpack_require__) {

	'use strict';

	var _Object$create = __webpack_require__(73)['default'];

	exports.__esModule = true;
	exports.createNewLookupObject = createNewLookupObject;

	var _utils = __webpack_require__(4);

	/**
	 * Create a new object with "null"-prototype to avoid truthy results on prototype properties.
	 * The resulting object can be used with "object[property]" to check if a property exists
	 * @param {...object} sources a varargs parameter of source objects that will be merged
	 * @returns {object}
	 */

	function createNewLookupObject() {
	  for (var _len = arguments.length, sources = Array(_len), _key = 0; _key < _len; _key++) {
	    sources[_key] = arguments[_key];
	  }

	  return _utils.extend.apply(undefined, [_Object$create(null)].concat(sources));
	}

/***/ }),
/* 76 */
/***/ (function(module, exports) {

	// Build out our basic SafeString type
	'use strict';

	exports.__esModule = true;
	function SafeString(string) {
	  this.string = string;
	}

	SafeString.prototype.toString = SafeString.prototype.toHTML = function () {
	  return '' + this.string;
	};

	exports['default'] = SafeString;
	module.exports = exports['default'];

/***/ }),
/* 77 */
/***/ (function(module, exports, __webpack_require__) {

	'use strict';

	var _Object$seal = __webpack_require__(78)['default'];

	var _Object$keys = __webpack_require__(59)['default'];

	var _interopRequireWildcard = __webpack_require__(1)['default'];

	var _interopRequireDefault = __webpack_require__(2)['default'];

	exports.__esModule = true;
	exports.checkRevision = checkRevision;
	exports.template = template;
	exports.wrapProgram = wrapProgram;
	exports.resolvePartial = resolvePartial;
	exports.invokePartial = invokePartial;
	exports.noop = noop;

	var _utils = __webpack_require__(4);

	var Utils = _interopRequireWildcard(_utils);

	var _exception = __webpack_require__(5);

	var _exception2 = _interopRequireDefault(_exception);

	var _base = __webpack_require__(3);

	var _helpers = __webpack_require__(9);

	var _internalWrapHelper = __webpack_require__(81);

	var _internalProtoAccess = __webpack_require__(72);

	function checkRevision(compilerInfo) {
	  var compilerRevision = compilerInfo && compilerInfo[0] || 1,
	      currentRevision = _base.COMPILER_REVISION;

	  if (compilerRevision >= _base.LAST_COMPATIBLE_COMPILER_REVISION && compilerRevision <= _base.COMPILER_REVISION) {
	    return;
	  }

	  if (compilerRevision < _base.LAST_COMPATIBLE_COMPILER_REVISION) {
	    var runtimeVersions = _base.REVISION_CHANGES[currentRevision],
	        compilerVersions = _base.REVISION_CHANGES[compilerRevision];
	    throw new _exception2['default']('Template was precompiled with an older version of Handlebars than the current runtime. ' + 'Please update your precompiler to a newer version (' + runtimeVersions + ') or downgrade your runtime to an older version (' + compilerVersions + ').');
	  } else {
	    // Use the embedded version info since the runtime doesn't know about this revision yet
	    throw new _exception2['default']('Template was precompiled with a newer version of Handlebars than the current runtime. ' + 'Please update your runtime to a newer version (' + compilerInfo[1] + ').');
	  }
	}

	function template(templateSpec, env) {
	  /* istanbul ignore next */
	  if (!env) {
	    throw new _exception2['default']('No environment passed to template');
	  }
	  if (!templateSpec || !templateSpec.main) {
	    throw new _exception2['default']('Unknown template object: ' + typeof templateSpec);
	  }

	  templateSpec.main.decorator = templateSpec.main_d;

	  // Note: Using env.VM references rather than local var references throughout this section to allow
	  // for external users to override these as pseudo-supported APIs.
	  env.VM.checkRevision(templateSpec.compiler);

	  // backwards compatibility for precompiled templates with compiler-version 7 (<4.3.0)
	  var templateWasPrecompiledWithCompilerV7 = templateSpec.compiler && templateSpec.compiler[0] === 7;

	  function invokePartialWrapper(partial, context, options) {
	    if (options.hash) {
	      context = Utils.extend({}, context, options.hash);
	      if (options.ids) {
	        options.ids[0] = true;
	      }
	    }
	    partial = env.VM.resolvePartial.call(this, partial, context, options);

	    var extendedOptions = Utils.extend({}, options, {
	      hooks: this.hooks,
	      protoAccessControl: this.protoAccessControl
	    });

	    var result = env.VM.invokePartial.call(this, partial, context, extendedOptions);

	    if (result == null && env.compile) {
	      options.partials[options.name] = env.compile(partial, templateSpec.compilerOptions, env);
	      result = options.partials[options.name](context, extendedOptions);
	    }
	    if (result != null) {
	      if (options.indent) {
	        var lines = result.split('\n');
	        for (var i = 0, l = lines.length; i < l; i++) {
	          if (!lines[i] && i + 1 === l) {
	            break;
	          }

	          lines[i] = options.indent + lines[i];
	        }
	        result = lines.join('\n');
	      }
	      return result;
	    } else {
	      throw new _exception2['default']('The partial ' + options.name + ' could not be compiled when running in runtime-only mode');
	    }
	  }

	  // Just add water
	  var container = {
	    strict: function strict(obj, name, loc) {
	      if (!obj || !(name in obj)) {
	        throw new _exception2['default']('"' + name + '" not defined in ' + obj, {
	          loc: loc
	        });
	      }
	      return container.lookupProperty(obj, name);
	    },
	    lookupProperty: function lookupProperty(parent, propertyName) {
	      var result = parent[propertyName];
	      if (result == null) {
	        return result;
	      }
	      if (Object.prototype.hasOwnProperty.call(parent, propertyName)) {
	        return result;
	      }

	      if (_internalProtoAccess.resultIsAllowed(result, container.protoAccessControl, propertyName)) {
	        return result;
	      }
	      return undefined;
	    },
	    lookup: function lookup(depths, name) {
	      var len = depths.length;
	      for (var i = 0; i < len; i++) {
	        var result = depths[i] && container.lookupProperty(depths[i], name);
	        if (result != null) {
	          return depths[i][name];
	        }
	      }
	    },
	    lambda: function lambda(current, context) {
	      return typeof current === 'function' ? current.call(context) : current;
	    },

	    escapeExpression: Utils.escapeExpression,
	    invokePartial: invokePartialWrapper,

	    fn: function fn(i) {
	      var ret = templateSpec[i];
	      ret.decorator = templateSpec[i + '_d'];
	      return ret;
	    },

	    programs: [],
	    program: function program(i, data, declaredBlockParams, blockParams, depths) {
	      var programWrapper = this.programs[i],
	          fn = this.fn(i);
	      if (data || depths || blockParams || declaredBlockParams) {
	        programWrapper = wrapProgram(this, i, fn, data, declaredBlockParams, blockParams, depths);
	      } else if (!programWrapper) {
	        programWrapper = this.programs[i] = wrapProgram(this, i, fn);
	      }
	      return programWrapper;
	    },

	    data: function data(value, depth) {
	      while (value && depth--) {
	        value = value._parent;
	      }
	      return value;
	    },
	    mergeIfNeeded: function mergeIfNeeded(param, common) {
	      var obj = param || common;

	      if (param && common && param !== common) {
	        obj = Utils.extend({}, common, param);
	      }

	      return obj;
	    },
	    // An empty object to use as replacement for null-contexts
	    nullContext: _Object$seal({}),

	    noop: env.VM.noop,
	    compilerInfo: templateSpec.compiler
	  };

	  function ret(context) {
	    var options = arguments.length <= 1 || arguments[1] === undefined ? {} : arguments[1];

	    var data = options.data;

	    ret._setup(options);
	    if (!options.partial && templateSpec.useData) {
	      data = initData(context, data);
	    }
	    var depths = undefined,
	        blockParams = templateSpec.useBlockParams ? [] : undefined;
	    if (templateSpec.useDepths) {
	      if (options.depths) {
	        depths = context != options.depths[0] ? [context].concat(options.depths) : options.depths;
	      } else {
	        depths = [context];
	      }
	    }

	    function main(context /*, options*/) {
	      return '' + templateSpec.main(container, context, container.helpers, container.partials, data, blockParams, depths);
	    }

	    main = executeDecorators(templateSpec.main, main, container, options.depths || [], data, blockParams);
	    return main(context, options);
	  }

	  ret.isTop = true;

	  ret._setup = function (options) {
	    if (!options.partial) {
	      var mergedHelpers = Utils.extend({}, env.helpers, options.helpers);
	      wrapHelpersToPassLookupProperty(mergedHelpers, container);
	      container.helpers = mergedHelpers;

	      if (templateSpec.usePartial) {
	        // Use mergeIfNeeded here to prevent compiling global partials multiple times
	        container.partials = container.mergeIfNeeded(options.partials, env.partials);
	      }
	      if (templateSpec.usePartial || templateSpec.useDecorators) {
	        container.decorators = Utils.extend({}, env.decorators, options.decorators);
	      }

	      container.hooks = {};
	      container.protoAccessControl = _internalProtoAccess.createProtoAccessControl(options);

	      var keepHelperInHelpers = options.allowCallsToHelperMissing || templateWasPrecompiledWithCompilerV7;
	      _helpers.moveHelperToHooks(container, 'helperMissing', keepHelperInHelpers);
	      _helpers.moveHelperToHooks(container, 'blockHelperMissing', keepHelperInHelpers);
	    } else {
	      container.protoAccessControl = options.protoAccessControl; // internal option
	      container.helpers = options.helpers;
	      container.partials = options.partials;
	      container.decorators = options.decorators;
	      container.hooks = options.hooks;
	    }
	  };

	  ret._child = function (i, data, blockParams, depths) {
	    if (templateSpec.useBlockParams && !blockParams) {
	      throw new _exception2['default']('must pass block params');
	    }
	    if (templateSpec.useDepths && !depths) {
	      throw new _exception2['default']('must pass parent depths');
	    }

	    return wrapProgram(container, i, templateSpec[i], data, 0, blockParams, depths);
	  };
	  return ret;
	}

	function wrapProgram(container, i, fn, data, declaredBlockParams, blockParams, depths) {
	  function prog(context) {
	    var options = arguments.length <= 1 || arguments[1] === undefined ? {} : arguments[1];

	    var currentDepths = depths;
	    if (depths && context != depths[0] && !(context === container.nullContext && depths[0] === null)) {
	      currentDepths = [context].concat(depths);
	    }

	    return fn(container, context, container.helpers, container.partials, options.data || data, blockParams && [options.blockParams].concat(blockParams), currentDepths);
	  }

	  prog = executeDecorators(fn, prog, container, depths, data, blockParams);

	  prog.program = i;
	  prog.depth = depths ? depths.length : 0;
	  prog.blockParams = declaredBlockParams || 0;
	  return prog;
	}

	/**
	 * This is currently part of the official API, therefore implementation details should not be changed.
	 */

	function resolvePartial(partial, context, options) {
	  if (!partial) {
	    if (options.name === '@partial-block') {
	      partial = options.data['partial-block'];
	    } else {
	      partial = options.partials[options.name];
	    }
	  } else if (!partial.call && !options.name) {
	    // This is a dynamic partial that returned a string
	    options.name = partial;
	    partial = options.partials[partial];
	  }
	  return partial;
	}

	function invokePartial(partial, context, options) {
	  // Use the current closure context to save the partial-block if this partial
	  var currentPartialBlock = options.data && options.data['partial-block'];
	  options.partial = true;
	  if (options.ids) {
	    options.data.contextPath = options.ids[0] || options.data.contextPath;
	  }

	  var partialBlock = undefined;
	  if (options.fn && options.fn !== noop) {
	    (function () {
	      options.data = _base.createFrame(options.data);
	      // Wrapper function to get access to currentPartialBlock from the closure
	      var fn = options.fn;
	      partialBlock = options.data['partial-block'] = function partialBlockWrapper(context) {
	        var options = arguments.length <= 1 || arguments[1] === undefined ? {} : arguments[1];

	        // Restore the partial-block from the closure for the execution of the block
	        // i.e. the part inside the block of the partial call.
	        options.data = _base.createFrame(options.data);
	        options.data['partial-block'] = currentPartialBlock;
	        return fn(context, options);
	      };
	      if (fn.partials) {
	        options.partials = Utils.extend({}, options.partials, fn.partials);
	      }
	    })();
	  }

	  if (partial === undefined && partialBlock) {
	    partial = partialBlock;
	  }

	  if (partial === undefined) {
	    throw new _exception2['default']('The partial ' + options.name + ' could not be found');
	  } else if (partial instanceof Function) {
	    return partial(context, options);
	  }
	}

	function noop() {
	  return '';
	}

	function initData(context, data) {
	  if (!data || !('root' in data)) {
	    data = data ? _base.createFrame(data) : {};
	    data.root = context;
	  }
	  return data;
	}

	function executeDecorators(fn, prog, container, depths, data, blockParams) {
	  if (fn.decorator) {
	    var props = {};
	    prog = fn.decorator(prog, props, container, depths && depths[0], data, blockParams, depths);
	    Utils.extend(prog, props);
	  }
	  return prog;
	}

	function wrapHelpersToPassLookupProperty(mergedHelpers, container) {
	  _Object$keys(mergedHelpers).forEach(function (helperName) {
	    var helper = mergedHelpers[helperName];
	    mergedHelpers[helperName] = passLookupPropertyOption(helper, container);
	  });
	}

	function passLookupPropertyOption(helper, container) {
	  var lookupProperty = container.lookupProperty;
	  return _internalWrapHelper.wrapHelper(helper, function (options) {
	    return Utils.extend({ lookupProperty: lookupProperty }, options);
	  });
	}

/***/ }),
/* 78 */
/***/ (function(module, exports, __webpack_require__) {

	module.exports = { "default": __webpack_require__(79), __esModule: true };

/***/ }),
/* 79 */
/***/ (function(module, exports, __webpack_require__) {

	__webpack_require__(80);
	module.exports = __webpack_require__(20).Object.seal;

/***/ }),
/* 80 */
/***/ (function(module, exports, __webpack_require__) {

	// 19.1.2.17 Object.seal(O)
	var isObject = __webpack_require__(39);

	__webpack_require__(63)('seal', function($seal){
	  return function seal(it){
	    return $seal && isObject(it) ? $seal(it) : it;
	  };
	});

/***/ }),
/* 81 */
/***/ (function(module, exports) {

	'use strict';

	exports.__esModule = true;
	exports.wrapHelper = wrapHelper;

	function wrapHelper(helper, transformOptionsFn) {
	  if (typeof helper !== 'function') {
	    // This should not happen, but apparently it does in https://github.com/wycats/handlebars.js/issues/1639
	    // We try to make the wrapper least-invasive by not wrapping it, if the helper is not a function.
	    return helper;
	  }
	  var wrapper = function wrapper() /* dynamic arguments */{
	    var options = arguments[arguments.length - 1];
	    arguments[arguments.length - 1] = transformOptionsFn(options);
	    return helper.apply(this, arguments);
	  };
	  return wrapper;
	}

/***/ }),
/* 82 */
/***/ (function(module, exports) {

	/* global globalThis */
	'use strict';

	exports.__esModule = true;

	exports['default'] = function (Handlebars) {
	  /* istanbul ignore next */
	  // https://mathiasbynens.be/notes/globalthis
	  (function () {
	    if (typeof globalThis === 'object') return;
	    Object.prototype.__defineGetter__('__magic__', function () {
	      return this;
	    });
	    __magic__.globalThis = __magic__; // eslint-disable-line no-undef
	    delete Object.prototype.__magic__;
	  })();

	  var $Handlebars = globalThis.Handlebars;

	  /* istanbul ignore next */
	  Handlebars.noConflict = function () {
	    if (globalThis.Handlebars === Handlebars) {
	      globalThis.Handlebars = $Handlebars;
	    }
	    return Handlebars;
	  };
	};

	module.exports = exports['default'];

/***/ })
/******/ ])
});
;
/* global Handlebars */
/* global translatedAssetLanguages */
/* global staticBreadcrumbDetails */
/* global facetDetails */

'use strict';

Handlebars.registerHelper('ifIn', function (elem, list, options) {
	if (list && list.indexOf(elem) > -1) {
		return options.fn(this);
	}
	return options.inverse(this);
});

Handlebars.registerHelper('ifNotIn', function (elem, list, options) {
	if (list && list.indexOf(elem) > -1) {
		return options.inverse(this);
	}
	return options.fn(this);
});

Handlebars.registerHelper('ifOr', function (v1, v2, v3, options) {
	if (v1 || v2 || v3) {
		return options.fn(this);
	}
	return options.inverse(this);
});

Handlebars.registerHelper('xif', function (expression, options) {
	return Handlebars.helpers['x'].apply(this, [expression, options]) ? options.fn(this) : options.inverse(this);
});

Handlebars.registerHelper('x', function (expression, options) {
	/* jshint unused: false */
	var fn = function () {
	}, result;
	try {
		fn = Function.apply(this, ['window', 'return ' + expression + ' ;']);
	} catch (e) {
		console.warn('{{x ' + expression + '}} has invalid javascript', e);
	}

	try {
		result = fn.call(this, window);
	} catch (e) {
		console.warn('{{x ' + expression + '}} hit a runtime error', e);
	}
	return result;
});

var lastValue = '';
Handlebars.registerHelper('setValue', function (name, context) {
	/* jshint unused: false */
	lastValue = name;
});

Handlebars.registerHelper('getValueIfNotPrevious', function (name, value, context) {
	/* jshint unused: false */
	if (lastValue !== name) {
		return name;
	}
	return '';
});

var hbIndex = 1;
Handlebars.registerHelper('getIndex', function (context) {
	/* jshint unused: false */
	return hbIndex++;
});

function getFormattedMonth(month) {
	// Validating for empty characters before getting the desired string for Month in IE and Edge
	if (/[A-Za-z]/.test(month.split('')[0])) {
		return month.substring(0, 3); // other browsers
	} else {
		return month.substring(1, 4); // IE and Edge - split() is adding an empty char at the beginning and end
	}
}

/* Deprecated - use formatDate instead */
Handlebars.registerHelper('formatDateByLanguage', function (language, date, datetime, timeonly, timezoneonly) {
	let showDate = false;
	if (!datetime && !timeonly && !timezoneonly) {
		showDate = true;
	}
	return Handlebars.helpers.formatDate(language, date, showDate || datetime, datetime || timeonly, datetime || timezoneonly);
});

Handlebars.registerHelper('formatDate', function (language, date, showDate, showTime, showTimeZone) {
	let dateToFormat = new Date(date),
		formattedDate = '', splitDate, options;

	if (showDate === true || showTime === true) {
		if (showDate === true && showTime === true) {
			options = {year: 'numeric', month: 'short', day: 'numeric', hour: 'numeric', minute: 'numeric'};
		} else if (showTime === true) {
			options = {hour: 'numeric', minute: 'numeric'};
		} else { // showDate === true
			options = {year: 'numeric', month: 'short', day: 'numeric'};
		}

		if (language === 'zh') {
			formattedDate = Intl.DateTimeFormat('zh-CN', options).format(dateToFormat);
		} else if (language === 'ja') {
			formattedDate = Intl.DateTimeFormat('ja-JP', options).format(dateToFormat);
		} else if (language === 'ko') {
			formattedDate = Intl.DateTimeFormat('ko-KR', options).format(dateToFormat);
		} else if (language === 'fr') {
			if (options.month) {
				options.month = 'long';
			}
			formattedDate = Intl.DateTimeFormat('fr-FR', options).format(dateToFormat);
			if (formattedDate.includes(' à ')) {
				formattedDate = formattedDate.replace(' à', ',');
			}
		} else if (language === 'it') {
			//Returned date is in a different format for IE and Edge when compared to other browsers. Hence the 'replace'
			formattedDate = Intl.DateTimeFormat('it-IT', options).format(dateToFormat).replace(/\//g, ' ');
		} else if (language === 'de') {
			if (options.month) {
				options.month = 'long';
				splitDate = Intl.DateTimeFormat('de-DE', options).format(dateToFormat).replace('.', '').split(' ');
				splitDate[1] = getFormattedMonth(splitDate[1]);
				if (splitDate[3] === 'um') {
					splitDate.splice(3, 1);
					splitDate[2] += ',';
				}
				formattedDate = splitDate.join(' ');
			} else {
				formattedDate = Intl.DateTimeFormat('de-DE', options).format(dateToFormat).replace('.', '').split(' ');
			}
		} else if (language === 'es') {
			if (options.month) {
				options.month = 'long';
				splitDate = Intl.DateTimeFormat('es-ES', options).format(dateToFormat).split(' de ');
				splitDate[1] = getFormattedMonth(splitDate[1]);
				formattedDate = splitDate.join(' ');
			} else {
				formattedDate = Intl.DateTimeFormat('es-ES', options).format(dateToFormat).split(' de ');
			}
		} else {
			formattedDate = Intl.DateTimeFormat('en-IN', options).format(dateToFormat).replace(/ am$/, ' AM').replace(/ pm$/, ' PM');
		}
	}

	if (showTimeZone === true) {
		/*
		 * We need to use the locale of the user to get the appropriate short name
		 * For example if locale is en-US when on the US East Coast you get EDT or EST but
		 * if the locale is en-GB on the US East Coast then you get GMT-4 or GMT-5
		 *
		 * There may still be weird use cases where the persons locale and their timezone don't match such as an
		 * American who took their laptop to China, they would have locale of en-US and would thus get GMT+8 instead of CST
		 * NOTE: GMT+8 is still correct just not what we may be expecting
		 */
		options = {timeZoneName: 'short'};
		let locale = Intl.NumberFormat().resolvedOptions().locale;
		let timezone = Intl.DateTimeFormat(locale, options).format(dateToFormat).split(' ')[1];
		if ((timezone.startsWith('GMT') || timezone.startsWith('UTC')) && (window.MathWorksCountryCode !== undefined) && (language !== undefined)) {
			locale = language + '-' + window.MathWorksCountryCode;
			timezone = Intl.DateTimeFormat(locale, options).format(dateToFormat).split(' ')[1];
		}
		formattedDate += ' ' + timezone;
	}

	return formattedDate;
});

Handlebars.registerHelper('commaDelimitedStringForList', function (list) {
	return list.join(', ');
});

Handlebars.registerHelper('timeAgoInWords', function (language, date) {
	//Based off of Ruby's time_ago_in_words
	var formattedDate;
	var now = new Date();
	var givenDate = new Date(date);
	var timeDiffInSeconds = now.getTime() - givenDate.getTime();
	timeDiffInSeconds = timeDiffInSeconds / 1000;

	if (timeDiffInSeconds <= 1) {
		formattedDate = 'less than 1 second ago';
	} else if (timeDiffInSeconds <= 4) {
		formattedDate = 'less than 5 seconds ago';
	} else if (timeDiffInSeconds <= 10) {
		formattedDate = 'less than 10 seconds ago';
	} else if (timeDiffInSeconds <= 20) {
		formattedDate = 'less than 20 seconds ago';
	} else if (timeDiffInSeconds <= 39) {
		formattedDate = 'half a minute ago';
	} else if (timeDiffInSeconds <= 59) {
		formattedDate = 'less than a minute ago';
	} else if (timeDiffInSeconds <= 89) {
		formattedDate = '1 minute ago';
	} else if (timeDiffInSeconds <= 60 * 45) {
		//over 1 minute up to and including 45 minutes
		formattedDate = Math.round(timeDiffInSeconds / 60) + ' minutes ago';
	} else if (timeDiffInSeconds <= 60 * 90) {
		//over 45 minutes up to and including 90 minutes
		formattedDate = 'about 1 hour ago';
	} else if (timeDiffInSeconds <= 60 * 60 * 24) {
		//over 90 minutes up to and including 1 day
		formattedDate = 'about ' + Math.round(timeDiffInSeconds / 60 / 60) + ' hours ago';
	} else if (timeDiffInSeconds <= 60 * 60 * 24 * 30) {
		//over 1 day up to and including 1 month (30 days)
		var utcTimeStamp = givenDate.getUTCHours() + ':' + ('0' + givenDate.getUTCMinutes()).slice(-2);
		formattedDate = 'on ' + Handlebars.helpers.formatDate(language, date, true, false, false) + ' at ' + utcTimeStamp;
	} else {
		formattedDate = 'on ' + Handlebars.helpers.formatDate(language, date, true, false, false);
	}

	return formattedDate;
});

Handlebars.registerHelper('acceptedAndAnswered', function (status) {
	if (status) {
		return ((status.indexOf('accepted') >= 0) && (status.indexOf('answered') >= 0));
	} else {
		return false;
	}
});

Handlebars.registerHelper('setList', function () {
	let list = [];
	for (let i = 0; i < arguments.length - 1; i++) {
		if (arguments[i] !== '') {
			list.push(arguments[i]);
		}
	}
	return list;
});

Handlebars.registerHelper('setVariable', function (varName, varValue, options) {
	options.data.root[varName] = varValue;
});

Handlebars.registerHelper('getLanguageSpecificValue', function (row, property) {
	var currentValue = null;
	$.each(
		[
			'_en',
			'_zh',
			'_ja',
			'_ko',
			'_fr',
			'_it',
			'_de',
			'_es'
		], function (index, value) {
			currentValue = row[property + value];
			if (currentValue) {
				return false;
			}
		});
	return currentValue;
});

Handlebars.registerHelper('getLanguageSpecificAdditionalPropertyValue', function (row, property, additionalProperty) {
	var currentValue = null;
	$.each(
		[
			'_en',
			'_zh',
			'_ja',
			'_ko',
			'_fr',
			'_it',
			'_de',
			'_es'
		], function (index, value) {
			currentValue = row[property + value + '_' + additionalProperty];
			if (currentValue) {
				return false;
			}
		});
	return currentValue;
});

Handlebars.registerHelper('getTagTitlesAndIds', function (namespace, tagIDs) {
	var tagTitleList = {};
	$.each(tagIDs, function (index, value) {
		var title = Handlebars.helpers.getTranslatedTagTitleForId(namespace, value);
		if (title) {
			tagTitleList[value] = title;
		}
	});
	if (Handlebars.helpers.objectSize(tagTitleList) > 0) {
		return tagTitleList;
	} else {
		return '';
	}
});

Handlebars.registerHelper('getTranslatedTagTitleForId', function (namespace, tagID) {
	var id = namespace + tagID;
	if (facetDetails && facetDetails[namespace]) {
		var currentTag = facetDetails[namespace].filter(
			function (data) {
				return data.id === id;
			}
		);
		if (currentTag && (currentTag.length > 0)) {
			return currentTag[0].title;
		} else {
			return '';
		}
	}
	return '';
});

Handlebars.registerHelper('getSpeakerInfo', function (speakers) {
	let speakerList = [];
	if (speakers !== undefined && speakers !== '') {
		for (let i = 0; i < speakers.length; i++) {
			if (speakers[i] !== '') {
				const txt = document.createElement('textarea');
				txt.innerHTML = speakers[i];
				const regex = /"([^"]+)"\s*:\s*"((?:[^"\\]|\\.)*)"/g;
				let match;
				let speaker = [];

				while ((match = regex.exec(txt.value)) !== null) {
					if ((match[1] === 'speakerName' || match[1] === 'speakerTitle') && match[2] !== '') {
						speaker.push(match[2]);
					} else if (match[1] === 'speakerCompany') {
						speaker.push(`<i>${match[2]}</i>`);
					}
				}
				speakerList.push(Handlebars.helpers.commaDelimitedStringForList(speaker));
			}
		}
	}
	return speakerList;
});

Handlebars.registerHelper('objectSize', function (object) {
	var osize = 0, key;
	for (key in object) {
		if (object.hasOwnProperty(key)) {
			osize++;
		}
	}
	return osize;
});

Handlebars.registerHelper('truncate', function (propertyValue) {
	if (propertyValue) {
		if ((propertyValue.length > 200) && (propertyValue.indexOf(' ', 200) !== -1)) {
			propertyValue = propertyValue.substring(0, propertyValue.indexOf(' ', 200)) + '...';
		}
	}
	return propertyValue;
});

Handlebars.registerHelper('getMultilingualProperty', function (row, property) {
	var value = null;
	/* jshint camelcase: false */
	var propertyName = property + '_' + row.asset_language;
	if (row.hasOwnProperty(propertyName)) {
		value = row[propertyName];
	} else if (row.hasOwnProperty(property + '_en')) {
		value = row[property + '_en'];
	} else {
		value = Handlebars.helpers.getLanguageSpecificValue(row, property);
	}

	return value;
});

Handlebars.registerHelper('getMultilingualAdditionalProperty', function (row, assetLanguage, property, additionalProperty) {
	var value = null;
	/* jshint camelcase: false */
	var langPropertyName = property + '_' + assetLanguage + '_' + additionalProperty;
	var enPropertyName = property + '_en_' + additionalProperty;
	if (row) {
		if (row.hasOwnProperty(langPropertyName)) {
			value = row[langPropertyName];
		} else if (row.hasOwnProperty(enPropertyName)) {
			value = row[enPropertyName];
		}
	}
	return value;
});

Handlebars.registerHelper('getMultilingualHighlightProperty', function (row, assetLanguage, property) {
	var value = null;
	/* jshint camelcase: false */
	var propertyName = property + '_' + assetLanguage;
	if (row) {
		if (row.hasOwnProperty(propertyName)) {
			value = row[propertyName];
		} else if (row.hasOwnProperty(property + '_en')) {
			value = row[property + '_en'];
		}
	}

	return value;
});

Handlebars.registerHelper('getTranslatedAssetLanguage', function (row) {
	var translatedTitle = null;
	/* jshint camelcase: false */
	var assetLanguage = row.asset_language;
	var assetLanguageNamespace = 'asset-language:';
	var tagId = assetLanguageNamespace + assetLanguage;

	if (assetLanguage) {
		if (translatedAssetLanguages) {
			translatedTitle = translatedAssetLanguages[tagId][assetLanguage];
		}
		if ((!translatedTitle) && (facetDetails)) {
			translatedTitle = facetDetails[assetLanguageNamespace].filter(
				function (data) {
					return data.id === tagId;
				}
			)[0].title;
		}
	}

	return translatedTitle;
});

Handlebars.registerHelper('getQueryComponent', function (url) {
	if (url && url.indexOf('?') === -1) {
		return '?';
	} else {
		return '&';
	}
});

Handlebars.registerHelper('getHighlights', function (highlights, row) {
	/* jshint camelcase: false */
	var	rowAssetLanguage = row.asset_language,
		highlightMetaDescriptionLangRaw = Handlebars.helpers.getMultilingualAdditionalProperty(highlights, rowAssetLanguage, 'meta_description', 'raw'),
		highlightBodyLangRaw = Handlebars.helpers.getMultilingualAdditionalProperty(highlights, rowAssetLanguage, 'body', 'raw'),
		highlightMetaDescriptionLang = Handlebars.helpers.getMultilingualHighlightProperty(highlights, rowAssetLanguage, 'meta_description'),
		highlightBodyLang = Handlebars.helpers.getMultilingualHighlightProperty(highlights, rowAssetLanguage, 'body'),
		highlightMetaDescription = highlights ? highlights['meta_description'] : null,
		highlightBody = highlights ? highlights['body'] : null,
		rowMetaDescriptionLangRaw = Handlebars.helpers.getMultilingualAdditionalProperty(row, rowAssetLanguage, 'meta_description', 'raw'),
		rowMetaDescriptionLang = Handlebars.helpers.getMultilingualProperty(row, 'meta_description'),
		rowMetaDescription = row['meta_description'],
		rowBodyLangRaw = Handlebars.helpers.getMultilingualAdditionalProperty(row, rowAssetLanguage, 'body', 'raw'),
		rowBodyLang = Handlebars.helpers.getMultilingualProperty(row, 'body'),
		highlightValue = null;

	if (highlightMetaDescriptionLangRaw && Handlebars.helpers.hasHighlightTag(highlightMetaDescriptionLangRaw)) {
		highlightValue = Handlebars.helpers.getHighlightedValueWithEllipsis(highlightMetaDescriptionLangRaw, rowMetaDescriptionLangRaw);
	} else if (highlightBodyLangRaw && Handlebars.helpers.hasHighlightTag(highlightBodyLangRaw)) {
		highlightValue = Handlebars.helpers.getHighlightedValueWithEllipsis(highlightBodyLangRaw, '');
	} else if (highlightMetaDescriptionLang && Handlebars.helpers.hasHighlightTag(highlightMetaDescriptionLang)) {
		highlightValue = Handlebars.helpers.getHighlightedValueWithEllipsis(highlightMetaDescriptionLang, rowMetaDescriptionLang);
	} else if (highlightBodyLang && Handlebars.helpers.hasHighlightTag(highlightBodyLang)) {
		highlightValue = Handlebars.helpers.getHighlightedValueWithEllipsis(highlightBodyLang, '');
	} else if (highlightMetaDescription && Handlebars.helpers.hasHighlightTag(highlightMetaDescription)) {
		highlightValue = Handlebars.helpers.getHighlightedValueWithEllipsis(highlightMetaDescription, rowMetaDescription);
	} else if (highlightBody && Handlebars.helpers.hasHighlightTag(highlightBody)) {
		highlightValue = Handlebars.helpers.getHighlightedValueWithEllipsis(highlightBody, '');
	} else if (rowMetaDescriptionLangRaw) {
		highlightValue = Handlebars.helpers.truncate(rowMetaDescriptionLangRaw);
	} else if (rowMetaDescriptionLang) {
		highlightValue = Handlebars.helpers.truncate(rowMetaDescriptionLang);
	} else if (rowMetaDescription) {
		highlightValue = Handlebars.helpers.truncate(rowMetaDescription);
	} else if (rowBodyLangRaw) {
		highlightValue = Handlebars.helpers.truncate(rowBodyLangRaw);
	} else if (rowBodyLang) {
		highlightValue = Handlebars.helpers.truncate(rowBodyLang);
	}

	return highlightValue;
});

Handlebars.registerHelper('hasHighlightTag', function (highlightField) {
	return (!!highlightField[0].match(/<\/?mark>/));
});

Handlebars.registerHelper('getHighlightedValueWithEllipsis', function (highlightedValue, rowValue) {
	var highlightedValueWithEllipsis = '';
	if (highlightedValue) {
		highlightedValueWithEllipsis = highlightedValue[0].trim();
		var unhighlightedValue = highlightedValue[0].replace(/<\/?mark>/g, '');
		if (rowValue) {
			if (!rowValue.startsWith(unhighlightedValue)) {
				highlightedValueWithEllipsis = '...' + highlightedValueWithEllipsis;
			}
			if (!rowValue.endsWith(unhighlightedValue)) {
				highlightedValueWithEllipsis = highlightedValueWithEllipsis + '...';
			}
		} else {
			highlightedValueWithEllipsis = '...' + highlightedValueWithEllipsis + '...';
		}
	}
	return highlightedValueWithEllipsis;
});

Handlebars.registerHelper('stripDomainForBreadcrumbValidation', function (url, type) {
	var pathName = url;
	var ignoreDomainTypes = ['https://blogs.mathworks.com',
		'https://www.matlabexpo.com',
		'https://matlabacademy.mathworks.com'];

	if (!ignoreDomainTypes.includes(type)) {
		var a = document.createElement('a');
		a.href = url;
		pathName = a.pathname;
	}
	return pathName;
});

Handlebars.registerHelper('isResultThisType', function (url, type) {
	return (Handlebars.helpers.stripDomainForBreadcrumbValidation(url, type).indexOf(type) === 0);
});

Handlebars.registerHelper('createBreadcrumbs', function (row) {
	var createdBreadcrumb = null;
	if (row['subcollection'].indexOf('seminars') > -1) {
		createdBreadcrumb = staticBreadcrumbDetails['seminars'];
	} else if (row['subcollection'].indexOf('livewebinars') > -1) {
		createdBreadcrumb = staticBreadcrumbDetails['livewebinars'];
	} else if (row['subcollection'].indexOf('webinars') > -1) {
		createdBreadcrumb = staticBreadcrumbDetails['webinars'];
	} else {
		for (var urlPatternType in staticBreadcrumbDetails) {
			if (Handlebars.helpers.isResultThisType(row.url, urlPatternType) === true) {
				createdBreadcrumb = staticBreadcrumbDetails[urlPatternType];
				break;
			}
		}
	}

	return createdBreadcrumb;
});

Handlebars.registerHelper('getSeminarSessions', function (language, value) {
	if (value.split(',')[1]) {
		return (Handlebars.helpers.formatDateByLanguage(language, value.split(',')[0], true) + value.substring(value.indexOf(',')));
	} else {
		return (Handlebars.helpers.formatDateByLanguage(language, value.split(',')[0], true));
	}
});

Handlebars.registerHelper('getLocaleSpecificNumber', function (categoryCount) {
	let domainLanguage = 'en';
	let element = document.getElementById('search');

	if (!element) {
		element = document.getElementById('query');
	}

	if (element) {
		domainLanguage = element.getAttribute('data-site-language');
	}
	return (Number(categoryCount).toLocaleString(domainLanguage)).toString();
});

Handlebars.registerHelper('getSuggestionHighlights', function (qValue, suggestion) {
	let suggestionHighlight = null;
	let regex = new RegExp('(' + qValue + ')', 'i');
	suggestionHighlight = suggestion.replace(regex, '');
	return suggestionHighlight;
});

Handlebars.registerHelper('getThumbnailClass', function (subCollection, isEmbeddedDoc) {
	if(subCollection?.includes('videos') || subCollection?.includes('books') || subCollection?.includes('videos_all') || subCollection?.includes('event_proceedings') || isEmbeddedDoc) {
		return 'figure-img';
	} else {
		return 'figure-img search_result_supplemental_image';
	}
});
/* global Handlebars */

'use strict';

Handlebars.registerHelper('ifCond', function (v1, operator, v2, options) {

	switch (operator) {
		case '==':
			/* jshint eqeqeq: false */
			return (v1 == v2) ? options.fn(this) : options.inverse(this);
		case '===':
			return (v1 === v2) ? options.fn(this) : options.inverse(this);
		case '!=':
			/* jshint eqeqeq: false */
			return (v1 != v2) ? options.fn(this) : options.inverse(this);
		case '!==':
			return (v1 !== v2) ? options.fn(this) : options.inverse(this);
		case '<':
			return (v1 < v2) ? options.fn(this) : options.inverse(this);
		case '<=':
			return (v1 <= v2) ? options.fn(this) : options.inverse(this);
		case '>':
			return (v1 > v2) ? options.fn(this) : options.inverse(this);
		case '>=':
			return (v1 >= v2) ? options.fn(this) : options.inverse(this);
		case '&&':
			return (v1 && v2) ? options.fn(this) : options.inverse(this);
		case '||':
			return (v1 || v2) ? options.fn(this) : options.inverse(this);
		case 'startsWith':
			return (v1.startsWith(v2)) ? options.fn(this) : options.inverse(this);
		default:
			return options.inverse(this);
	}
});

this["Mathworks"] = this["Mathworks"] || {};
this["Mathworks"]["templates"] = this["Mathworks"]["templates"] || {};
this["Mathworks"]["templates"]["adaptiveimage"] = Handlebars.template({"compiler":[8,">= 4.3.0"],"main":function(container,depth0,helpers,partials,data) {
    var helper, alias1=depth0 != null ? depth0 : (container.nullContext || {}), alias2=container.hooks.helperMissing, alias3="function", alias4=container.escapeExpression, lookupProperty = container.lookupProperty || function(parent, propertyName) {
        if (Object.prototype.hasOwnProperty.call(parent, propertyName)) {
          return parent[propertyName];
        }
        return undefined
    };

  return "<div data-adaptivepicture data-alt=\""
    + alias4(((helper = (helper = lookupProperty(helpers,"altText") || (depth0 != null ? lookupProperty(depth0,"altText") : depth0)) != null ? helper : alias2),(typeof helper === alias3 ? helper.call(alias1,{"name":"altText","hash":{},"data":data,"loc":{"start":{"line":1,"column":36},"end":{"line":1,"column":47}}}) : helper)))
    + "\" data-title=\""
    + alias4(((helper = (helper = lookupProperty(helpers,"titleText") || (depth0 != null ? lookupProperty(depth0,"titleText") : depth0)) != null ? helper : alias2),(typeof helper === alias3 ? helper.call(alias1,{"name":"titleText","hash":{},"data":data,"loc":{"start":{"line":1,"column":61},"end":{"line":1,"column":74}}}) : helper)))
    + "\"\n	data-class=\""
    + alias4(((helper = (helper = lookupProperty(helpers,"classText") || (depth0 != null ? lookupProperty(depth0,"classText") : depth0)) != null ? helper : alias2),(typeof helper === alias3 ? helper.call(alias1,{"name":"classText","hash":{},"data":data,"loc":{"start":{"line":2,"column":13},"end":{"line":2,"column":26}}}) : helper)))
    + "\" data-backgroundImage=\""
    + alias4(((helper = (helper = lookupProperty(helpers,"isBackgroundImage") || (depth0 != null ? lookupProperty(depth0,"isBackgroundImage") : depth0)) != null ? helper : alias2),(typeof helper === alias3 ? helper.call(alias1,{"name":"isBackgroundImage","hash":{},"data":data,"loc":{"start":{"line":2,"column":50},"end":{"line":2,"column":71}}}) : helper)))
    + "\"\n	data-image=\""
    + alias4(((helper = (helper = lookupProperty(helpers,"imagePath") || (depth0 != null ? lookupProperty(depth0,"imagePath") : depth0)) != null ? helper : alias2),(typeof helper === alias3 ? helper.call(alias1,{"name":"imagePath","hash":{},"data":data,"loc":{"start":{"line":3,"column":13},"end":{"line":3,"column":26}}}) : helper)))
    + "\"\n	data-has-mobile=\""
    + alias4(((helper = (helper = lookupProperty(helpers,"mobileImage") || (depth0 != null ? lookupProperty(depth0,"mobileImage") : depth0)) != null ? helper : alias2),(typeof helper === alias3 ? helper.call(alias1,{"name":"mobileImage","hash":{},"data":data,"loc":{"start":{"line":4,"column":18},"end":{"line":4,"column":33}}}) : helper)))
    + "\" data-mobile-breakpoint=\"481\"\n	data-mobile-image=\""
    + alias4(((helper = (helper = lookupProperty(helpers,"mobileImagePath") || (depth0 != null ? lookupProperty(depth0,"mobileImagePath") : depth0)) != null ? helper : alias2),(typeof helper === alias3 ? helper.call(alias1,{"name":"mobileImagePath","hash":{},"data":data,"loc":{"start":{"line":5,"column":20},"end":{"line":5,"column":39}}}) : helper)))
    + "\">\n</div>\n";
},"useData":true});;
this["Mathworks"] = this["Mathworks"] || {};
this["Mathworks"]["templates"] = this["Mathworks"]["templates"] || {};
this["Mathworks"]["templates"]["blogfeed"] = Handlebars.template({"1":function(container,depth0,helpers,partials,data) {
    var stack1, lookupProperty = container.lookupProperty || function(parent, propertyName) {
        if (Object.prototype.hasOwnProperty.call(parent, propertyName)) {
          return parent[propertyName];
        }
        return undefined
    };

  return " - "
    + container.escapeExpression((lookupProperty(helpers,"formatDateByLanguage")||(depth0 && lookupProperty(depth0,"formatDateByLanguage"))||container.hooks.helperMissing).call(depth0 != null ? depth0 : (container.nullContext || {}),(depth0 != null ? lookupProperty(depth0,"siteLanguage") : depth0),((stack1 = (depth0 != null ? lookupProperty(depth0,"blog") : depth0)) != null ? lookupProperty(stack1,"updated_at") : stack1),false,false,false,{"name":"formatDateByLanguage","hash":{},"data":data,"loc":{"start":{"line":3,"column":36},"end":{"line":3,"column":107}}}));
},"compiler":[8,">= 4.3.0"],"main":function(container,depth0,helpers,partials,data) {
    var stack1, alias1=depth0 != null ? depth0 : (container.nullContext || {}), alias2=container.hooks.helperMissing, lookupProperty = container.lookupProperty || function(parent, propertyName) {
        if (Object.prototype.hasOwnProperty.call(parent, propertyName)) {
          return parent[propertyName];
        }
        return undefined
    };

  return "<li>\n	<a href=\""
    + container.escapeExpression(container.lambda(((stack1 = (depth0 != null ? lookupProperty(depth0,"blog") : depth0)) != null ? lookupProperty(stack1,"url") : stack1), depth0))
    + "\">"
    + ((stack1 = (lookupProperty(helpers,"getLanguageSpecificValue")||(depth0 && lookupProperty(depth0,"getLanguageSpecificValue"))||alias2).call(alias1,(depth0 != null ? lookupProperty(depth0,"blog") : depth0),"title",{"name":"getLanguageSpecificValue","hash":{},"data":data,"loc":{"start":{"line":2,"column":24},"end":{"line":2,"column":67}}})) != null ? stack1 : "")
    + "</a>\n	"
    + ((stack1 = (lookupProperty(helpers,"ifCond")||(depth0 && lookupProperty(depth0,"ifCond"))||alias2).call(alias1,(depth0 != null ? lookupProperty(depth0,"showDate") : depth0),"==","true",{"name":"ifCond","hash":{},"fn":container.program(1, data, 0),"inverse":container.noop,"data":data,"loc":{"start":{"line":3,"column":1},"end":{"line":3,"column":118}}})) != null ? stack1 : "")
    + "\n</li>";
},"useData":true});;
this["Mathworks"] = this["Mathworks"] || {};
this["Mathworks"]["templates"] = this["Mathworks"]["templates"] || {};
this["Mathworks"]["templates"]["errormessage500"] = Handlebars.template({"compiler":[8,">= 4.3.0"],"main":function(container,depth0,helpers,partials,data) {
    return "<div class=\"mw-text\">\n    <div class=\"alert alert-danger\" role=\"alert\"><span class=\"alert_icon icon-alert-error\"></span>\n        <h3>We're Sorry - an error has occurred</h3>\n        <p>We apologize for the inconvenience. This error has been automatically reported to MathWorks. We will fix this as soon as possible.</p>\n        <p>Please try visiting our <a href=\"/\">Home Page</a>&nbsp;or&nbsp;<a href=\"/help/\">Site Help</a> to choose another page.</p>\n    </div>\n</div>";
},"useData":true});;
this["Mathworks"] = this["Mathworks"] || {};
this["Mathworks"]["templates"] = this["Mathworks"]["templates"] || {};
this["Mathworks"]["templates"]["searchedcollectionname"] = Handlebars.template({"compiler":[8,">= 4.3.0"],"main":function(container,depth0,helpers,partials,data) {
    var helper, alias1=depth0 != null ? depth0 : (container.nullContext || {}), alias2=container.hooks.helperMissing, alias3="function", alias4=container.escapeExpression, lookupProperty = container.lookupProperty || function(parent, propertyName) {
        if (Object.prototype.hasOwnProperty.call(parent, propertyName)) {
          return parent[propertyName];
        }
        return undefined
    };

  return "<div class=\"searched\">\n	"
    + alias4(((helper = (helper = lookupProperty(helpers,"searchedWord") || (depth0 != null ? lookupProperty(depth0,"searchedWord") : depth0)) != null ? helper : alias2),(typeof helper === alias3 ? helper.call(alias1,{"name":"searchedWord","hash":{},"data":data,"loc":{"start":{"line":2,"column":1},"end":{"line":2,"column":17}}}) : helper)))
    + ":  <a href=\""
    + alias4(((helper = (helper = lookupProperty(helpers,"searchedCollectionPath") || (depth0 != null ? lookupProperty(depth0,"searchedCollectionPath") : depth0)) != null ? helper : alias2),(typeof helper === alias3 ? helper.call(alias1,{"name":"searchedCollectionPath","hash":{},"data":data,"loc":{"start":{"line":2,"column":29},"end":{"line":2,"column":55}}}) : helper)))
    + "\">"
    + alias4(((helper = (helper = lookupProperty(helpers,"searchedCollectionName") || (depth0 != null ? lookupProperty(depth0,"searchedCollectionName") : depth0)) != null ? helper : alias2),(typeof helper === alias3 ? helper.call(alias1,{"name":"searchedCollectionName","hash":{},"data":data,"loc":{"start":{"line":2,"column":57},"end":{"line":2,"column":83}}}) : helper)))
    + "</a>\n</div>";
},"useData":true});;
this["Mathworks"] = this["Mathworks"] || {};
this["Mathworks"]["templates"] = this["Mathworks"]["templates"] || {};
this["Mathworks"]["templates"]["searchgrouptypeahead"] = Handlebars.template({"1":function(container,depth0,helpers,partials,data) {
    var stack1, lookupProperty = container.lookupProperty || function(parent, propertyName) {
        if (Object.prototype.hasOwnProperty.call(parent, propertyName)) {
          return parent[propertyName];
        }
        return undefined
    };

  return ((stack1 = lookupProperty(helpers,"each").call(depth0 != null ? depth0 : (container.nullContext || {}),(depth0 != null ? lookupProperty(depth0,"pages") : depth0),{"name":"each","hash":{},"fn":container.program(2, data, 0),"inverse":container.noop,"data":data,"loc":{"start":{"line":3,"column":2},"end":{"line":31,"column":11}}})) != null ? stack1 : "");
},"2":function(container,depth0,helpers,partials,data) {
    var stack1, helper, alias1=depth0 != null ? depth0 : (container.nullContext || {}), alias2=container.hooks.helperMissing, alias3="function", alias4=container.escapeExpression, lookupProperty = container.lookupProperty || function(parent, propertyName) {
        if (Object.prototype.hasOwnProperty.call(parent, propertyName)) {
          return parent[propertyName];
        }
        return undefined
    };

  return "			<dl>\n				<dt tabindex=\"0\">"
    + alias4(((helper = (helper = lookupProperty(helpers,"header") || (depth0 != null ? lookupProperty(depth0,"header") : depth0)) != null ? helper : alias2),(typeof helper === alias3 ? helper.call(alias1,{"name":"header","hash":{},"data":data,"loc":{"start":{"line":5,"column":21},"end":{"line":5,"column":31}}}) : helper)))
    + "\n					<span class=\"header_icon_linebreak\"></span>\n"
    + ((stack1 = (lookupProperty(helpers,"ifIn")||(depth0 && lookupProperty(depth0,"ifIn"))||alias2).call(alias1,"fcn",(depth0 != null ? lookupProperty(depth0,"type") : depth0),{"name":"ifIn","hash":{},"fn":container.program(3, data, 0),"inverse":container.noop,"data":data,"loc":{"start":{"line":7,"column":5},"end":{"line":9,"column":14}}})) != null ? stack1 : "")
    + ((stack1 = (lookupProperty(helpers,"ifIn")||(depth0 && lookupProperty(depth0,"ifIn"))||alias2).call(alias1,"blk",(depth0 != null ? lookupProperty(depth0,"type") : depth0),{"name":"ifIn","hash":{},"fn":container.program(5, data, 0),"inverse":container.noop,"data":data,"loc":{"start":{"line":10,"column":5},"end":{"line":12,"column":14}}})) != null ? stack1 : "")
    + "				</dt>\n				<dd class=\""
    + alias4(((helper = (helper = lookupProperty(helpers,"type") || (depth0 != null ? lookupProperty(depth0,"type") : depth0)) != null ? helper : alias2),(typeof helper === alias3 ? helper.call(alias1,{"name":"type","hash":{},"data":data,"loc":{"start":{"line":14,"column":15},"end":{"line":14,"column":23}}}) : helper)))
    + "area suggestionarea\">\n					<ul class=\"list-unstyled\">\n"
    + ((stack1 = lookupProperty(helpers,"each").call(alias1,(depth0 != null ? lookupProperty(depth0,"suggestions") : depth0),{"name":"each","hash":{},"fn":container.program(7, data, 0),"inverse":container.noop,"data":data,"loc":{"start":{"line":16,"column":6},"end":{"line":27,"column":15}}})) != null ? stack1 : "")
    + "					</ul>\n				</dd>\n			</dl>\n";
},"3":function(container,depth0,helpers,partials,data) {
    return "						<span class=\"icon-function\"></span>\n";
},"5":function(container,depth0,helpers,partials,data) {
    return "						<span class=\"icon-block\"></span>\n";
},"7":function(container,depth0,helpers,partials,data) {
    var stack1, helper, alias1=depth0 != null ? depth0 : (container.nullContext || {}), alias2=container.hooks.helperMissing, alias3="function", alias4=container.escapeExpression, lookupProperty = container.lookupProperty || function(parent, propertyName) {
        if (Object.prototype.hasOwnProperty.call(parent, propertyName)) {
          return parent[propertyName];
        }
        return undefined
    };

  return "							<li class=\"suggestion\">\n								<a href=\"/help/"
    + alias4(((helper = (helper = lookupProperty(helpers,"path") || (depth0 != null ? lookupProperty(depth0,"path") : depth0)) != null ? helper : alias2),(typeof helper === alias3 ? helper.call(alias1,{"name":"path","hash":{},"data":data,"loc":{"start":{"line":18,"column":23},"end":{"line":18,"column":31}}}) : helper)))
    + "\">\n									<span class=\"suggestion_summary\">\n										"
    + ((stack1 = lookupProperty(helpers,"each").call(alias1,(depth0 != null ? lookupProperty(depth0,"title") : depth0),{"name":"each","hash":{},"fn":container.program(8, data, 0),"inverse":container.noop,"data":data,"loc":{"start":{"line":20,"column":10},"end":{"line":20,"column":160}}})) != null ? stack1 : "")
    + "\n										-\n										"
    + ((stack1 = lookupProperty(helpers,"each").call(alias1,(depth0 != null ? lookupProperty(depth0,"summary") : depth0),{"name":"each","hash":{},"fn":container.program(8, data, 0),"inverse":container.noop,"data":data,"loc":{"start":{"line":22,"column":10},"end":{"line":22,"column":162}}})) != null ? stack1 : "")
    + "\n									</span>\n									<span class=\"suggestion_product\">"
    + alias4(((helper = (helper = lookupProperty(helpers,"product") || (depth0 != null ? lookupProperty(depth0,"product") : depth0)) != null ? helper : alias2),(typeof helper === alias3 ? helper.call(alias1,{"name":"product","hash":{},"data":data,"loc":{"start":{"line":24,"column":42},"end":{"line":24,"column":53}}}) : helper)))
    + "</span>\n								</a>\n							</li>\n";
},"8":function(container,depth0,helpers,partials,data) {
    var stack1, alias1=depth0 != null ? depth0 : (container.nullContext || {}), alias2=container.hooks.helperMissing, lookupProperty = container.lookupProperty || function(parent, propertyName) {
        if (Object.prototype.hasOwnProperty.call(parent, propertyName)) {
          return parent[propertyName];
        }
        return undefined
    };

  return ((stack1 = (lookupProperty(helpers,"ifCond")||(depth0 && lookupProperty(depth0,"ifCond"))||alias2).call(alias1,(data && lookupProperty(data,"index")),"==","1",{"name":"ifCond","hash":{},"fn":container.program(9, data, 0),"inverse":container.noop,"data":data,"loc":{"start":{"line":20,"column":25},"end":{"line":20,"column":98}}})) != null ? stack1 : "")
    + container.escapeExpression(container.lambda(depth0, depth0))
    + ((stack1 = (lookupProperty(helpers,"ifCond")||(depth0 && lookupProperty(depth0,"ifCond"))||alias2).call(alias1,(data && lookupProperty(data,"index")),"==","1",{"name":"ifCond","hash":{},"fn":container.program(11, data, 0),"inverse":container.noop,"data":data,"loc":{"start":{"line":20,"column":106},"end":{"line":20,"column":151}}})) != null ? stack1 : "");
},"9":function(container,depth0,helpers,partials,data) {
    return "<span class=\"suggestion_highlight\">";
},"11":function(container,depth0,helpers,partials,data) {
    return "</span>";
},"13":function(container,depth0,helpers,partials,data) {
    var stack1, helper, alias1=depth0 != null ? depth0 : (container.nullContext || {}), alias2=container.hooks.helperMissing, alias3="function", alias4=container.escapeExpression, lookupProperty = container.lookupProperty || function(parent, propertyName) {
        if (Object.prototype.hasOwnProperty.call(parent, propertyName)) {
          return parent[propertyName];
        }
        return undefined
    };

  return "		<dl class=\"typeahead_suggestions\">\n			<dt tabindex=\"0\">"
    + alias4(((helper = (helper = lookupProperty(helpers,"labelSuggestions") || (depth0 != null ? lookupProperty(depth0,"labelSuggestions") : depth0)) != null ? helper : alias2),(typeof helper === alias3 ? helper.call(alias1,{"name":"labelSuggestions","hash":{},"data":data,"loc":{"start":{"line":35,"column":20},"end":{"line":35,"column":40}}}) : helper)))
    + "</dt>\n			<dd class=\"wordarea suggestionarea\">\n				<ul class=\"list-unstyled\">\n"
    + ((stack1 = lookupProperty(helpers,"each").call(alias1,((stack1 = (depth0 != null ? lookupProperty(depth0,"words") : depth0)) != null ? lookupProperty(stack1,"wordlist") : stack1),{"name":"each","hash":{},"fn":container.program(14, data, 0),"inverse":container.noop,"data":data,"loc":{"start":{"line":38,"column":5},"end":{"line":44,"column":14}}})) != null ? stack1 : "")
    + "				</ul>\n			</dd>\n		</dl>\n		<dl class=\"text-center\">\n			<hr class=\"add_hr_spacing_10\">\n			<a href=\"/support/search.html?s_tid=ta_see_all_results&q="
    + alias4(((helper = (helper = lookupProperty(helpers,"searchtext") || (depth0 != null ? lookupProperty(depth0,"searchtext") : depth0)) != null ? helper : alias2),(typeof helper === alias3 ? helper.call(alias1,{"name":"searchtext","hash":{},"data":data,"loc":{"start":{"line":50,"column":60},"end":{"line":50,"column":74}}}) : helper)))
    + "\" tabindex=\"0\" class=\"see_all_results\">"
    + alias4(((helper = (helper = lookupProperty(helpers,"labelSeeAllResults") || (depth0 != null ? lookupProperty(depth0,"labelSeeAllResults") : depth0)) != null ? helper : alias2),(typeof helper === alias3 ? helper.call(alias1,{"name":"labelSeeAllResults","hash":{},"data":data,"loc":{"start":{"line":50,"column":113},"end":{"line":50,"column":135}}}) : helper)))
    + "</a>\n		</dl>\n";
},"14":function(container,depth0,helpers,partials,data) {
    var stack1, helper, alias1=depth0 != null ? depth0 : (container.nullContext || {}), lookupProperty = container.lookupProperty || function(parent, propertyName) {
        if (Object.prototype.hasOwnProperty.call(parent, propertyName)) {
          return parent[propertyName];
        }
        return undefined
    };

  return "						<li class=\"suggestion\">\n							<a href=\"/support/search.html?suggestion=true&q="
    + container.escapeExpression(((helper = (helper = lookupProperty(helpers,"fullword") || (depth0 != null ? lookupProperty(depth0,"fullword") : depth0)) != null ? helper : container.hooks.helperMissing),(typeof helper === "function" ? helper.call(alias1,{"name":"fullword","hash":{},"data":data,"loc":{"start":{"line":40,"column":55},"end":{"line":40,"column":67}}}) : helper)))
    + "\">\n								"
    + ((stack1 = lookupProperty(helpers,"each").call(alias1,(depth0 != null ? lookupProperty(depth0,"splitwordlist") : depth0),{"name":"each","hash":{},"fn":container.program(8, data, 0),"inverse":container.noop,"data":data,"loc":{"start":{"line":41,"column":8},"end":{"line":41,"column":166}}})) != null ? stack1 : "")
    + "\n							</a>\n						</li>\n";
},"compiler":[8,">= 4.3.0"],"main":function(container,depth0,helpers,partials,data) {
    var stack1, alias1=depth0 != null ? depth0 : (container.nullContext || {}), lookupProperty = container.lookupProperty || function(parent, propertyName) {
        if (Object.prototype.hasOwnProperty.call(parent, propertyName)) {
          return parent[propertyName];
        }
        return undefined
    };

  return "<div class=\"typeahead_container typeahead_type_grouped dropdown-menu add_display_block\" aria-label=\"Suggestions\" tabindex=\"-1\">\n"
    + ((stack1 = lookupProperty(helpers,"if").call(alias1,(depth0 != null ? lookupProperty(depth0,"pages") : depth0),{"name":"if","hash":{},"fn":container.program(1, data, 0),"inverse":container.noop,"data":data,"loc":{"start":{"line":2,"column":1},"end":{"line":32,"column":8}}})) != null ? stack1 : "")
    + ((stack1 = lookupProperty(helpers,"if").call(alias1,((stack1 = (depth0 != null ? lookupProperty(depth0,"words") : depth0)) != null ? lookupProperty(stack1,"wordlist") : stack1),{"name":"if","hash":{},"fn":container.program(13, data, 0),"inverse":container.noop,"data":data,"loc":{"start":{"line":33,"column":1},"end":{"line":52,"column":8}}})) != null ? stack1 : "")
    + "</div>";
},"useData":true});;
this["Mathworks"] = this["Mathworks"] || {};
this["Mathworks"]["templates"] = this["Mathworks"]["templates"] || {};
this["Mathworks"]["templates"]["truncatelist"] = Handlebars.template({"1":function(container,depth0,helpers,partials,data) {
    var helper, lookupProperty = container.lookupProperty || function(parent, propertyName) {
        if (Object.prototype.hasOwnProperty.call(parent, propertyName)) {
          return parent[propertyName];
        }
        return undefined
    };

  return "	<li class=\"dropdown\" id=\"truncate_list\">\n		<a href=\"#\" class=\"dropdown-toggle add_padding_top_10 add_padding_bottom_10\" data-toggle=\"dropdown\" id=\"truncate_dropdown_toggle\" role=\"button\" aria-haspopup=\"true\" aria-expanded=\"false\">\n			"
    + container.escapeExpression(((helper = (helper = lookupProperty(helpers,"labelMoreDropdown") || (depth0 != null ? lookupProperty(depth0,"labelMoreDropdown") : depth0)) != null ? helper : container.hooks.helperMissing),(typeof helper === "function" ? helper.call(depth0 != null ? depth0 : (container.nullContext || {}),{"name":"labelMoreDropdown","hash":{},"data":data,"loc":{"start":{"line":4,"column":3},"end":{"line":4,"column":24}}}) : helper)))
    + "\n			<span class=\"caret\"></span>\n		</a>\n		<ul class=\"dropdown-menu\" role=\"menu\"></ul>\n	</li>\n";
},"compiler":[8,">= 4.3.0"],"main":function(container,depth0,helpers,partials,data) {
    var stack1, lookupProperty = container.lookupProperty || function(parent, propertyName) {
        if (Object.prototype.hasOwnProperty.call(parent, propertyName)) {
          return parent[propertyName];
        }
        return undefined
    };

  return ((stack1 = lookupProperty(helpers,"if").call(depth0 != null ? depth0 : (container.nullContext || {}),(depth0 != null ? lookupProperty(depth0,"labelMoreDropdown") : depth0),{"name":"if","hash":{},"fn":container.program(1, data, 0),"inverse":container.noop,"data":data,"loc":{"start":{"line":1,"column":0},"end":{"line":9,"column":7}}})) != null ? stack1 : "");
},"useData":true});;
