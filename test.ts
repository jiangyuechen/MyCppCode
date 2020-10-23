export default function() {
    console.log("this is a module.");
}

export class __exports{
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

export class __derived extends __exports{
    c: any;
    constructor(_a: any, _b: any, _c: any) {
        super(_a, _b);
        this.c = _c;
    }
}

export var foo = (a: string, b: string) => {
    return a + b;
}

var a: string = foo("114", "514");

var x = "123" + 4;
var p: boolean = ((a: number, b: number) => { return a < b; })(1, 2);

var dv = new __derived(1, 2, 3);
var dv_ss: boolean = dv instanceof __derived;