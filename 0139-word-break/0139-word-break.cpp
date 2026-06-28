class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // s를 wordDict로 쪼갤수있다면 ㅇㅋ 중복 x
        int j = 0;

        vector <bool> dp(s.size() + 1, false);
        dp[0] = true; // 빈 면은 다 가능이지.
        // dp[i]는 s의 i파티션(0~ i까지) 대해서 단어를 워드딕트로 쪼갤수있냐? bool
        for (int i = 1; i <= s.size(); i++) {
            for (string p : wordDict) {
                // s.substr(i, j) 이거는 i부터 j개를 본다 이거야.
                int j = i - p.size();  // 시작 인덱스
                if (j >= 0 && dp[j] && s.substr(j, p.size()) == p){
                    dp[i] = true; // dp[4] = true, dp[8] = true
                }
            }
        }
        return dp[s.size()];
    }
};