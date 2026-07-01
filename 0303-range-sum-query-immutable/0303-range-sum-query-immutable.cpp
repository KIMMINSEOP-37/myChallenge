class NumArray {
public:
    vector<int> prefix; // 멤버변수

    NumArray(vector<int>& nums) { // 클래스 이름과 동일 = 생성자
    // 생성자니까 객체만들면서 prefix만드는거지
        // sumRange가 2,5이면 인덱스2~5 누적합
        // 누적합은 그떄그때하기보단, 일단 nums를 누적합 prefix로 새배열
        int n = nums.size();
        prefix.resize(n + 1, 0);    
        
        // 일단 prefix는 쓰던 말던 다만들어놓는거야
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
            // 누적합. 이전 누적에다가 nums값 더하기.
            // [1, 2, 3]
            // pref = [null, 1, 3, 6]
        }
    }
    
    int sumRange(int left, int right) {// 멤버함수 : 호출될때마다, 
    // 즉 예시를 보면 numArray.sumRange이렇게 호출중이야.
        
        return prefix[right + 1] - prefix[left];  // 항상 이거 하나면 됨!
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */