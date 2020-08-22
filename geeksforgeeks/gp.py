
def maxLen(n, arr):
    left = right = None
    arr.sort()
    ans = 0
    if n >= 1 and arr[0] <= 0:
        for i in range(n):
            if arr[i] == 0:
                left, right = i, i
                break
            elif arr[i] > 0:
                left, right = i-1, i
                break

        curSum = arr[left] + arr[right]

        while left >= 0 and right < n:
            if curSum == 0:
                ans = right - left + 1
                right += 1
                curSum +=  arr[right]
            elif curSum < 0:
                right += 1
                curSum += arr[right]
            else:
                left -= 1
                curSum += arr[left]

    return ans


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        print(maxLen(n, arr))
