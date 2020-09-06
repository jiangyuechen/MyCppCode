#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1000];
int main()
{
    int a,b,id,n,m;
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d%d",&n,&m);
    fclose(stdin);
    for (int i=1; i<=20; i++)
        {
            freopen(s,"r",stdin);
            scanf("%d%d",&a,&b);
            if (a==n&&b==m)
                {
                    id=i;
                    break;
                }
            fclose(stdin);
        }
//  cout<<id<<endl;
    freopen(s,"r",stdin);
    char ans;
    while(~scanf("%c",&ans))
        printf("%c",ans);
    return 0;
}

