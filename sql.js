var mysql = require('mysql');
var connection = mysql.createConnection({
    host: 'localhost',
    user     : 'root',
    password : 'Kxcrdcnl1',
    database : 'temp'
});
connection.connect();
var sql = 'SELECT * FROM temp.arknights_opt WHERE code_name_en=\"Amiya\";';
connection.query(sql, function (err, result) {
    if (err) {
        console.log("select error:", err.message);
        return;
    }
    console.log(result);
})
// connection.end();