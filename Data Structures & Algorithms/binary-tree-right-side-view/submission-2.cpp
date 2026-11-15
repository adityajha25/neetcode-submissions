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
    vector<int> rightSideView(TreeNode* root) {
        if (root == 0) {
            return {};
        }
        std::queue<pair<TreeNode*, int>> q;
        vector<int> traversal = {};
        q.push({root,0});

        while (q.size() > 0) {
            auto curr = q.front();
            if (curr.second < traversal.size()) {
                traversal[traversal.size()-1] = curr.first->val;
            } else {
                traversal.push_back(curr.first->val);
            }
            q.pop();
            if (curr.first->left != 0) {
                q.push({curr.first->left, curr.second+1});
            }
            if (curr.first->right != 0) {
                q.push({curr.first->right, curr.second+1});
            }
        }
        return traversal;
        
    }
};
