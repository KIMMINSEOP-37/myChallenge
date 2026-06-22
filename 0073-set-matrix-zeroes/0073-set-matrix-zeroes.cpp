class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // matrix를 search를해, 하다가 0을 만나 -> 포함된 행, 열 전부 0으로 만들어.
        int m = matrix.size(), n = matrix[0].size();
        set<int> rows, cols; // set으로 중복제거! 
        // 정렬을 하는데, 자동으로 중복 제거해줘.

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);  // 중복 행 자동 제거
                    cols.insert(j);  // 중복 열 자동 제거
                }
            }
        }
        // 위에거 돌면서 자동으로 중복 없는걸로 저장.
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rows.count(i) || cols.count(j))
                    matrix[i][j] = 0;
            }
        } // set.count는 i 가 있으면1 없음녀 0 즉 하나라도 있으면 고
    }
};