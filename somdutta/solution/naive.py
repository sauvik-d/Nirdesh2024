def nCr(n, r):

    return (fact(n) / (fact(r) * fact(n - r)))

# Returns factorial of n
def fact(n):
    if n == 0 or n==1:
        return 1
    res = 1
    
    for i in range(2, n+1):
        res = res * i
        
    return res

t = int(input())
while t > 0:
    user_input = input()

# Split the input string into two parts
    x, y = map(int, user_input.split())
    sum = 0
    for i in range(x+1):
        sum += pow(y, x-i)*nCr(x, i)
    print(int(sum))
    t = t - 1