function ArithSeq(first, diff) {
    this.a1 = first;
    this.d = diff;
}
ArithSeq.prototype.a1 = new Number(0);
ArithSeq.prototype.d = new Number(0);
ArithSeq.prototype.a = [];
ArithSeq.prototype.GetNthNumber = function (n) {
    return this.a1 + (n - 1) * this.d;
}
ArithSeq.prototype.GetSum = function (n) {
    return this.a1 * n + n * (n - 1) * this.d / 2;
}
let ars = new ArithSeq(1, 2);
console.log(ars.GetNthNumber(3));
console.log(ars.GetSum(4));
console.log([1, 3, 4, 5, 7]);
function* YieldFunction() {
    yield* [1,2,3,4,5];    
}