function Max(...array: number[]) {
    var ret: number = -2147483648;
    for (var i = 0; i < array.length; i++) {
        ret = array[i] > ret ? array[i] : ret;
    }
    return ret;
}
function Min(...array: number[]) {
    var ret: number = 2147483647;
    for (var i = 0; i < array.length; i++) {
        ret = array[i] < ret ? array[i] : ret;
    }
    return ret;
}

function Average(...array: number[]) {
    var total: number = 0;
    for (var i = 0; i < array.length; i++) {
        total += array[i];
    }
    return total / array.length;
}

export { Max, Min, Average };

class Show {
    x: number;
    y: number;

    total(): number{
        return this.x + this.y;
    }
    set(_x: number, _y: number): void { this.x = _x; this.y = _y; }
    setx(_x: number): void { this.x = _x; }
    sety(_y: number): void { this.y = _y; }
    setDefault(): void { this.x = this.y = 0; }
    constructor(_x: number, _y: number) { this.x = _x; this.y = _y; }
}

class __Extend_show extends Show{
    getx(): number { return this.x; }
    gety(): number { return this.y; }
    constructor(_x: number, _y: number) { super(_x, _y); }
}

function swap(_x: number &, _y: number &) {
    
}

var sh = new Show(1, 2);
sh.setDefault();
sh.set(2, 3);

var Uvuvwevwevwe_Onyetenyevwe_Ugwemuhwem_Osas = new __Extend_show(1, 2);