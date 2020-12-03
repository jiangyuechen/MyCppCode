import React from 'react';

class Exp {
    x: number;
    y: number;
    fn(): number { return this.x + this.y; }
    constructor(x: number, y: number) { this.x = x; this.y = y; }
};
let a = new Exp(1, 2);

console.log(a instanceof Exp);
console.log(typeof a);

function sort<T>(data: T[], callback: (a: T, b: T) => boolean) : T[] {
    if (data.length <= 1) { return data; }
    let pivotIndex = Math.floor(data.length / 2);
    let pivot = data.splice(pivotIndex, 1)[0];
    let left = [], right = [];
    for (let i = 0; i < data.length; i++){
        if (callback(data[i], pivot)) {
            left.push(data[i]);
        } else {
            right.push(data[i]);
        }
    }
    return sort(left, callback).concat([pivot], sort(right, callback));
}

let temp: string[];
temp = ['babel', 'bootstrap', 'eslint', 'jquery', 'ajax', 'vue', 'node', 'springboot', 'angular'];

function string_comp(a: string, b: string) {
    let len: number;
    if (a.length > b.length) {
        for (let i = b.length; i < a.length; i++) b += ' ';
    } else {
        for (let i = a.length; i < b.length; i++) a += ' ';
    }
    for (let i = 0; i < len; i++){
        if (a[i] != b[i]) return a.charCodeAt(i) < b.charCodeAt(i);
    }
}

console.log(sort(temp, string_comp));



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