const { fstat } = require('fs');
var mysql = require('mysql');
const { stderr } = require('process');

var connection = mysql.createConnection({
    host     : 'localhost',
    user     : 'root',
    password : 'Kxcrdcnl1',
    database : 'grades'
});
 
connection.connect();
function max(x, y) { return x > y ? x : y; }
function min(x, y) { return x < y ? x : y; }


connection.query('SELECT * FROM Exams', function (error, results, fields) {
    if (error) throw error;
    var chinese_max = max(results[0].chinese, results[1].chinese);
    var math_max = max(results[0].math, results[1].math);
    var english_max = max(results[0].english, results[1].english);
    var physics_max = max(results[0].physics, results[1].physics);
    var chemistry_max = max(results[0].chemistry, results[1].chemistry);
    var biology_max = max(results[0].biology, results[1].biology);
    var politics_max = max(results[0].politics, results[1].politics);
    var history_max = max(results[0].history, results[1].history);
    var geography_max = max(results[0].geography, results[1].geography);
    var total_max = max(results[0].total, results[1].total);

    console.log('你的历史最高成绩 (顺序:语数英物化生政史地):', chinese_max, math_max, english_max, physics_max, chemistry_max, biology_max, politics_max, history_max, geography_max, total_max);
    
    var move_class = results[1].total_class_rank - results[0].total_class_rank;
    var move_grade = results[1].total_grade_rank - results[0].total_grade_rank;
    var move_city = results[1].total_city_rank - results[0].total_city_rank;
    console.log('你进步了:', move_class, '名(班级)', move_grade, '名(年级)', move_city, '名(全市)');
});


console.log(foo);
var foo = [];
if (foo instanceof Array) {
    
}