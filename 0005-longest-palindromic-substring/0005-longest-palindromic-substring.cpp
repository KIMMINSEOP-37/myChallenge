class Solution { // 방향은 맞는데, for문으로 모든 인덱스를 중심으로했을때의 팰린드롬을 찾아야해.
public:
    string longestPalindrome(string s) {
        // s안에서 앞뒤가 똑같이 끝나는 문자열을 반환하라 이거.
        // 짝수면 선대칭, 홀수면 가운데 기준 선대칭 kayak
        int n = s.size();
        string res = s.substr(0,1); // 최소 한글자 res
        // 애초에 left, right를 half로 둘다 찍어두고 벌려나가야돼.
        for (int z = 0; z < n; z++) {
            // 이 전체 hlaf를 돌면서도, 짝 홀을 나눠야함.
                // 짝수
                int left = z, right = z + 1;
                while (left >= 0 && right < n && s[left] == s[right]) {
                    if (right - left + 1 > res.size()){
                    // 1보단 길이가 길때만 res에 저장
                        res = s.substr(left, right - left + 1);        
                    }   
                    left--;
                    right++;
                }

                left = z, right = z;
                while (left >= 0 && right < n && s[left] == s[right]) {
                    if (right - left + 1 > res.size()){
                    // 1보단 길이가 길때만 res에 저장
                        res = s.substr(left, right - left + 1);        
                    
                    }   
                    left--;
                    right++;
                }

        

            
        }
        return res;
    }
            
};