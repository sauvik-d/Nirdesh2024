t = int(input())
while t > 0:
    user_input = input()

# Split the input string into two parts
    x, y = map(int, user_input.split())
    sum = int(pow(y+1, x))
    print(sum)
    t = t - 1

# use runtime 3 sec in Python3