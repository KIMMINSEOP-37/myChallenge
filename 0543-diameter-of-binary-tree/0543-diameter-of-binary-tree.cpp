/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // 가장 긴경로 즉 왼쪽으로 쭈욱 깊이탐색 + 오른쪽으로 쭈욱 깊이 탐색
        if (root == NULL) return 0;

        int curr = dfs(root -> left) + dfs(root -> right); // 지름 탐색
        int left = diameterOfBinaryTree(root -> left);
        int right = diameterOfBinaryTree(root -> right);
        return max(curr, max(left, right));
    }
    int dfs(TreeNode* node) { // tree의 깊이를 구해
        // TreeNode자체가 타입변수야 int 같은거
        // 구조체 타입변수
        if (node == NULL) return 0;
        return 1 + max(dfs(node -> left), dfs(node -> right));
    }

};