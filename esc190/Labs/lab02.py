# q4
def binary_search_deluxe(L, n):
    '''mid = len(L)//2
    start = 0
    end = len(L) - 1
    a = None
    b = None
    while a != n and b != n:
        if L[mid] == n:
            a = n
            b = n
        elif L[mid] < n:
            end = mid
            mid = (end - start)//2
        else:
            start = mid
            mid = (end - start)//2'''
    
    a = binary_search_deluxe_left(L, n)
    b = binary_search_deluxe_right(L, n)

    return (a, b)


def binary_search_deluxe_left(L, target):
    left = 0
    right = len(L) - 1
    while left <= right:
        mid = (left + right) // 2
        if L[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return left

def binary_search_deluxe_right(L, target):
    left = 0
    right = len(L) - 1
    while right >= left:
        mid = (left + right) // 2
        if L[mid] > target:
            right = mid - 1
        else:
            left = mid + 1
    return right



print(binary_search_deluxe([1, 2, 3, 10, 10, 10, 12, 12], 12))
print("hello")