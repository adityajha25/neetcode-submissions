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
    TreeNode* invertTree(TreeNode* root) {
        invertTreeHelper(root);
        return root;
    }

    void invertTreeHelper(TreeNode* subtreeRoot) {
        if (subtreeRoot != 0) {
            TreeNode* temp = subtreeRoot->left;
            subtreeRoot->left = subtreeRoot->right;
            subtreeRoot->right = temp;
            invertTreeHelper(subtreeRoot->right);
            invertTreeHelper(subtreeRoot->left);
        }
        
    }
};
