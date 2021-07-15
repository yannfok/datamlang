const {describe, it} = require('mocha');
const assert = require('assert');
const DTMLTranspile = require('./DataMLTranspiler');

describe('transpile sum', function () {
    it('should parse into a reduce function to compute the sum', function () {
        assert.deepStrictEqual(DTMLTranspile('f.sum{give data->sum;}'),'function sum(data){return data.reduce((a, b) => a + b, 0);}');
    });
});

describe('transpile size', function () {
    it('should parse into a function that returns the length property of the data', function () {
        assert.deepStrictEqual(DTMLTranspile('f.size{give data->size;}'),'function size(data){return data.length;}');
    });
});

describe('transpile condition', function () {
    it('should parse all the conditions', function (){
        const srcCode =
            'f.special {' +
            '   cst a = data->sum;' +
            '   if a <= 5 {'+
            '       give a * 5;'+
            '   }'+
            '   elif a <= 10 {'+
            '       give a * 10;'+
            '   }' +
            '   else {'+
            '       give a * a;'+
            '   }'+
            '}';
        const jsCode = 'function special(data){const a = data.reduce((a, b) => a + b, 0);if ( a <= 5 ){return a * 5;}else if ( a <= 10 ){return a * 10;}else{return a * a;}}';
        assert.deepStrictEqual(DTMLTranspile(srcCode),jsCode);
    });
});