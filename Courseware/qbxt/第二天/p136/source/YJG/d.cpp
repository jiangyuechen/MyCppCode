#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);	
	srand(time(0));
	int n = rand() % 1000000009;
	cout << n;
	return 0;
}
