from collections import deque
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        # 오른쪽 끝라인을 반환. 즉 while right하면 될듯
        queue = deque([root])
        if not root :
            return []
        result = []
        while queue :
            level = []
            for _ in range(len(queue)) : # 일단 레벨별로 체크
                node = queue.popleft()
                level.append(node.val)
                if node.left :
                    queue.append(node.left) # queue에 올리는 이유는 자식은 큐에 넣어야 다음 레벨에서 pop해서 쓸수있어
                if node.right :
                    queue.append(node.right)
            result.append(level[-1])
        return result