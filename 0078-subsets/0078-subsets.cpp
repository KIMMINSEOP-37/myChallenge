class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        // 주어진 nums에 대한 모든 부분집합 반환, 
        // res만들고,res반환. res에다가 for문으로 퐈함된거 true로 재껴가기
        vector<int> current;
        
        int start = 0;
        backT(nums, current, start);


        return res;
        
    }
    // void backT 반환타입
    void backT(vector <int>& nums, vector <int>& current, int start) {
        res.push_back(current); // 일단 매번 저장 다안차도 저장.
        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backT(nums, current, i + 1); // 여기서 깊숙히 들어가
            current.pop_back();
        }
        return;
    }
};