#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 205, MAXM = 21;
struct Bigint {
    short z[MAXN], len;

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

    Bigint() { reset(); }
    Bigint(const string& str) {
        reset();
        read(str);
    }
    Bigint(const int& str) {
        reset();
        string real_str = to_string(str);
        read(real_str);
    }
    void SetInfinite() {
        for (int i = 0; i <= MAXN; i++) {
            z[i] = 9;
        }
    }
    short& operator[](const int& digit) { return this->z[digit]; }
    bool operator<(const Bigint& bi) {
        if (this->len != bi.len)
            return this->len < bi.len;
        else {
            for (int _it = this->len; _it >= 1; _it--) {
                if (this->z[_it] < bi.z[_it])
                    return true;
                else if (this->z[_it] > bi.z[_it])
                    return false;
            }
        }
        return false;
    }
    bool operator>=(const Bigint& bi) { return !(*this < bi); }
    bool operator<=(const Bigint& bi) {
        if (this->len != bi.len)
            return this->len < bi.len;
        else {
            for (int _it = this->len; _it >= 1; _it--) {
                if (this->z[_it] < bi.z[_it])
                    return true;
                else if (this->z[_it] > bi.z[_it])
                    return false;
            }
        }
        return true;
    }
    bool operator>(const Bigint& bi) { return !(*this <= bi); }
    Bigint operator+(const Bigint& bi) {
        Bigint res;
        res.len = max(this->len, bi.len);
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
        res.len = max(this->len, bi.len);
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
        if ((this->len == 1 && this->z[1] == 0) ||
            (bi.len == 1 && bi.z[1] == 0)) {
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
char number[MAXN];
int n, len;
Bigint value[MAXN][MAXN];
Bigint f[MAXN][MAXM];
int main() {
    cin >> number + 1;
    cin >> n;
    len = strlen(number + 1);
    for (int i = 1; i <= len; i++) {
        for (int j = i; j <= len; j++) {
            for (int k = i; k <= j; k++) {
                value[i][j] =
                    value[i][j] * Bigint("10") + Bigint(number[k] - '0');
            }
        }
    }
    for (int i = 0; i <= len; i++) {
        for (int j = 0; j <= len; j++) {
            f[i][j].SetInfinite();
        }
    }
    for (int i = 1; i <= len; i++) {
        f[i][0] = value[1][i];
    }
    for (int i = 1; i <= len; i++) {                // 枚举位置
        for (int j = 1; j <= max(n, i - 1); j++) {  // 枚举要放的加号数量
            for (int k = 1; k < i; k++) {
                if (f[i][j] > f[k][j - 1] + value[k + 1][i])
                    f[i][j] = f[k][j - 1] + value[k + 1][i];
            }
        }
    }
    f[len][n].write();
    // system("pause");
}