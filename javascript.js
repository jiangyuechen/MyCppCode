var http = require('http');
function Set(x) {
    console.log(x.msg, x.association, x.collectable);
}

Set({
    msg: "haha",
    association: 1,
    collectable: false
});