for _ in range(int(input())):
    n = int(input())
    l = [True] * (n + 1)
    ans = 0
    for i in range(2, n + 1):
        if l[i]:
            ans += n // i
            for j in range(i * i, n + 1, i):
                l[j]  = False
    print(ans)