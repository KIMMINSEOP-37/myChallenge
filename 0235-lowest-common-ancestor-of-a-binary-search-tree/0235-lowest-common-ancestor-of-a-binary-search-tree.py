# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
            # 위에 def받으면서 이미 tree만들어져서 들어옴.
            while root :
                if root.val > p.val and root.val > q.val :
                    root = root.left # 왼쪽으로 가기
                elif root.val < p.val and root.val < q.val:
                    root = root.right  # 오른쪽으로
                else :
                    return root