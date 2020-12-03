"use strict";
exports.__esModule = true;
var Exp = /** @class */ (function () {
    function Exp(x, y) {
        this.x = x;
        this.y = y;
    }
    Exp.prototype.fn = function () { return this.x + this.y; };
    return Exp;
}());
;
var a = new Exp(1, 2);
console.log(a instanceof Exp);
console.log(typeof a);
function sort(data, callback) {
    if (data.length <= 1) {
        return data;
    }
    var pivotIndex = Math.floor(data.length / 2);
    var pivot = data.splice(pivotIndex, 1)[0];
    var left = [], right = [];
    for (var i = 0; i < data.length; i++) {
        if (callback(data[i], pivot)) {
            left.push(data[i]);
        }
        else {
            right.push(data[i]);
        }
    }
    return sort(left, callback).concat([pivot], sort(right, callback));
}
var temp;
temp = ['babel', 'bootstrap', 'eslint', 'jquery', 'ajax', 'vue', 'node', 'springboot', 'angular'];
function string_comp(a, b) {
    var len;
    if (a.length > b.length) {
        for (var i = b.length; i < a.length; i++)
            b += ' ';
    }
    else {
        for (var i = a.length; i < b.length; i++)
            a += ' ';
    }
    for (var i = 0; i < len; i++) {
        if (a[i] != b[i])
            return a.charCodeAt(i) < b.charCodeAt(i);
    }
}
// function add_mutable(plus_val:number,...data: number[]) :number[] {
//     data.forEach( (value:number, index:number, array:number[]) => {
//         array[index] += plus_val;    
//     });
//     return data;
// }
// function add(plus_val:number,data: number[]) :number[] {
//     data.forEach( (value:number, index:number, array:number[]) => {
//         array[index] += plus_val;    
//     });
//     return data;
// }
// let det = [];
// for (let index = 0; index < 100000000; index++) {
//     det.push(index);
// }
// console.log(add(1, det));
// export { add as default, add_mutable };
let s = Date.now();
console.log(s);