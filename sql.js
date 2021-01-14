var mysql = require('mysql');
var h = window.prompt('请输入主机');
var u = window.prompt('请输入用户名');
var p = window.prompt('请输入密码');
var d = window.prompt('请输入数据库');
// var connection = mysql.createConnection({
//   host     : 'localhost',
//   user     : 'root',
//   password : 'Kxcrdcnl1',
//   database : 'grades'
// });
 
var connection = mysql.createConnection({
  host     : h,
  user     : u,
  password : p,
  database : d
});

connection.connect();
 
connection.query('select * from Exams', function (error, results, fields) {
  if (error) throw error;
//console.log('The solution is: ', results);
  document.write(results);
});
