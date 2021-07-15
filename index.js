const DTMLTranspile = require('./DataMLTranspiler');


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

console.log(DTMLTranspile(srcCode));