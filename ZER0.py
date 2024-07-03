import numpy as np
ip = open("inputnew2.txt", "w")
op = open("outputnew2.txt", "w")
n = np.random.randint(1, 5)
ip.write(str(n)+"\n")
arr = []
for j in range(0, n):
    col = []
    for k in range(0, n):
        col.append(np.random.randint(-10, 10))
    arr.append(col)

for i in range(0, n):
    for j in range(0, n):
        if j != n-1:
            ip.write(str(arr[i][j])+" ")
        else:
            ip.write(str(arr[i][j]))
    if i != n - 1:
        ip.write("\n")


arr2 = []

for i in range(0, n):
    col = []
    for j in range(0, n):
        if arr[i][j] < 0:
            col.append(arr[i][j]*(-1))
        else:
            col.append(arr[i][j])
    arr2.append(col)

arr3 = np.bitwise_and(arr, arr2)
for i in range(0, n):
    for j in range(0, n):
        if j != n - 1:
            op.write(str(arr3[i][j])+" ")
        else:
            op.write(str(arr3[i][j]))
    if i != n - 1:
        op.write("\n")