# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []
        
        queue = deque()
        queue.append((root,0))
        ans = [[]]

        while queue:
            node, depth = queue.popleft()
            if depth+1 > len(ans):
                ans.append([])
            
            ans[depth].append(node.val)
            if node.left:
                queue.append((node.left, depth+1))
            
            if node.right:
                queue.append((node.right, depth+1))

        return ans