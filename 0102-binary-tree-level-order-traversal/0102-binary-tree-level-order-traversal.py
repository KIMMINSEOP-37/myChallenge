from collections import deque
# Definition for a binary tree node.
class TreeNode: # 이미 이 트리노드 클래스가 트리를 만들어줌.
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        # 레벨별로 묶어서 출력
        queue = deque([root]) # queue에다가 deque 객체를 담아
        if not root:
            return []
        result = []
        
        while queue :
            level = []
            for _ in range(len(queue)) : # 층마다 끝나면 for 끝
                node = queue.popleft() # val꺼낼때 자식 탐색후 추가, 위에서 추가한 객체를 node에 담아. 메서드 가능
                level.append(node.val)
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)
                # val, left, right 순서로 queue에 어펜드
            result.append(level)    # 층마다 result에 삽입
        return result
            # 처음부터 큐에 다넣는게아니라. val넣고 꺼낼때 자식 추가
            # 그니까 큐에 층마다 들어가는거지. 1층 드가고 , 나오면서 2층 추가
