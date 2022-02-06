import sys

def getCost(memory, cost, i):
  if(memory <= 0):
    return cost
  if(i>=N):
    return 10001
  dp[memory] = min(getCost(memory-ms[i], cost+cs[i], i+1), getCost(memory, cost, i+1))
  return dp[memory]

N, M = map(int, sys.stdin.readline().split())
ms = list(map(int, sys.stdin.readline().split()))
cs = list(map(int, sys.stdin.readline().split()))

dp = [10001 for _ in range(10000000)] #메모리 비활성화 최소비용

print(getCost(M, 0, 0))