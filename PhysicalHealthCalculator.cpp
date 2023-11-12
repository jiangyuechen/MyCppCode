#include <iostream>
using namespace std;

int main()
{
    int bmi = 0, fhl = 0, zwtqq = 0, ldty = 0, p50 = 0, p1000 = 0, ytxs = 0;
    cout << "BMI:";
    cin >> bmi;
    cout << "肺活量:";
    cin >> fhl;
    cout << "坐位体前屈:";
    cin >> zwtqq;
    cout << "立定跳远:";
    cin >> ldty;
    cout << "50米跑:";
    cin >> p50;
    cout << "1000米跑:";
    cin >> p1000;
    cout << "引体向上:";
    cin >> ytxs;
    double score = bmi * 0.15 + fhl * 0.15 + zwtqq * 0.1 + ldty * 0.1 + p50 * 0.2 + p1000 * 0.2 + ytxs * 0.1;
    cout << "你最后的成绩是:" << score << endl;
    system("pause");
    return 0;
}