def sieve(n):
    isPrime = [True] * (n+1)

    prime = []

    for i in range(2, n+1):
        
        if isPrime[i]:
            prime.append(i)

            for j in range(i*i, n+1, i):
                isPrime[j] = False;
    
    return prime



n = int(input("Enter the number till where you want to print prime numbers!!"))

prime = sieve(n)

print(prime)