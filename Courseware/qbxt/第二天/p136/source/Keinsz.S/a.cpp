#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std ;

typedef long long LL ;
const LL MAXN = 10001 ;
const LL MAXM = 10001 ;
const LL Inf = 0x7fffffff ;

LL N, M, A[MAXN][MAXN], D, Mod ;

inline LL Read() {
	LL X = 0, F = 1 ; char ch = getchar() ;
	while (ch > '9' || ch < '0') F = (ch == '-' ? - 1 : 1), ch = getchar() ;
	while (ch >= '0' && ch <= '9') X=(X<<1)+(X<<3)+(ch^48), ch = getchar() ;
	return X * F ;
}

inline LL Inverse_Element(LL X, LL Y, LL Mod) {
	LL Ans = 1 ; while (Y) {
		if (Y & 1) Ans = Ans * X % Mod ;
		X = X * X % Mod ; Y >>= 1 ;
	}	return Ans ;
}

inline void Gauss_Elimination() {
	for (LL i = 1 ; i <= N ; ++ i) {
	    for (LL j = i ; j <= N ; j ++) 
		    if (A[j][i]) {
			    for (LL k = 1 ; k <= M ; k ++)
				    swap(A[i][k], A[j][k]) ;
			    break ;
		    }
		    if (! A[i][i]) { printf("No Solution") ; exit(0) ;}
		    D = Inverse_Element(A[i][i], Mod - 2, Mod) ;
		    for (LL j = i ; j <= M ; ++ j)
			    A[i][j] = A[i][j] * D % Mod ;
		    for (LL j = 1 ; j <= N ; ++ j)
			    if (j != i) {
				    D = A[j][i] ;
				    for (LL k = i ; k <= M ; ++ k)
					    A[j][k] = (A[j][k] - D * A[i][k] % Mod + Mod) % Mod ;
			    }
	}		
}

int main() {
	freopen("a.in", "r", stdin) ;
	freopen("a.out", "w", stdout) ;
	N = Read() ; Mod = Read() ;	M = N << 1 ;
	for (LL i = 1 ; i <= N ; i ++)
	for (LL j = 1 ; j <= N ; j ++)
		A[i][j] = Read(), A[i][i + N] = 1;
	Gauss_Elimination() ;
	for (LL i = 1 ; i <= N ; i ++) {
		for (LL j = N + 1 ; j <= M ; j++)
			printf("%lld ", A[i][j] % Mod) ;
		printf("\n") ;
	}
	fclose(stdin) ; fclose(stdout) ;
	return 0 ;
}	