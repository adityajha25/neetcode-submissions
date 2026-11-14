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
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, INT_MIN, INT_MAX);
    }

    bool isValidBSTHelper(TreeNode* root, int low, int high) {
        if (root != 0) {
            if (root->val <= low || root->val >= high) {
                return false;
            } else {
                return root->val > low && root->val < high && isValidBSTHelper(root->left, low, root->val) && isValidBSTHelper(root->right, root->val, high);
            }
            
        } else {
            return true;
        }
    }
};
