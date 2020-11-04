n = int(input())
a = [0]
for i in range(1, n + 1):
    a.append(a[i - 1] * 2 + 2)
print(a[n])
