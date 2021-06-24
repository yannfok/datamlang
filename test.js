const {describe, it} = require('mocha');
const assert = require('assert');
const DTMLTranspile = require('./DataMLTranspiler');

describe('transpile sum', function () {
    it('it should parse into a reduce function to compute the sum', function () {
        assert.deepStrictEqual(DTMLTranspile('f.sum{give data->sum;}'),'function sum(data){return data.reduce((a, b) => a + b, 0);}');
    });
});

describe('transpile size', function () {
    it('it should parse into a function that returns the length property of the data', function () {
        assert.deepStrictEqual(DTMLTranspile('f.size{give data->size;}'),'function size(data){return data.length;}');
    });
});
