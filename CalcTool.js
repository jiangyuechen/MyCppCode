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
exports.Average = exports.Min = exports.Max = void 0;
function Max() {
    var array = [];
    for (var _i = 0; _i < arguments.length; _i++) {
        array[_i] = arguments[_i];
    }
    var ret = -2147483648;
    for (var i = 0; i < array.length; i++) {
        ret = array[i] > ret ? array[i] : ret;
    }
    return ret;
}
exports.Max = Max;
function Min() {
    var array = [];
    for (var _i = 0; _i < arguments.length; _i++) {
        array[_i] = arguments[_i];
    }
    var ret = 2147483647;
    for (var i = 0; i < array.length; i++) {
        ret = array[i] < ret ? array[i] : ret;
    }
    return ret;
}
exports.Min = Min;
function Average() {
    var array = [];
    for (var _i = 0; _i < arguments.length; _i++) {
        array[_i] = arguments[_i];
    }
    var total = 0;
    for (var i = 0; i < array.length; i++) {
        total += array[i];
    }
    return total / array.length;
}
exports.Average = Average;
var Show = /** @class */ (function () {
    function Show(_x, _y) {
        this.x = _x;
        this.y = _y;
    }
    Show.prototype.total = function () {
        return this.x + this.y;
    };
    Show.prototype.set = function (_x, _y) { this.x = _x; this.y = _y; };
    Show.prototype.setx = function (_x) { this.x = _x; };
    Show.prototype.sety = function (_y) { this.y = _y; };
    Show.prototype.setDefault = function () { this.x = this.y = 0; };
    return Show;
}());
var __Extend_show = /** @class */ (function (_super) {
    __extends(__Extend_show, _super);
    function __Extend_show(_x, _y) {
        return _super.call(this, _x, _y) || this;
    }
    __Extend_show.prototype.getx = function () { return this.x; };
    __Extend_show.prototype.gety = function () { return this.y; };
    return __Extend_show;
}(Show));
var sh = new Show(1, 2);
sh.setDefault();
sh.set(2, 3);
var Uvuvwevwevwe_Onyetenyevwe_Ugwemuhwem_Osas = new __Extend_show(1, 2);
