
def getTotalRewards(n, arr):
    # Write your code here.
    if n == 1 : return 1
    arr = list(set(arr))
    a = min(arr)
    if a == 0:
      a = min(arr[1:])
    b = max(arr)
    return b-a+1
    


print(getTotalRewards(3, [2,3,3]))


