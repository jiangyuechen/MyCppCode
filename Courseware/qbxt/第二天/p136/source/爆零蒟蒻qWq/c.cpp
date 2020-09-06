#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
const ll mod=1e6+7;
ll b[10001],n,t,p,q,a1,a2;
ll a[11][10001],erjinzhi[20001],eetop;
int chu(int ga)
{
	long long x=0;
	long long ff=(a[ga][1]&1)?1:0;
	memset(b,0,sizeof(b));
    for(ll i=250;i>=1;i--){
        x=x*10+a[ga][i];
        b[i]=x/2;
        x%=2;
    }
    for(ll i=1;i<=250;i++) a[ga][i]=b[i];
    return ff;
}
void cheng(int ga){
	for(int i=1;i<=250;i++){
		a[ga][i]+=a[ga-1][i]*p,a[ga][i]+=a[ga-2][i]*q;
	}
	for(int i=1;i<=250;i++){
		if(a[ga][i]>=10){
			a[ga][i+1]+=(a[ga][i]/10),a[ga][i]%=10;
		}
	}
}
bool is_ling(){
	for(int i=250;i>=1;i--){
		if(a[n][i])return false;
	}
	return true;
}
void zhuan_erjinzhi(){
	int kk=n;
	for(int i=1;i<=250;i++){
		erjinzhi[++eetop]=chu(n);
		if(is_ling())break;
	}
}
struct mat{
	ll m[4][4];
	mat(){
		memset(a,0,sizeof(a));
	}
}ans,bas;
void intt(int rrp)
{
	ans.m[1][1]=a2;
	ans.m[1][2]=a1;
	bas.m[1][1]=p;
	bas.m[2][1]=q;
	bas.m[1][2]=1;
}
mat mul(mat a,mat b)
{
	mat res;
	memset(res.m,0,sizeof(res.m));
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=2;j++)
		{
			for(int k=1;k<=2;k++){
				res.m[i][j]+=(a.m[i][k]%mod)*(b.m[k][j]%mod);
				res.m[i][j]%=mod;
			}
		}
	}
	return res;
}
void jian(){
	erjinzhi[1]--;
	for(int i=1;i<=250;i++){
		if(erjinzhi[i]<0){
			erjinzhi[i+1]--;erjinzhi[i]=0;
		}
	}
}
void qpow()
{
	for(int i=1;i<=eetop;i++){
		if(erjinzhi[i])ans=mul(ans,bas);
		bas=mul(bas,bas);
		p>>=1;
	}
}
int main()
{
//	b[1]=1;
//	for(int i=2;i<=1001;i++) b[i]=(2*b[i-2]+b[i-1])%mod;
//	cout<<b[341]<<"\n";
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	a1=0,a2=1;
	cin>>n>>p>>q;
	a[1][0]=0,a[1][1]=1;
	if(n==1){
		return printf("%lld",a1),0;
	}
	if(n==2){
		return printf("%lld",a2),0;
	}
	intt(4);
	for(int i=2;i<=10;i++) cheng(i);
	zhuan_erjinzhi();jian();
//	for(int i=20;i>=1;i--)std::cout<<erjinzhi[i];
	qpow();
	ll anss=ans.m[1][1];
	anss%=mod;
	return printf("%lld",anss),0;
}
