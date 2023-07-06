from sys import stdin, setrecursionlimit
setrecursionlimit(10**7)

def calculateMinPatforms(at, dt, n):
    at.sort()
    dt.sort()
    i = j = cnt = 0
    res = 1
    while i < n:
        if at[i] <= dt[j]:
            cnt+=1
            i += 1
        else:
            cnt -= 1
            j += 1
        res = max(res, cnt)
    return res
# Taking the input.
def takeInput():
    n = int(stdin.readline().strip())
    at = list(map(int, stdin.readline().strip().split(" ")))
    dt = list(map(int, stdin.readline().strip().split(" ")))

    return at, dt, n

# Main.
T = int(input())
while (T > 0):
    T -= 1
    at, dt, n = takeInput()
    minNumOfPlatforms = calculateMinPatforms(at, dt, n)
    print(minNumOfPlatforms)
