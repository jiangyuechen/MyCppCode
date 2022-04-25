function X2(a, b, c, d) {
    let n = a + b + c + d;
    return n * (a * d - b * c) * (a * d - b * c) / ((a + b) * (c + d) * (a + c) * (b + d));
}
console.log ( X2 (45,165,30,60) );