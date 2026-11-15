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
        std::queue<TreeNode*> q;
        vector<int> traversal = {};
        std::unordered_map<int, int> edges;
        q.push(root);
        edges[root->val]=0;


        while (q.size() > 0) {
            TreeNode* curr = q.front();
            traversal.push_back(curr->val);
            q.pop();
            if (curr->left != 0) {
                q.push(curr->left);
                edges[curr->left->val] = edges[curr->val] + 1;
            }
            if (curr->right != 0) {
                q.push(curr->right);
                edges[curr->right->val] = edges[curr->val] + 1;
            }
        }

        vector<int> ans={};
        for (int i=0;i<traversal.size()-1;i++) {
            if (edges[traversal[i]]==edges[traversal[i+1]]-1) {
                ans.push_back(traversal[i]);
            }
        }
        ans.push_back(traversal.back());
        return ans;
        
    }
};
