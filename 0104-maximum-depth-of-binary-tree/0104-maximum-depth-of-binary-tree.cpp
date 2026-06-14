
// Definition for a binary tree node.
// treeNode 이미 나와있어.

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }


        return 1 + max(maxDepth(root -> left), maxDepth(root -> right)); 
    } // root가 포인터고, 포인터root가 left에 접근
};