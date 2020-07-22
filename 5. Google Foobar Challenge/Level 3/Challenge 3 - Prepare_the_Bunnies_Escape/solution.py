def solution(map):
  cord_init = [0,0]
  cord_exit = [len(map)-1, len(map[0])-1]
  start = bfs(map, cord_init)
  end  = bfs(map, cord_exit)

  #list of all ones - wall
  ones = getOnes(map)
  
#   print start
#   print end
#   print ones
  
  min = 1000 * 1000 * 1000
  for one in ones:
    adj1 = getAdj(one, start)
    adj2 = getAdj(one, end)
    if not adj1 or not adj2:
      continue    
    sum = adj1 + adj2 + 1
    if sum < min:
      min = sum
      
  return min

def getAdj(one, map):
  l = []
  node = stringtoNode(one)
  x = node[0]
  y = node[1]
  a = nodeToString([x+1, y])
  b = nodeToString([x-1, y])
  c = nodeToString([x, y+1])
  d = nodeToString([x, y-1])

  if a in map:
    l.append(map[a])
  if b in map:
    l.append(map[b])
  if c in map:
    l.append(map[c])
  if d in map:
    l.append(map[d])
  if len(l) == 0:
      return None
  else:
    return min(l)
  
  

def getOnes(map):
  l = []
  for x in range(0,len(map)):
    for y in range(0,len(map[0])):
    #   print x
    #   print y
      if map[x][y] == 1:
        l.append(nodeToString([x, y]))
  return l

def bfs(map, first):
  
  queue = []
  dict = {}
  queue.append(first)
  dict[nodeToString(first)] = 1
  
  while len(queue) > 0:
    
    current = queue.pop(0)
    #print(current)
    
    # add valid nodes to queue
    for neighbor in getNeighbors(current, map):
      if neighbor[0] < 0 or neighbor[0] > len(map)-1 or neighbor[1] < 0 or neighbor[1] > len(map[0])-1:
        pass
      else:
        if map[neighbor[0]][neighbor[1]] == 0 and nodeToString(neighbor) not in dict:
          queue.append(neighbor)
          dict[nodeToString(neighbor)] = dict[nodeToString(current)] + 1
        else:
          pass
  return dict

def stringtoNode(s):
  a = s.split('-')
  return[int(a[0]), int(a[1])]

def nodeToString(node):
    test = str(node[0]) + '-' + str(node[1])
    return test

def getNeighbors(current, map):
  x = current[0]
  y = current[1]
  neighbors = []
  
  neighbors.append([x+1,y])
  neighbors.append([x,y+1])
  neighbors.append([x-1,y])
  neighbors.append([x,y-1])
  
  return neighbors
  
  
  


# map = [[0, 1, 1, 0], [0, 0, 0, 1], [1, 1, 0, 0], [0,0,0,1], [0,1,1,1], [0,0,0,0]]
#map = [[0, 1, 1, 0], [0, 0, 0, 1], [1, 1, 0, 0], [1, 1, 1, 0]]
# map = [[0, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 0], [0, 0, 0, 0, 0, 0], [0, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1], [0, 0, 0, 0, 0, 0]]
#print(solution(map)) 