# n = int(input())
s = input()
maxGap = 0
n = len(s)
start = s.find('#')
i = (start+1) % n
while i != start:
    count = 0
    if s[i] == '_':
        while i != start and s[i] == '_':
            count += 1
            i = (i+1) % n
        maxGap = max(maxGap, count)
    else:
        i = (i+1) % n

print(maxGap)
