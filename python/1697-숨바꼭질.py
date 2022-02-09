import sys

N, K= map(int, sys.stdin.readline().split())

qA = []
qB = []
q = [qA, qB]

qI = 0
l = 0
end = 0
while q[0] or q[1]:
  q[qI%2] = []
  l += 1
  qI+=1

print(l)