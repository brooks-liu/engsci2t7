# problem: least amount of coins in the denomination (the real world is 5, 10, 25, 100 cents) to make an amount
# define OPT(v) = least number of coins to make v
# say we use n cents, then OPT(v) = 1 + OPT(v - n)
# OPT(11) = 1 + min(OPT(d1), OPT(d2), ..., OPT(dn))   where d1...dn are the denominations

import numpy as np

def make_change(coins, amt):
    OPT = [np.inf] * (amt - 1)
    OPT[0] = 0
    # not complete code since this is the problem for the lab
    j = amt
    OPT[j] = min(1 + OPT[j-c] for c in coins if j-c >= 0)


'''project intro:
seam is from top to bottom (can go diagonal left/diagonal right/down)
want smallest "energy" path/seam from top to bottom



'''