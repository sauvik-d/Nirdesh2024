import random

test = random.randint(1, 10)
print("No. of tests are: "+str(test))
ip = open("input.txt", "w")
op = open("output.txt", "w")
ip.write(str(test)+'\n')

def threat(arr, n, element, i, j):
    if i == 0 or j == 0 or i == n-1 or j == n-1:
        return False
    # for checking total depths
    '''
    for a in range(j):
        left += arr[i][a]
    for b in range(j+1, n):
        right += arr[i][b]
    for c in range(i):
        up += arr[c][j]
    for d in range(i+1, n):
        down += arr[d][j]
    '''
    # for checking depths of only adjacent elements
    left = arr[i][j-1]
    right = arr[i][j+1]
    up = arr[i-1][j]
    down = arr[i+1][j]
    fmt = "Depths for arr[{0}][{1}] are"
    if left <= element and right <= element and up <= element and down <= element:
        # print(fmt.format(i, j))
        # print(left, right, up, down)
        return True
    else:
        return False

def func(n):
    arr = []
    for i in range(n):
        col = []
        for j in range(n):
            col.append(random.randint(1, 100000))
        arr.append(col)
    for i in range(n):
        for j in range(n):
            ip.write(str(arr[i][j])+" ")
        ip.write("\n")
    ip.write("\n")
    replaceCavity(n, arr)
    # print("After removing cavity: ")
    # for i in range(n):
        # print(arr[i])

'''
def cavity(n, arr):
    
    replaceCavity(mx, n, arr)
'''
def replaceCavity(n, arr):
    cavityflag = 1
    rounds = 1
    totalcavity = 0
    while cavityflag != 0:
        mx = -1
        for i in range(n):
            for j in range(n):
                mx = max(mx, arr[i][j])
        # print("Max for round " + str(rounds) +" is: "+str(mx))
        # fmt2 = "After Round {0} Cavity Check"
        # print(fmt2.format(rounds))
        rounds += 1
        flag = 0
        for i in range(n):
            for j in range(n):
                if arr[i][j] == mx:
                    if threat(arr, n, arr[i][j], i, j) == True:
                        flag = 1
                        arr[i][j] = 0
                        totalcavity += 1
        if flag == 0:
            cavityflag = 0
    print("The total rounds are: " + str(rounds-1))
    print("Total no. of Cavity removed is: " + str(totalcavity))

for i in range(test):
    print("Result at Test "+str(i+1)+":")
    n = random.randint(50, 100)
    # n = 100
    # print(rounds)
    ip.write(str(n)+'\n')
    func(n)