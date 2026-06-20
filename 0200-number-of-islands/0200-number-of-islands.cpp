class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // 섬 개수 반환. 섬은 1로만 이루어져있고, 상하좌우가 0이면됌.

    //2D grid + BFS/DFS
        int dx[] = {-1, 1, 0, 0}; // 상 하 좌 우 dx는 좌우가 당연히 변화 x  
        int dy[] = {0, 0, -1, 1}; // y축 기준 상 하 좌 우
        int n = grid.size(), m = grid[0].size(); 
        vector<vector<int>> visited(n, vector<int>(m, 0));
    // 여기서 visited() 괄호 안에 n, vector<int>(m, 0)이거는 생성자,
    // 생성할때부터 디폴트 생성자 정의
    // vector<int>(m, 0)은 0으로 채운 m개의벡터를 생성. 그거를 n개 만들어라
        queue<pair<int, int>> q; // 튜플 저장하는 큐 생성
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                // grid가 char이기 때문에 '1'
                    q.push({i, j});
                    visited[i][j] = 1;

                    while (!q.empty()) { // c++의 queue.pop()은 제거만하지 반환을 안해
        // 그래서 먼저 front넣어주고 나서 pop해야돼.
                        auto[cx, cy] = q.front();
                        q.pop();

                        for (int direction = 0; direction < 4; direction++) {
                //사방향
                            int nx = cx + dx[direction], ny = cy + dy[direction];

                //범위체크 -> 판떼기를 벗어나면 수행안하기 = continue
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '0') continue;
                            if (visited[nx][ny]) continue; // 1이면 수행안하기

                            visited[nx][ny] = 1;
                            q.push({nx, ny});
                        }   
                    }
                    count += 1;
                }
            }
        }
        return count;
    }
    
};



