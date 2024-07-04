'''
Dynamic programming:

fibonacci numbers
recursive function is O(1.61^n) time if not optimal (ie. t3 = t2 + t1)
'''

def fib(n):
    if n in [0, 1]:
        return 1
    return fib(n-1) + fib(n-2)

# memoization:
# store the result of a dunction call every time it happens
def fibbetter(n, fibdict = {0:1, 1:1}):   # they have to pass in {0:1, 1:1}
    if n not in fibdict:
        fibdict[n] = fibbetter(n-1, fibdict) + fibbetter(n-2, fibdict)
    return fibdict[n]

# O(n) additions because every Fibonacci number

#
print(fibbetter(6, {0:1, 1:1}))


'''dynamic programming just means optimization:
solve subproblems and store solutions to those subproblems
then build up to the actual problem




'''



