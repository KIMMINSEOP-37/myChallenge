class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 이 nums라는걸 어떻게 쪼개든 두개로 쪼갰을때 둘이 같으면 true.
        // 하나하나 하면은 nums가 크면 너무 복잡도 커.
        // 정수기 때문에, 전체합이 홀수면 false
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if (sum % 2 == 1) {
            return false;
        }

        // 같다는건 결국 전체 sum의 반이 target으로 두고, 집합으로 target을 만들수있는지
        int target = sum / 2;
        vector <int> dp(target + 1, false);
        dp[0] = true;
        
        // 뒤에서 부터 돌기 (중복 방지) 
        for (int num : nums) {
            for (int i = target; i >= num; i--) {
                dp[i] = dp[i] || dp[i - num];
                // dp[11] = dp[11] || dp[10] flase || false = false
                // dp[10] = dp[10] || dp[9] 쭉 false
                // dp[1] = dp[1] || dp[0] true
                // dp가 true라는건 만들수 있다 이거야 1을 만들수있다. 
                // num = 5에서 dp[6] = dp[6] || dp[1] true즉 6도 만들수있다. 1이랑 5로
            }
        }
        return dp[target]; // 위에서 for문으로 만들수있는 true를 다 만들어놨으면, 
        //아! 그러면 dp[target]도 true이면 만들수있다는거겠구나.

    }
};