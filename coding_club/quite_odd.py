n = int(input())
nums = list(map(int, input().strip().split()))
evenAtOddIndex = 0
evenAtEvenIndex = 0
for i in range(n):
    if nums[i] % 2 == 0:
        if i % 2 == 0:
            evenAtEvenIndex += 1
        else:
            evenAtOddIndex += 1

ans = []

for i in range(n):
    if i % 2 == 0:
        ans.append(evenAtOddIndex)
    else:
        ans.append(evenAtEvenIndex)

print(*ans)