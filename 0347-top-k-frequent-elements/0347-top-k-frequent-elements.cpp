class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 빈도수 높은 숫자 k개를 리턴 > maxheap 정렬해서, k개 팝팝팝
        unordered_map<int, int> freq;  // 숫자 → 빈도수
        for (int x : nums) {
            freq[x]++;
        }
        
        priority_queue<pair<int, int>> maxHeap;
        // pair는 p로 접근 first 정수 3 1개 {3 : 1}

        for (auto&p : freq) { // freq의 주소 인덱스를 가지고, maxHeap에 넣는거야 second가 nums, first가 빈도수
            maxHeap.push({p.second, p.first});
        }
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(maxHeap.top().second); // 숫자만 꺼내기
            maxHeap.pop();
        }
        return res;     
    }
};