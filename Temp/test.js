"use strict";
var __extends = (this && this.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (Object.prototype.hasOwnProperty.call(b, p)) d[p] = b[p]; };
        return extendStatics(d, b);
    };
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();
exports.__esModule = true;
exports.foo = exports.__derived = exports.__exports = void 0;
function default_1() {
    console.log("this is a module.");
}
exports["default"] = default_1;
var __exports = /** @class */ (function () {
    function __exports(_a, _b) {
        this.a = _a;
        this.b = _b;
    }
    __exports.prototype.fn = function () {
        return this.a + this.b;
    };
    return __exports;
}());
exports.__exports = __exports;
var __derived = /** @class */ (function (_super) {
    __extends(__derived, _super);
    function __derived(_a, _b, _c) {
        var _this = _super.call(this, _a, _b) || this;
        _this.c = _c;
        return _this;
    }
    return __derived;
}(__exports));
exports.__derived = __derived;
exports.foo = function (a, b) {
    return a + b;
};
var a = exports.foo("114", "514");
var x = "123" + 4;
var p = (function (a, b) { return a < b; })(1, 2);
var dv = new __derived(1, 2, 3);
var dv_ss = dv instanceof __derived;
