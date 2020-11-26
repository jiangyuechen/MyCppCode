"use strict";
"properities default";
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
exports.get_total = exports.get_max = exports.get_average = exports["default"] = exports.foo = void 0;
var __base = /** @class */ (function () {
    function __base(_a, _b) {
        this.a = _a;
        this.b = _b;
    }
    __base.prototype.fn = function () {
        return this.a + this.b;
    };
    return __base;
}());
var __derived = /** @class */ (function (_super) {
    __extends(__derived, _super);
    function __derived(_a, _b, _c) {
        var _this = _super.call(this, _a, _b) || this;
        _this.c = _c;
        return _this;
    }
    return __derived;
}(__base));
function get_total() {
    var data = [];
    for (var _i = 0; _i < arguments.length; _i++) {
        data[_i] = arguments[_i];
    }
    var total = 0;
    for (var index = 0; index < data.length; index++) {
        var element = data[index];
        total += element;
    }
    return total;
}
exports.get_total = get_total;
function get_average() {
    var data = [];
    for (var _i = 0; _i < arguments.length; _i++) {
        data[_i] = arguments[_i];
    }
    return get_total.apply(void 0, data) / data.length;
}
exports.get_average = get_average;
function get_max() {
    var data = [];
    for (var _i = 0; _i < arguments.length; _i++) {
        data[_i] = arguments[_i];
    }
    var max = Number.MIN_VALUE;
    for (var index = 0; index < data.length; index++) {
        var element = data[index];
        max = max > element ? max : element;
    }
    return max;
}
exports.get_max = get_max;
function get_attribute(add) {
}
exports.foo = function (a, b) {
    return a + b;
};
exports["default"] = exports.foo;
console.log(get_total(1, 2, 3, 4, 5, 6), get_max(1, 2, 3, 4, 5, 6));
console.assert(false, 1, 2, 3, 4, 5);
var b;
b instanceof __base;
b instanceof __derived;
var nmsl = /** @class */ (function () {
    function nmsl() {
    }
    Object.defineProperty(nmsl.prototype, "value", {
        get: function () {
            return this.s;
        },
        set: function (_s) {
            this.s = _s;
        },
        enumerable: false,
        configurable: true
    });
    return nmsl;
}());
