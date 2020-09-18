def ArrayChallenge(strArr):
    n1 = strArr[1]
    n2 = strArr[2]

    if n1 == n2:
        return n1

    heap = strArr[0]
    heap = heap.replace('[', '')
    heap = heap.replace(']', '')
    heap = heap.split(', ')
    heap = ['0'] + heap

    i = heap.index(n1)
    temp = []
    while i > 0:
        temp.append(heap[i])
        i = i // 2

    i = heap.index(n2)

    while i > 0:
        if heap[i] in temp:
            return heap[i]
        i = i//2


inp = ["[12, 5, 9, 6, 2, 0, 8, #, #, 7, 4, #, #, #, #]", "9", "9"]

print(arrChallenge(inp, 0))