class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 가장 긴 배열을 갖는 오름차순
        int n = nums.size();
        vector <int> dp(n, 1);


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // dp는 초기화 개념,
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    // 하나의 i에 대한 여러개의 j이기에, max
                } 
            }
            // dp는 초기화 개념, 
        }
        
        return *max_element(dp.begin(), dp.end());
        //  범위 내에서 최대의 (값 *)
        
    }
};