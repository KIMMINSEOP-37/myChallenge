class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // top left -> bottom right.
        // min cost sum, 오직 down or right
        int m = grid.size(), n = grid[0].size();
        
        // 일단 다 기본값 0로 초기화 후, grid값 대입
        // 어차피 0행, 0열은 직진만 가능 최단거리
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j - 1];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};