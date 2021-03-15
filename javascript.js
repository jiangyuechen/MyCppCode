'use strict';
var s = new Function();
s.prototype.a = new Number (5);
s.prototype.b = new Number (6);
s.prototype.fn = function() {return this.a + this.b;}
console.log(s.prototype.fn());