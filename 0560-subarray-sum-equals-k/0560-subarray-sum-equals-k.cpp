class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        mp[0] = 1; // 해시맵, 키밸류, 누적합0이 1번 있다.
        int sum = 0, cnt = 0;

        for (int num : nums) {
            sum += num;
            if (mp.count(sum - k)) { // mp안에는 1만 있고, count는 ()이 있는지 확인
                // 있으면
                cnt += mp[sum - k]; // 밸류를 높혀주는거 
            }
            mp[sum]++;
    
        }
        return cnt;
    }
    // 해시맵 사용
    // 빈도수, 값 인덱스 매핑, 이전값 기록,중복확인
    // 모든 sum확인sum(i ~j) == prefix(j + 1) - prefix(i) == k
    // prefix(i) == prefix(j + 1) - k == sum - k
};