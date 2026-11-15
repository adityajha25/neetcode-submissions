# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        queue = deque()
        queue.append((root,0))
        traversal=[]

        if not root:
            return []

        while queue:
            curr, depth = queue.popleft()
            if depth == len(traversal):
                traversal.append(curr.val)
            else:
                traversal[-1]=curr.val
            
            if curr.left:
                queue.append((curr.left, depth+1))
            if curr.right:
                queue.append((curr.right, depth+1))

        return traversal
