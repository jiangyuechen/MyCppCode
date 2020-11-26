"use strict";
"properities default";
class __base{
    a: any;
    b: any;
    constructor(_a:any,_b:any){
        this.a = _a;
        this.b = _b;
    }
    fn(): any{
        return this.a + this.b;
    }
}
class __derived extends __base{
    c: any;
    constructor(_a: any, _b: any, _c: any) {
        super(_a, _b);
        this.c = _c;
    }
}
function get_total(...data: number[]) {
    var total: number = 0;
    for (let index = 0; index < data.length; index++) {
        const element = data[index];
        total += element;
    }
    return total;
}

function get_average(...data: number[]) {
    return get_total(...data) / data.length;
}


function get_max(...data: number[]) {
    var max = Number.MIN_VALUE;
    for (let index = 0; index < data.length; index++) {
        const element = data[index];
        max = max > element ? max : element;
    }
    return max;
}
function get_attribute(add: __base | __derived) {
    
}
export var foo = (a: string, b: string) => {
    return a + b;
}

console.log(get_total(1, 2, 3, 4, 5, 6), get_max(1, 2, 3, 4, 5, 6));
console.assert(false, 1, 2, 3, 4, 5);

export { foo as default, get_average, get_max, get_total };

var b: __derived;
b instanceof __base;
b instanceof __derived;

class Arknights{
    
    private s: Int16Array;
    public get value() : Int16Array {
        return this.s; 
    }
    public set value(_s:Int16Array){
        this.s = _s;
    }
    
}