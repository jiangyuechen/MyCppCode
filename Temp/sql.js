var mysql = require('mysql');
var connection = mysql.createConnection({
    host     : 'localhost',
    user     : 'root',
    password : 'Kxcrdcnl1',
    database : 'test'
});
connection.connect();
var sql = 'SELECT * FROM test.ak_opt';
connection.query(sql, function (err, result) {
    if (err) {
        console.log("select error:", err.message);
        return;
    }
    console.log(result);
})
// connection.end();