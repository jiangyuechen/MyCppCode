#include<cstdio>
using namespace std;
int n,a,b;
int ans[100]={0,1};
bool k[100]={1,1};
int qwe(int x){
	if(k[x])return ans[x];
	ans[x]=a*qwe(x-1)+b*qwe(x-2);
	return ans[x];
}
int main(){
	freopen("c.in.txt","r",stdin);
	freopen("c.out.txt","w",stdout);
	scanf("%d%d%d",&n,&a,&b);
	int m=qwe(n);
	printf("%d",qwe(m));
return 0;
}
