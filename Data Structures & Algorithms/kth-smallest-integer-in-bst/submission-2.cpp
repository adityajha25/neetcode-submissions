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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode dummy(0);
        helper(root, k, 0, &dummy);
        return dummy.val;
    }

    int helper(TreeNode* root, int k, int counter, TreeNode* dummy) {
        if (root != 0 && counter < k) {
            counter = helper(root->left, k, counter, dummy);
            if (counter >=k) {
                return counter;
            }
            counter+=1;
            if (counter == k) {
                dummy->val = root->val;
                return counter;
            }
            counter = helper(root->right, k, counter, dummy);
        }
        return counter;
    }
};
