const createObject = require('./build/Release/dataTranspiler');

/**
 * Transpile the DataMLCode into a JavaScript source code
 * @param code {string}
 * @returns {string}
 * @constructor
 */

module.exports = function DTMLTranspile(code)
{
    return createObject(code).transpile();
}