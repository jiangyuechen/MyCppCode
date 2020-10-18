def doit(n, k, rev):
    if n == 0:
        return
    x = 1 << (n - 1)
    if k < x:
        print(0 ^ rev, end='')
        doit(n - 1, k, 0)
    else:
        print(1 ^ rev, end='')
        doit(n - 1, k - x, 1)


a = (input().split(' '))
N = int(a[0])
K = int(a[1])
doit(N, K, 0)
