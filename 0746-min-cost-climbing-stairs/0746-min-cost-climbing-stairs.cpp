class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 1 or 2 step, start 0 or 1 index
        // return reach the top cost
        
        // dp[i] = i번째 도착하는 최소 비용
        // 이전에 거를 끌어와 i = i-1 i-2 최대 2칸가니까
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        // 벡터 생성자. n + 1은 크기, 0은 초기값.
        
        for (int i = 2; i <= cost.size(); i++) {
            dp[i] = min(dp[i - 1] + cost[i -1], dp[i - 2] + cost[i - 2]);
        }
        

        return dp[n];
        
    }
};