# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        return self.isSameTreeHelper(p,q)
    
    def isSameTreeHelper(self, p: TreeNode, q: TreeNode) -> bool:
        if p is None and q is not None:
            return False
        elif p is not None and q is None:
            return False
        elif p is not None and q is not None:
            left = self.isSameTreeHelper(p.left, q.left)
            curr = p.val == q.val
            right = self.isSameTreeHelper(p.right, q.right)
            return curr and left and right
        else:
            return True