#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
int m,n,sx,sy;
const int MAXN = 10001;
int ansx,ansy;
int num;
int a[MAXN][MAXN];
int mini=0x7fffffff;
inline int getdist(int x,int y){
	return abs(x-sx)+abs(y-sy);
}
int main(){
	freopen("friend.in","r",stdin);
	freopen("friend.out","w",stdout);
	scanf("%d%d",&m,&n);
	scanf("%d%d",&sx,&sy);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(i==sx&&j==sy){
				num=a[i][j];
			}
		}
	}
	//printf("the num is %d,the loc is %d,%d\n",num,sx,sy);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			//printf("%d,%d\n",i,j);
			if(a[i][j]==num&&(i!=sx||j!=sy)){
				//printf("%d,%d is a friend to %d,%d\n",i,j,sx,sy);
				//printf("the dist is %d\n",getdist(i,j));
				if(getdist(i,j)<mini){
					mini=getdist(i,j);
					ansx=i;ansy=j;
				}
			}
		}
	}
	printf("%d %d\n",ansx,ansy);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
