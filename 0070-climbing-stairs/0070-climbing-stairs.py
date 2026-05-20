class Solution:
    def climbStairs(self, n: int) -> int:
        # 내가 한번에 올라갈 수 있는 칸은 1칸 or 2칸
        # n은 내가 올라가야 할 총 계단 수
        dp = [0] * (n + 1)

        dp[0] = 1
        dp[1] = 2
        for i in range(2, n + 1) :
            dp[i] = dp[i - 1] + dp[i - 2]
        return dp[n - 1]
        # n = 2) 1 + 1 : 2
        # n = 3) 1 + 1 + 1, 1 + 2, 2 + 1 : 3 
        # n = 4) 1 + 1 + 1 + 1, 1 + 1 + 2, 1 + 2 + 1, 2 + 1 + 1, 2 + 2 : 5