#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')  f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
const int mod=1e9+9;
long long s;
int main()
{
	freopen("d.in","r",stdin); 
	freopen("d.out","w",stdout);
	srand(time(NULL));
	s=rand()%mod;
	cout<<s;
	fclose(stdin);  fclose(stdout);
	return 0;
}
