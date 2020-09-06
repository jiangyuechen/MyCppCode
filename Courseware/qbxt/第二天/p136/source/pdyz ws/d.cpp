#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

#define rep(i,a,n) for(int i = a;i <= n;i++)
#define per(i,n,a) for(int i = n;i >= a;i--)
#define clr(a) memset(a,0,sizeof(a))
#define fwide FFF

const int Maxn = 20;
const int mod = 1e9+9;

ll lwide,fwide,ans;
int lhi[Maxn],fhi[Maxn];
int G[Maxn][Maxn],vis[Maxn][Maxn];

bool check(){
	int maxh;
	rep(i,1,lwide){
		maxh = 0;
		rep(j,1,fwide)maxh = max(maxh,G[i][j]);
		if(maxh!=lhi[i])return false;
	}
	rep(i,1,fwide){
		maxh = 0;
		rep(j,1,lwide)maxh = max(maxh,G[j][i]);
		if(maxh!=fhi[i])return false;
	}
	return true;
}

void print(){
	rep(i,1,lwide){
		rep(j,1,fwide)cout << G[i][j] << ' ';
		cout << endl;
	}
		cout << "-------------\n";
}

void dfs(int x,int y){
//	if(vis[x][y])return;
	if(y > fwide){dfs(x+1,1);return;}
	if(x > lwide){if(check())ans++;return;}
//	vis[x][y] = 1;
	int maxh = min(lhi[x],fhi[y]);
	rep(i,0,maxh){
		G[x][y] = i;
		dfs(x,y+1);
	}
	G[x][y] = 0;
//	vis[x][y] = 0;
	return;
}

int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	cin >> lwide;
	rep(i,1,lwide)cin >> lhi[i];
	cin >> fwide;
	rep(i,1,fwide)cin >> fhi[i];
	
//	rep(i,1,lwide)cout << lhi[i] << ' ';
//	cout << endl;
//	rep(i,1,fwide)cout << lhi[i] <<' ';
//	cout << endl; 
	
	clr(G);clr(vis);
	dfs(1,1);
	cout << ans%mod;
return 0;
}
