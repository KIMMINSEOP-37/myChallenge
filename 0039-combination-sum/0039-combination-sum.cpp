class Solution {
public:
    vector<vector<int>> res;
    int target;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // res 만들고 sum을 target으로 만드는거야. 원소 중복해서
        // 사용해도되고(backT(nums, current, res, i)), target을 만들면
        // res.push_back(current)
        vector<int> current;
        int start = 0;
        int sum = 0;
        backT(candidates, current, sum, start, target);

        return res;
    }
    void backT(vector<int>& candidates,
                                    vector<int>& current, int sum, int start, int target) {
        if (sum == target) {
            res.push_back(current);
            return;
        }
        if (sum > target) return; // target보다 크면 return
        for (int i = start; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            backT(candidates, current, sum + candidates[i], i, target);
            // sum + candidates[i]는 더한값을 가지고 넘어가는거야, 그래야 다음단계를 체크하지
            current.pop_back();
        }
    }
};