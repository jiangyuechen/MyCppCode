var http = require('http');
function Set(x) {
    console.log(x.msg, x.association, x.collectable);
    return {
        paramStatus: 0,
        returnStatus: 0,
        thrownError: [],
        applicableLanguage: [
            "ZH_CN",
            "EN_US",
            "FR"
        ],
        time: Date(Date.now())
    };
}

const SETRETURN = Set({
    msg: "haha",
    association: 1,
    collectable: false
});

SETRETURN.returnStatus = 1;
console.log(SETRETURN.time);