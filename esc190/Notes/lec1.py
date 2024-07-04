# deep copies of lists
L = [[[[1, 2]], 5], 2]
L2 = L[:]  # shallow copy means they are separate lists, but their elements are aliases

# changing L[0][0] changes L2[0][0] to 3 as well

# a way to deep copy is to manually copy the elements of a list by hand, but this involves knowing the list in advanced
# more comprehensively, we want it to be recursive in a way that deepcopies every element of a list

def deepcopy(L):
    '''return a deepcopy of L'''
    res = []
    if type(L) != list:
        return L

    for e in L:
        if type(e) ==list:
            res.append(deepcopy(e))
        else:
            res.append(e)
    return res

# want a list of all strings of length k over the alphabet
alphabet = "abcdefghijklmnopqrstuvwxyz"
for letter1 in alphabet:
    for letter2 in alphabet:
        for letter3 in alphabet:
            for letter4 in alphabet:
                print(letter1 + letter2 + letter3 + letter4)
# this would be the 4 letter version, want k letters

def all_strings(k, alphabet):
    '''Return a list of all strings of length k over the alphabet'''
    if k == 0:
        return [""]

    res = []
    for letter in alphabet:
        all_k1_strings = all_strings(k-1, alphabet)
        for string in all_k1_strings:
            res.append(letter + string)
    return res

'''what is the call tree/complexity?
suppose len(alphabet) = n
                    ...
                    |
                    k-2           n * (number of strings of length k-3) = n * n^(k-3) = n^(k-2)
                    |
                    k-1           n * (number of strings of length k-2) = n * n^(k-2) = n^(k-1)
                    |
                    k             n * (number of strings of length k-1) = n * n^(k-1) = n^k

                    n^k + n^(k-1) ... + n + 1 = (n^(k+1)-1)/(n-1) = O(n^k) assuming k is constant
'''


def test(n: int) -> str:
    if n == 0:
        return "hello"
    return "stfu"

print(test(0))
