class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 이전에거 기억을 해야되니까, dp
        // amount = 11이면 dp[11] = dp[6] + 1 = dp[1] + 2 = 3        
        vector <int> dp(amount + 1, amount + 1); // 일단 가능한 젤 큰수로, 뭔지 모르니까
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {  // 모든 동전 다 시도!
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        // dp는 dp[i]가 뭘 의미하는지 한글로 써보기
        // dp[i]는 target을 만드는 최소 coin의 갯수
        // dp[11] = 11원을 만드는 코인의 최소갯수
        // 젤 마지막 단계에서 1원을 쓰면 dp[10] + 1, 젤 마지막에 2원쓰면 dp[9] + 1,
        // 젤 마지막에 5원쓰면 dp[6] + 1 이중에서 최소값을 찾아. 계속 쭉쭊 앞으로 가는거야.
        // 
                
        return dp[amount] == amount + 1 ? -1 : dp[amount];
        // dp[amount] == 초기값이면 초기화가 안된거니까 -1 아니면 return 
    }
};