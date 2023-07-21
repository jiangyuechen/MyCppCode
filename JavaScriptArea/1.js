function X2(a, b, c, d) {
    let n = a + b + c + d;
    return n * (a * d - b * c) * (a * d - b * c) / ((a + b) * (c + d) * (a + c) * (b + d));
}
function jc (x) {
    let ans = 1;
    for (let i = 1; i <= x; i++) ans = ans * i;
    return ans;
}
function C(n, m) { return jc(n) / (jc(m) * jc(n-m));}
console.log(X2(64, 16, 10, 10))