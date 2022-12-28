def binarySearch(arr, s, e, x):
    while e >= s:
        mid = s + (e - s) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            e=mid-1
        else:
            s=mid + 1
    
    return -1


arr = [2, 3, 4, 10, 40]
x = 2
# x = 10

result = binarySearch(arr, 0, len(arr)-1, x)

if result != -1:
    print('Element is present at', result, 'Index.')
else:
    print("Element is not present in array")
