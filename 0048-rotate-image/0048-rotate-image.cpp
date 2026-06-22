class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 전치행렬 후 역방향
        int n = matrix.size();
        

        // 전치행렬
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]); 
            }
        }
        // swap안쓰면 값이 복사되고 복사되서 이상해져
        // swap은 임시적으로 안전하게 보관

        // 역방향
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());  // ✅
        } // i번째 행의 처음부터 끝까지 뒤집어라
    
    }
};