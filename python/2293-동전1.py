import sys
sys.setrecursionlimit(10000)
n, k = map(int, input().split())
coins = []
for _ in range(n):
  coins.append(int(sys.stdin.readline()))

# 3원을 만드는 경우의 수 = 1원을 만드는 경우의 수 + 2원을 만드는 경우의 수
# ///
