#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct Node {
    Node *ls, *rs;
    int key, dist;
    Node() : ls(NULL), rs(NULL), key(0), dist(0) {}
    Node(int k) : ls(NULL), rs(NULL), key(k), dist(0) {}
};

Node* Merge(Node* A, Node* B) {
    if (A == NULL) return B;
    if (B == NULL) return A;
    if (B->key < A->key) {
        Node* temp = A;
        A = B;
        B = temp;
    }
    A->rs = Merge(A->rs, B);
    if (A->rs->dist > A->ls->dist) {
        Node* temp = A->ls;
        A->ls = A->rs;
        A->rs = temp;
    }
    if (A->rs == NULL)
        A->dist = 0;
    else
        A->dist = A->rs->dist + 1;
    return A;
}

Node* Insert(Node* A, int X) { return Merge(A, new Node(X)); }

Node* DelMin(Node* A) {
    Node* Ret = Merge(A->ls, A->rs);
    delete A;
    return Ret;
}
int GetMin(Node* A) { return A->key; }

int main() {
    Node *X = new Node(), *Y = new Node();
    Insert(X, 1);
    Insert(X, 5);
    Insert(X, 4);
    Insert(X, 8);
    printf("%d\n", GetMin(X));
    X = DelMin(X);
    printf("%d\n", GetMin(X));
    system("pause");
}