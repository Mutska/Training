n = 1
m = 10
ok = False
res = 0


def backtrack(number, iteracion):
  global n, m, ok, res
  if ok: return
  if iteracion == m + 1:
    ok = True
    res = number
    return

  
  for i in range(10):
    if len(number) >= n:
      integer = int(number)
      if integer % iteracion == 0:
        if iteracion == m : 
          backtrack(number, iteracion +1)
        else : 
          backtrack(number + str(i) , iteracion + 1)
    else:
      backtrack(number + str(i) , iteracion + 1)




t = 0

for i in range(1, 30):
  for j in range(1, 30):
    if i < j:
      t += 1
      print(f"{i} {j}")
    #if i < j: 
      #ok = False
      #n = i
      #m = j
      #for k in range(1, 10):
        #backtrack(str(k), 1)
        #if ok: break
      #if not ok:
        #res = -1
      #print("Case " + str(k+1) + ": {}".format(res))
print(t)