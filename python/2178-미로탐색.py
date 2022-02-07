import sys

height, width = map(int, sys.stdin.readline().split())
mapp = [[0 for _ in range(width)] for __ in range(height)]

for i in range(height):
  inp = sys.stdin.readline()
  for j in range(width):
    mapp[i][j] = int(inp[j])

#todo USE BFS (NOT recursive(DFS))

qA = [[0,0]]
qB = []
q = [qA, qB]
qi = 0
l = 1
for xy in q[qi]:
  x = xy[0]
  y = xy[1]
  if(x == width-1 and y == height-1):
    print(l)
    break
  if(x < width-1 and q.count([x+1,y])==0):
    q.append([x+1,y])
  if(x > 0 and q.count([x-1,y])==0):
    q.append([x-1,y])
  if(y < height-1 and q.count([x,y+1])==0):
    q.append([x,y+1])
  if(y > 0 and q.count([x,y-1])==0):
    q.append([x,y-1])
  
  
