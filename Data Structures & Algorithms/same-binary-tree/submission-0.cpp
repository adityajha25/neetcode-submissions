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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSameTreeHelper(p,q);
    }

    bool isSameTreeHelper(TreeNode* p, TreeNode* q) {
        if (p == 0 && q != 0) {
            return false;
        } else if (p != 0 && q == 0) {
            return false;
        } else if (p != 0 && q != 0) {
            bool left = isSameTreeHelper(p->left, q->left);
            bool curr = p->val == q->val;
            bool right = isSameTreeHelper(p->right, q->right);
            return left && curr && right;
        } else {
            return true;
        }
    }


};
