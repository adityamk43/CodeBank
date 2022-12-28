def fact(n):
    if (n<1):
        print("Factorial not Possible")
        return -1
    
    if (n==0 or n==1):
        return 1
    
    else:
        return n*fact(n-1)

n=int(input("enter a number:"))

print("factorial of",n,"is:",fact(n))
