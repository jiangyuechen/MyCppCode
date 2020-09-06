/**********************By. SZOI-Kench***********************/
//                            _ooOoo_  
//                           o8888888o  
//                           88" . "88  
//                           (| -_- |)  
//                            O\ = /O  
//                        ____/`---'\____  
//                      .   ' \\| |// `.  
//                       / \\||| : |||// \  
//                     / _||||| -:- |||||- \  
//                       | | \\\ - /// | |  
//                     | \_| ''\---/'' | |  
//                      \ .-\__ `-` ___/-. /  
//                   ___`. .' /--.--\ `. . __  
//                ."" '< `.___\_<|>_/___.' >'"".  
//               | | : `- \`.;`\ _ /`;.`/ - ` : | |  
//                 \ \ `-. \_ __\ /__ _/ .-` / /  
//         ======`-.____`-.___\_____/___.-`____.-'======  
//                            `=---='  
//  
//         .............................................  
//                  佛祖保佑             永无BUG 
//          佛曰:  
//                  写字楼里写字间，写字间里程序员；  
//                  程序人员写程序，又拿程序换酒钱。  
//                  酒醒只在网上坐，酒醉还来网下眠；  
//                  酒醉酒醒日复日，网上网下年复年。  
//                  但愿老死电脑间，不愿鞠躬老板前；  
//                  奔驰宝马贵者趣，公交自行程序员。  
//                  别人笑我忒疯癫，我笑自己命太贱；  
//                  不见满街漂亮妹，哪个归得程序员？
#include<cstdio>
#include<iostream>
#define LL long long 
using namespace std;
const int N=105;
LL mod;
int n,m;
LL f[N][N<<1];
LL r,ret;
// 写这段代码的时候，只有上帝和我知道它是干嘛的
LL ksm(LL u,LL v){
    ret=1;
    while(v){
        if(v&1)ret=ret*u%mod;
        u=u*u%mod;v>>=1;
    }
    return ret;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
    cin>>n>>mod;
	m=n*2;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;j++)
			cin>>f[i][j];
        f[i][n+i]=1;
    }
    // 现在只有上帝知道
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;j++)
        if(f[j][i]){
            for(int k=1;k<=m;k++)
            swap(f[i][k],f[j][k]);
            break;
        }
        r=ksm(f[i][i],mod-2);
        for(int j=i;j<=m;++j)
        f[i][j]=f[i][j]*r%mod;
        for(int j=1;j<=n;++j)
        if(j!=i){
            r=f[j][i];
            for(int k=i;k<=m;++k)
            f[j][k]=(f[j][k]-r*f[i][k]%mod+mod)%mod;
        }
    }
    for(int i=1;i<=n;++i,puts(""))
    	for(int j=n+1;j<=m;++j)
			cout<<f[i][j]<<" ";
}
