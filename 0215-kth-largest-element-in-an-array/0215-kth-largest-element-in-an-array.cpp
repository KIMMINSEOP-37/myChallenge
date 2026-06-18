class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        // 우선순위 큐 생
        for (int x : nums) {
            // for x in nums랑 똑같아
            minHeap.push(x);
            if (minHeap.size() > k){
                minHeap.pop(); // k개 유지
            }
        }
        return minHeap.top(); // k번째 최대값 반환
    } // k개만 딱 남기는거야    
    
    
};