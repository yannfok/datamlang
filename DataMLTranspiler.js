const objectWrapper = require('bindings')('DTMLTranspiler');

/**
 * Transpile the DataMLCode into a JavaScript source code
 * @param code {string}
 * @returns {string}
 * @constructor
 */

module.exports = function DTMLTranspile(code)
{
    return objectWrapper.Transpiler(code).transpile();
}