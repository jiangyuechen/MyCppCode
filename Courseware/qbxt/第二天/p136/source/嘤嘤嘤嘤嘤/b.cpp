#include "iostream"
#include "cstdio"
#include "algorithm"
#include "cstring"
#include "string"
#include "cmath"
#define int long long
using namespace std;
int n,k;
int a,b;
/*
N位大佬在研究幽魂炸弹，由于这个研究非常重要，所以他们用a把锁把炸弹锁住了。每把锁有自己所对应的
钥匙，但是大佬比较皮，他们不一定需要每个人都拥有所有的钥匙，只需要保证有k个大佬在一起的时候一定
能打开所有的锁， 并且少于k个大佬在一起的时候就一定没办法打开所有的锁。假设每个大佬钥匙的数量都
是b，给定N,k，求a,b的最小值。 

3位大佬在研究幽魂炸弹，由于这个研究非常重要，所以他们用a把锁把炸弹锁住了。每把锁有自己所对应的
钥匙，但是大佬比较皮，他们不一定需要每个人都拥有所有的钥匙，只需要保证有2个大佬在一起的时候一定
能打开所有的锁， 并且少于2个大佬在一起的时候就一定没办法打开所有的锁。假设每个大佬钥匙的数量都
是b，给定N,k，求a,b的最小值。 
*/
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin >> n >> k;
	if(n - k == 1) a = n,b = k;
	cout << a << ' ' << b << endl;
	return 0;
}
