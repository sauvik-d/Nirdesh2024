import numpy as np
n = np.random.randint(1, 10)
arr = np.random.randint(0, 10, n)
ip = open("input.txt", "w")
op = open("output.txt", "w")

ip.write(str(n)+"\n")
for i in range(n):
    ip.write(str(arr[i])+" ")
ip.write("\n")

print(arr)

arr = set(arr)
arr.discard(0)
print(len(arr))
op.write(str(len(arr))+"\n")