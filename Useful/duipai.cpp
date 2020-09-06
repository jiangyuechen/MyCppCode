#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int random(int a,int b){
	int c=b-a;
	int d=rand()%c;
	return d+a;
}
int N,M,T[10001];
int main()
{
	srand((unsigned)time(0));
	//freopen("C:\\11.txt","w",stdout);
	N=random(1000,5000);
	M=random(1000,5000);
	cout<<N<<" "<<M<<endl;
	for(int i=1;i<=N;i++){
		T[i]=random(1,100);
		cout<<T[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=T[i];j++){
			cout<<random(-10000,10000)<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=M;i++){
		int k=random(1,N),l=random(1,N);
		cout<<k<<" "<<random(0,T[k])<<"  "<<l<<" "<<random(0,T[l])<<endl;
	}
	//fclose(stdout);
	system("pause");
	return 0;
}

