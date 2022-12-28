def ReverseArray(arr):
    start = 0
    end = len(arr) - 1

    while start < end :
        arr[start],arr[end] = arr[end],arr[start]
        start = start + 1
        end = end - 1

def PrintArray(arr):
    for i in range(len(arr)):
        print(arr[i], end=" ")
        
arr = [10,20,30,40,50,60,70,80,90,100]

ReverseArray(arr)
print("The reversed array is: ")
PrintArray(arr)