#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int n,p,m1[110][110],m2[110][110],m3[110][110];

int main(int argc,char *argv[])
{
	FILE *fin = fopen(argv[1],"r");
	FILE *fout = fopen(argv[2],"r");
	FILE *fsc = fopen(argv[5],"w");
	FILE *finf = fopen(argv[6],"w");

	fscanf(fin,"%d%d",&n,&p);
	for (int a=1;a<=n;a++)
		for (int b=1;b<=n;b++)
			fscanf(fin,"%d",&m1[a][b]);
	for (int a=1;a<=n;a++)
		for (int b=1;b<=n;b++)
			fscanf(fout,"%d",&m2[a][b]);
	for (int a=1;a<=n;a++)
		for (int b=1;b<=n;b++)
			for (int c=1;c<=n;c++)
				m3[a][c]=(m3[a][c]+(long long)m1[a][b]*m2[b][c])%p;
	bool wrong=false;
	for (int a=1;a<=n;a++)
		for (int b=1;b<=n;b++)
			if (a==b)
			{
				if (m3[a][b]!=1) wrong=true;
			}
			else
			{
				if (m3[a][b]) wrong=true;
			}
	if (wrong)
	{
		fprintf(fsc,"0\n");
		fprintf(finf,"niu bi o\n");
	}
	else
	{
		fprintf(fsc,"%s\n",argv[4]);
		fprintf(finf,"zhen de niu bi o\n");
	}


	return 0;
}
