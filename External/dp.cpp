#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	//	for(int i=1;i<=5000;i++)//���Դ���
	//	{
	//		system("C:\\make_data.exe");
	//		double begin=clock();
	//		system("C:\\qjyq.exe");
	//		double end=clock();
	//		system("C:\\std.exe");
	//		if(system("fc C:\\std.txt C:\\ qjyq.txt"))
	//		{
	//			puts("Wrong answer");
	//			return 0;
	//		}
	//		else
	//			printf("Accepted ���Ե�#%d  ��ʱ %.0lfms\n",i,end-begin);
	//	}
	//
	for (int i = 1; i <= 500; i++)
	{
		system("make_data.exe > make_data.txt");
		system("std.exe < make_data.txt > std.txt");
		double begin = clock();
		system("qjyq.exe <make_data.txt > qjyq.txt");
		double end = clock();
		if (system("fc qjyq.txt std.txt"))
		{
			puts("Wrong answer");
			return 0;
		}
		else
			printf("Accepted ���Ե�#%d  ��ʱ %.0lfms\n", i, end - begin);
	}
}
