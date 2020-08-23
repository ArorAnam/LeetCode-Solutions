'''
Problem Statement -

Given -
def rand(k):
    => that generates perfectly random numbers between 1 and k (inclusive),

Write a function that shuffles an array of distinct numbers uniformly
=> using only swap operations
=> T: O(n)
=> All permutations should be equally likely
'''

from random import randint

def shuffle(arr):
    n = len(arr)
    for i in range(0, n):
        j = randint(0, n-1)
        arr[i], arr[j] = arr[j], arr[i]


    return arr


res = {}
for _ in range(1000):
    arr = [1, 2, 3]
    new_arr = shuffle(arr)
    keys = str(new_arr)
    res.setdefault(keys, 0)
    res[keys] += 1

print(res)
