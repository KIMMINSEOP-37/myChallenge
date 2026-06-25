class Solution {
public:
    int uniquePaths(int m, int n) {
        // 오직 down or right만 이동가능
        // return 가능한 경우의수.
        // dp[][] = dp[i - 1][j] + dp[i][j - 1]

        vector<vector<int>> dp(m, vector<int>(n, 1));
        // 2D표현dp(행, 열)
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
   }
};