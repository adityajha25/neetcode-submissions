# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        dummy = TreeNode(0)
        self.helper(root, k, 0, dummy)
        return dummy.val
        
    

    def helper(self, root: TreeNode, k: int, counter: int, dummy: TreeNode) -> int:
        if counter < k and root is not None:
            counter = self.helper(root.left, k, counter, dummy)
            if counter >= k:
                return counter
            counter+=1
            if counter == k:
                dummy.val = root.val
                return counter
            counter = self.helper(root.right, k, counter, dummy)
        
        return counter
        