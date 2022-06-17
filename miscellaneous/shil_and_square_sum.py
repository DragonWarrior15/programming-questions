from sys import stdin

N, K = list(map(int, stdin.readline().split(" ")))
A = list(map(int, stdin.readline().split(" ")))
res = [0] * (N - K + 1)
mod = (10**9) + 7
square_list = [j**2 for j in range(K + 1)]
for i in range(0, N - K + 1):
    res[i] = sum([square_list[j] * A[i + j - 1] for j in range(1, K + 1)]) % mod
print(" ".join(list(map(str, res))))
