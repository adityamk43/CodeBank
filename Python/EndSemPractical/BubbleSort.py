def bubbleSort(arr):
    n = len(arr)

    for i in range(n-1, 0, -1):
        swapped = False
        for j in range(i):
            if (arr[j] > arr[j+1]):
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped=True
        
        if not swapped:
            return

def printArray(arr):
    for i in arr:
        print(i, end=" ")

arr = [19,2,31,45,6,11,121,27]
bubbleSort(arr)
# printArray(arr)
print(arr)