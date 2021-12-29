import sys

def pickWeighs(r, n, w):
  if(r==n):
    if(w>=0):
      dp[w]='Y'
    return
  if(w+(n-r)*500<0):
    return
  pickWeighs(r+1, n, w)
  pickWeighs(r+1, n, w+ws[r])
  pickWeighs(r+1, n, w-ws[r])

nW = int(sys.stdin.readline())
ws = list(map(int, sys.stdin.readline().split()))
nBead = int(sys.stdin.readline())
beadWs = list(map(int, sys.stdin.readline().split()))

plateW = 0

dp = ['N' for _ in range(40001)]
pickWeighs(0, nW, 0)

for b in beadWs:
  print(dp[b], end=' ')
print()