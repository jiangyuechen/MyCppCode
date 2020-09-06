#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<algorithm>

using namespace std;

#define problem "a"
#define prename "a"

char djm[1000];

int cases=10;

int mode=1;

int getrand()
{
	return (rand()<<15)+rand();
}

bool prime(int x)
{
	if (x<2) return false;
	for (int y=2;y*y<=x;y++)
		if (x%y==0) return false;
	return true;
}

void make_data(int test)
{
	int n;
	if (test<=1) n=1;
	else if (test<=4) n=6;
	else n=100;
	int p=1;
	if (test>=5 && test<=6) p=2;
	else
	{
		p=1;
		while (!prime(p))
			p=getrand()%1000000000+1;
	}	
	printf("%d %d\n",n,p);
	for (int a=1;a<=n;a++)
		for (int b=1;b<=n;b++)
			printf("%d%c",getrand()%p,b==n?'\n':' ');
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
