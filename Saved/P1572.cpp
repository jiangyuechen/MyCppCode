#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
using namespace std;
int fenzi,fenmu;
string s;
int main(){
    cin>>s;
    if(s[0]!='-') s='+'+s;
    int temp=0;
    bool neg=false;
    for(int i=0;i<s.length();i++){
        if(s[i]=='+'||s[i]=='-'){
            fenmu+=(neg?-temp:temp);
            temp=0;
            neg=(s[i]=='+'?false:true);
        }
        else if(isdigit(s[i])){
            temp=(temp*10+s[i]-'0');
        }
        else if(s[i]=='/'){
            fenzi+=(neg?-temp:temp);
            temp=0;
        }
    }
    cout<<fenzi<<endl<<fenmu<<endl;
    system("pause");
    return 0;
}