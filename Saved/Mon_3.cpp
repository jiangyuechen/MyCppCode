#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1001;
int from[3][3];
int to[3][3];
int origin[3][3];
int n;
void output(){
    cout<<"debug:"<<endl;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            cout<<from[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool ok()
{
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            if (from[i][j] != to[i][j])
                return false;
        }
    }
    return true;
}
void up_down()
{
    swap(from[1][1], from[2][1]);
    swap(from[1][2], from[2][2]);
}
void left_right()
{
    swap(from[1][1], from[1][2]);
    swap(from[2][1], from[2][2]);
}
void reset()
{
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            from[i][j] = origin[i][j];
        }
    }
}
int main()
{
    cin >> n;
    if(n == 1){
        cin>>from[1][1]>>from[2][1];
        cin>>to[1][1]>>to[2][1];
        if(from[1][1]==to[1][1]&&from[2][1]==to[2][1]) cout<<0<<endl;
        else cout<<"dldsgay!!1"<<endl;
        system("pause");
        return 0;
    }
    if (n == 2)
    {
        for (int i = 1; i <= 2; i++)
        {
            for (int j = 1; j <= 2; j++)
            {
                cin >> from[i][j];
                origin[i][j] = from[i][j];
            }
        }
        for (int i = 1; i <= 2; i++)
        {
            for (int j = 1; j <= 2; j++)
            {
                cin >> to[i][j];
            }
        }
        if(ok()){
            cout<<0<<endl;
            system("pause");
            return 0;
        }
        up_down();
        if (ok())
        {
            cout << 1 << endl;
            system("pause");
            return 0;
        }
        reset();
        left_right();
        if (ok())
        {
            cout << 1 << endl;
            system("pause");
            return 0;
        }
        reset();
        up_down();
        left_right();
        if (ok())
        {
            cout << 2 << endl;
            system("pause");
            return 0;
        }
        cout<<"dldsgay!!1"<<endl;
        system("pause");
        return 0;
    }
}