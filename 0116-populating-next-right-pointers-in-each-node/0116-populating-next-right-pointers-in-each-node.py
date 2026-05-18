from collections import deque
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        # full 이진트리를 레벨별로 리스트를 끊어 주는거야.
        
        if not root :
            return None # Optional[Node]  # Node 객체 or None
        queue = deque([root])
        while queue :
            level = []
            for i in range(len(queue)) : # 1을 빼는 이유는 마지막은 바로 next -> none, 1단계 : 먼저 level채우기
                node = queue.popleft()
                level.append(node) # node라고 하면 객체 그자체. (val, left, right, next 다 가지고 있음)
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)
            for i in range(len(level) - 1) : # 위에서 level을 다 채우고 연결
                level[i].next = level[i + 1]
        return root # root자체가 트리전체에 접근하는 객체임