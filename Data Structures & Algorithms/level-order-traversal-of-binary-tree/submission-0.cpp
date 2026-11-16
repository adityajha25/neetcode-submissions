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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == 0) {
            return {};
        }
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root,0});
        vector<vector<int>> ans = {};

        while (q.size()>0) {
            auto curr = q.front();
            q.pop();
            if (curr.second + 1 > ans.size()) {
                vector<int> a = {};
                ans.push_back(a);
            }
            ans[curr.second].push_back(curr.first->val);
            if (curr.first->left != 0) {
                q.push({curr.first->left, curr.second+1});
            }
            if (curr.first->right != 0) {
                q.push({curr.first->right, curr.second+1});
            }
        }
        return ans;
    }
};
