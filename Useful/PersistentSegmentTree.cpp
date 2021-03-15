#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 50;
struct Node {
    Node *ls, *rs;
    int l, r, val;
    Node(int L = 0, int R = 0, int VAL = 0, Node* LS = NULL, Node* RS = NULL)
        : ls(LS), rs(RS), l(L), r(R), val(VAL) {}
} * rot[MAXN];

void Build(Node* now, int L, int R) {
    now = new Node(L, R, 0);
    if (L == R) {
        return;
    }
    int M = (L + R) >> 1;
    Build(now->ls, L, M);
    Build(now->rs, M + 1, R);
}

void Insert(Node* now, Node* base, int x, int val) {
    now = new Node();
    *now = *base;
    if (now->l == now->r) {
        now->val = val;
        return;
    }
}

int n, m;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        void* s = malloc((size_t)10);
    }
}