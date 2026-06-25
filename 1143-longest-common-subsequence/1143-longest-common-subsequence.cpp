class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //두개의 문자열 input, 1문자열에 포함된 2텍스트의 길이
        // 공통으로 존재하는 가장 긴 부분 수열의 길이.
        int m = text1.size(), n = text2.size();
        vector <vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        //dp는 1의 i번째, 2의 j번째까지 봤을때의 부분수열 길이
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    // dp[i + 1][j + 1] 이거는 과거 즉, i, j에 영향 + 1
                }
                else {
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
                // 같지 않으면은 둘중에 하나를 포기해서 최대 길이를 만들어야 되는데, 큰거를 선택해야지 최대길이가 되지.
            }
            
            
        }
        return dp[m][n];
    }
};