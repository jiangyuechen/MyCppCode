#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<algorithm>

using namespace std;

#define problem "c"
#define prename "a"

char djm[1000];

int cases=10;

int mode=1;

int getrand()
{
	return (rand()<<15)+rand();
}

void make_data(int test)
{
	long long n=1ll*getrand()*getrand();
	int a=getrand()%1000000001;
	int b=getrand()%1000000001;
	if (test<=2) n=rand()%10+1,a=rand()%2+2,b=rand()%2+2;
	if (test>=3 && test<=4) a=b=1;
	if (test>=5 && test<=6) b=0;
	if (test>=9 && test<=10)
	{
		if (a&1) a+=1;
		if (b&1) b+=2;
	}
	printf("%I64d %d %d\n",n,a,b);
}

int main()
{
	//srand(time(0));

	for (int a=1;a<=cases;a++)
	{
		fprintf(stderr,"%d\n",a);
		if (mode == 1)
		{
			sprintf(djm,problem "%d.in",a);
			freopen(djm,"w",stdout);

			make_data(a);

			fclose(stdout);

#ifdef unix
			sprintf(djm,"./" problem " < " problem "%d.in > " problem "%d.out",a,a);
#else
			sprintf(djm,problem ".exe < " problem "%d.in > " problem "%d.out",a,a);
#endif
			system(djm);
		}
		if (mode == 2)
		{
#ifdef unix
			sprintf(djm,"mv " prename "%d.in " problem "%d.in",a,a);
#else
			sprintf(djm,"rename " prename "%d.in " problem "%d.in",a,a);
#endif
			system(djm);

#ifdef unix
			sprintf(djm,"mv " prename "%d.out " problem "%d.out",a,a);
#else
			sprintf(djm,"rename " prename "%d.out " problem "%d.out",a,a);
#endif
			system(djm);
		}
	}

	return 0;
}
