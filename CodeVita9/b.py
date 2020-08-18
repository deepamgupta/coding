from itertools import permutations

n = int(input())

speeds = [int(num) for num in input().strip().split()]

if n==0:
    print('{:.6f}'.format(0))
elif n==1:
    print('{:.6f}'.format(1))
else:
    perm = list(permutations(speeds))
    
    perm = [list(t) for t in perm]
    
    groups = 0
    
    for p in perm:
        prevs = p[0]
        
        for i in range(1, len(p)):
            if p[i] >= prevs:
                p[i] = prevs
            
            prevs = p[i]
            

        
        groups += len(set(p))
        
        gc.collect()
        
    
    print('{:.6f}'.format(groups/len(perm)))            
    
    
