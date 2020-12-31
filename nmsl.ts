function Max(...data: number[]) {
    var ret: number = -2147483648;
    for (let i = 0; i < data.length; i++) {
        const element = data[i];
        ret = ret < element ? element : ret;
    }
    return ret;
}

function Command(...options: any[]) {
    options.forEach(elem => {
        console.assert(elem);
    });
}

function cucOvOcyc(param?: any) {
    if (param === void 0) {
        
    }
}


class A {

    new(): void {
        
    }
    
}
