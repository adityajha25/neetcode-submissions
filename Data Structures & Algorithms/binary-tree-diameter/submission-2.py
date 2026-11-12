# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    diameter=0
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.helper(root)
        return self.diameter
    def helper(self, root) -> int:
        if root is None:
            return 0
        else:
            left = self.helper(root.left)
            right = self.helper(root.right)
            height = max(left,right)+1
            self.diameter = max(left+right, self.diameter)
            return height
    