class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        
        // 경계를 좁혀나가자
        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        vector<int> res;

        while(top <= bottom && left <= right) {
            // 오른쪽으로
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++; // top 제외
            
            // 아래로
            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--; // right제외
            
            // 왼쪽으로 (중복방지)
            if (top <= bottom) {
               for (int i = right; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--; // bottom제외 
            }

            // 위로 (중복방지)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++; // lfet제외
            }
            
        }
    return res;
    }
};