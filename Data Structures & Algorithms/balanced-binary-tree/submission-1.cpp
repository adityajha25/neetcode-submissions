/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return helper(root) != -1;
    }

    int helper(TreeNode* subRoot) {
        if (subRoot == 0) {
            return 0;
        } else {
            int left = helper(subRoot->left);
            int right = helper(subRoot->right);
            if (left-right >=2 || left-right <=-2 || left==-1 || right == -1) {
                return -1;
            } else {
                return std::max(left,right)+1;
            }
        }
    }
};
