#knapsack problem
def solution(n):
  dp = [0 for i in range(n+1)]
  dp[0] = 1
  for num in range(1, n):
    for i in range(n-num, -1, -1):
      dp[i+num] += dp[i]
  return dp[n]

print(solution(200))