n = int(input())
while n != 0:
    s = input()
    st = set(s)
    print("Yes" if len(st) == 26 else "No")
    n-=1
