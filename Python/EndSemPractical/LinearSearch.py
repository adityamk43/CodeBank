arr = [2,58,95,999,65,32,15,1,7,45]

n = int(input("Enter the number to be searched: "))

found=0
for x in arr:
    if (x==n):
        print("Item found at position", arr.index(x)+1)
        found=1
        break

if (found==0):
    print("Item not found in the list")