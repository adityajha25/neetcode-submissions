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
    int diameter=0;
    int diameterOfBinaryTree(TreeNode* root) {
        auto x = helper(root);
        return diameter;
    }

    int helper(TreeNode* root) {
        if (root != 0) {
            auto left = helper(root->left);
            auto right = helper(root->right);
            diameter = std::max(left+right, diameter);
            return std::max(left,right)+1;
        } else {
            return 0;
        }
    }
};
