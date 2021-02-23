#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long
#define _max(i,j) ((i)>(j)?(i):(j))
#define _min(i,j) ((i)<(j)?(i):(j))
#define re register
using namespace std;
const int _Maxdigit = 32768;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
struct Bigint {

	short z[_Maxdigit], len;

	void reset() {
		memset(z, 0, sizeof(z));
		len = 0;
	}

	void read(const string& str) {
		reset();
		len = str.length();
		for (int _it = 1; _it <= str.length(); _it++) {
			z[_it] = str[len - _it] - '0';
		}
	}
	void read() {
		reset();
		string obj;
		cin >> obj;
		read(obj);
	}

	void write() {
		for (int _it = len; _it >= 1; _it--) {
			cout << z[_it];
		}
	}


	Bigint() {
		reset();
	}
	Bigint(const string& str) {
		reset();
		read(str);
	}
	short& operator[](const int& digit) {
		return this->z[digit];
	}
	bool operator<(const Bigint& bi) {
		if (this->len != bi.len) return this->len < bi.len;
		else {
			for (int _it = this->len; _it >= 1; _it--) {
				if (this->z[_it] < bi.z[_it]) return true;
				else if (this->z[_it] > bi.z[_it]) return false;
			}
		}
		return false;
	}
	bool operator>=(const Bigint& bi) {
		return !(*this < bi);
	}
	bool operator<=(const Bigint& bi) {
		if (this->len != bi.len) return this->len < bi.len;
		else {
			for (int _it = this->len; _it >= 1; _it--) {
				if (this->z[_it] < bi.z[_it]) return true;
				else if (this->z[_it] > bi.z[_it]) return false;
			}
		}
		return true;
	}
	bool operator>(const Bigint& bi) {
		return !(*this <= bi);
	}
	Bigint operator+(const Bigint& bi) {
		Bigint res;
		res.len = _max(this->len, bi.len);
		for (int _it = 1; _it <= res.len; _it++) {
			res.z[_it] += this->z[_it] + bi.z[_it];
			if (res.z[_it] >= 10) {
				res.z[_it] -= 10;
				res.z[_it + 1]++;
			}
		}
		while (res[res.len + 1]) res.len++;
		return res;
	}
	Bigint operator-(const Bigint& bi) {
		Bigint res;
		res.len = _max(this->len, bi.len);
		for (int _it = 1; _it <= res.len; _it++) {
			res.z[_it] += this->z[_it] - bi.z[_it];
			if (res.z[_it] < 0) {
				res.z[_it] += 10;
				res.z[_it + 1]--;
			}
		}
		while (!res.z[res.len] && res.len > 1) res.len--;
		return res;
	}
	Bigint operator*(const Bigint& bi) {
		Bigint res;
		if ((this->len == 1 && this->z[1] == 0) || (bi.len == 1 && bi.z[1] == 0)) {
			return res;
		}
		res.len = this->len + bi.len - 1;
		for (int i = 1; i <= len; i++) {
			for (int j = 1; j <= bi.len; j++) {
				res.z[i + j - 1] += this->z[i] * bi.z[j];
				res.z[i + j] += res.z[i + j - 1] / 10;
				res.z[i + j - 1] %= 10;
			}
		}
		while (res.z[res.len + 1]) res.len++;
		return res;
	}
	void operator++() {
		Bigint temp("1");
		*this = *this + temp;
	}
};
int t, n, key;
int main() {
	t = read();
	for (int i = 1; i <= t; i++) {
		n = read(); key = read();
		Bigint num("1");
		for (Bigint j("1"); j < ; p++) {
			num = num * j;
		}
		int ans = 0;
		for (int i = 0; i <= num.len; i++) {
			if (num[i] == key) ans++;
		}
		printf("%d\n", ans);
	}
}

