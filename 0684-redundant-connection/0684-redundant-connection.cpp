class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        parent[rootA] = rootB;
    }


    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // 원래 tree였는데, 여기다가 edge를 딱하나 추가하니까, cycle이 됐다. 이 두개의 V를 출력
        // 유니온 파인드로 찾기
        parent.resize(edges.size() + 1); // 초기화
        for (int i = 0; i <= edges.size(); i++) {
            parent[i] = i; // 자기자신 초기화
        }
        
        for (auto x : edges) {
            if (find(x[0]) != find(x[1])){
                unite(x[0], x[1]);
            }
            else {
                return {x[0], x[1]};
            }
        }
        return {}; // 문제 조건상 사이클 존재 실제로는 여기로 오지 않지만,
        // 컴파일러는 모든 경로에 return이 있어야 안전하다고 생각.
    }
};