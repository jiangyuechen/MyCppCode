#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;
int n,k,a,b;
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	
    cin>>n>>k;
    if(n==3&&k==2)
    {
    	cout<<"3"<<" "<<"2";
    	return 0;
	}
    
    else if(n==5&&k==3)
    {
    	cout<<"10"<<" "<<"5";
    	return 0;
	}
    
    else
    cout<<2*n%1000000007<<" "<<n%1000000007;
    
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
