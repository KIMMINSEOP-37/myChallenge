class Solution {
public:
    vector<vector<int>> res; // 리스트 안에 리스트
    vector<vector<int>> permute(vector<int>& nums) {
        // 가능한 모든 수열을 반환
        vector<int> current;
        vector<bool> used(nums.size(), false);

        backT(nums, current, used);


        return res;
    }

    void backT(vector<int>& nums, vector<int>& current, vector<bool>& used) 
    // vector<int>& nums 즉 int형 벡터를 만드는데, 이때 nums를 참조로 받겠다.
    // 참조가 아닌 그냥 복사로 받으면 오버헤드 커져
    { // 현재까지 선택한 것을 들고다니기
        if (current.size() == nums.size()){
            res.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) {
                continue;
            }
            current.push_back(nums[i]); // 선택
            used[i] = true; 
            backT(nums, current, used); // 재귀
            current.pop_back(); // 선택취소 == 이게 back
            used[i] = false;
        }
    }
};