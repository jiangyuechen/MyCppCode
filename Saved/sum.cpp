#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int n;
bool ok;
void dfs(int x,int num){
    if(x<0||num<0) return;
    if(num==0){
        if(x!=0) return;
        else if(x==0){
            ok = true;
            return;
        }
    }
    for (int i = 0; i < 10;i++){
        dfs(x - a[i], num - 1);
    }
}
int main(){
    freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
    cin >> n;
    while(n!=-1){
        for (int i = 1; i <= 10;i++){
            dfs(n, i);
            if(ok){
                cout << "YES" << endl;
                break;
            }
        }
        if(!ok){
            cout << "NO" << endl;
        }
        ok = false;
        cin >> n;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}