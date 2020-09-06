#include<iostream>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<algorithm>
using namespace std;
int n,k,a,b,mo=1000000007;
int main()
{freopen("a.in","r",stdin);
 freopen("a.out","w",stdout);
  scanf("%d%d",&n,&k);
   for(int j=n;;j++)
   {for(int i=1;;i++)
     {if(k*i>=j){a=j%mo;b=i%mo;printf("%d %d",a,b);return 0;}
       }
     }
   fclose(stdin);
  fclose(stdout);
}
