from itertools import combinations

def solution(l):
    # Your code here
    n = len(l)
    l.sort(reverse = True)
    for i in reversed(range(1, n+1)):
        for nums in combinations(l,i):
            if sum(nums) % 3 == 0:
                return int(''.join(map(str,nums)))
    return 0

print(solution([3, 1, 4, 1]))