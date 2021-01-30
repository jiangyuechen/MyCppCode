var mysql = require('mysql');
var connection = mysql.createConnection({
    host     : 'localhost',
    user     : 'root',
    password : 'Kxcrdcnl1',
    database : 'grades'
});
 
connection.connect();
 
connection.query('select * from Exams', function (error, results, fields) {
    if (error) throw error;
    console.log('The solution is: ', results);
});