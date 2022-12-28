def selectionSort(arr):
    n = len(arr)

    for i in range(0, n):
        min_idx = i

        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        
        arr[min_idx], arr[i] = arr[i], arr[min_idx]

arr = [19,2,31,45,30,11,121,27]
selectionSort(arr)
print(arr)