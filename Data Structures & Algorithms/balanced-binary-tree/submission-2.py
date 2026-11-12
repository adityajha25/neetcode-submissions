# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.helper(root)!=-1
    

    def helper(self, root) -> bool:
        if root is None:
            return 0
        else:
            left = self.helper(root.left)
            right = self.helper(root.right)

            if (left-right >=2 or left-right <= -2 or left == -1 or right == -1):
                return -1
            else:
                return max(left,right)+1

        