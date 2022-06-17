N = int(input())
max_num = N + 1
all_num_list = [0] * (max_num + 1)
primeList = []


def mark(start, end, num):
    for i in range(start, end, num):
        all_num_list[i] = 1


def generatePrimes():
    for i in range(2, max_num):
        if all_num_list[i] == 0:
            primeList.append(i)
            mark(i * 2, max_num + 1, i)


generatePrimes()
ans = N
j = 0
while primeList[j] <= N:
    if N % primeList[j] == 0:
        ans //= primeList[j]
        ans *= primeList[j] - 1
    j += 1
    if j == len(primeList):
        break
print(ans)
