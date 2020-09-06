#include<iostream>
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll N,M,minn;
ll Nn[1008666],Mm[1008666];
ll Cat[25] = {1,2,5,14,42,132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190, 6564120420, 24466267020, 91482563640, 343059613650, 1289904147324, 4861946401452};
int main() 
{
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
	scanf("%lld",&N);
    for(int i=1;i<=N;i++)
    scanf("%lld",&Nn[i]);
    for(int i=1;i<=M;i++)
    scanf("%lld",&Mm[i]);
    for(int i=1;i<=min(N,M);i++)
    minn = min(Nn[i],Mm[i]);
    printf("%lld",Cat[minn - 2]);
    return 0;
}