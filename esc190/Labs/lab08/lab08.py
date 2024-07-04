# q2a
# OPT(n) = min(OPT(1) + OPT(n-1), OPT(2) + OPT(n-2), ..., OPT(n-1) + OPT(1))

#q2b
import numpy as np
def compute_opt(coins, target):
    optlist = [np.inf] * (target + 1)
    optlist[0] = 0
    for i in range(1, target + 1):
        optlist[i] = min(1 + optlist[i-c] for c in coins if i-c >= 0)
    return optlist

#q2c

def opt(coins, target): # result is a list
    if target == 0:
        return []

    return [least_coin(coins, target)] + opt(coins, target - least_coin(coins, target))

def least_coin(coins, target):
    if target == 0:
        return None
    
    optlist = compute_opt(coins, target)
    temp = [np.inf] * len(coins) # stores the amount of coins needed if went with coin c

    for i in range(len(temp)):
        if coins[i] <= target:
            temp[i] = optlist[coins[i]] + optlist[target - coins[i]]

    index = 0
    for j in range(len(coins)):
        if temp[j] == min(k for k in temp):
            index = j
    return coins[index]




if __name__ == '__main__':
    coins = [1, 5, 10]
    optlist = compute_opt(coins, 6)
    for i in range(len(optlist)):
        print(optlist[i])
    
    print("break")
    coins2 = [1, 4, 5]
    list = opt(coins2, 8)
    for i in range(len(list)):
        print(list[i])


