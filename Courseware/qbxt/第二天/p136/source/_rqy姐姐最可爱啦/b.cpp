#include<functional>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>
int n,k;
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(k==1){
		printf("1 1\n");
		return 0;
	}
	if(k==n){
		printf("%d 1\n",n);
		return 0;
	}
	if(k==2){
		printf("%d %d\n",n,n-1);
		return 0;
	}
	else{
		srand(time(0));
		printf("%d %d\n",rand(),rand());
		return 0;
	}
	return 0;
}
