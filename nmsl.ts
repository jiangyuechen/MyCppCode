let x: string = "123";

function exp(callback: (a: any, b: any) => boolean, ...options: any[]) {
    return {
        "name": "ok",
        "isok": callback(1, 2)
    }
}
let s = exp((a: any, b: any) => { return a < b; });
console.log(s.isok);