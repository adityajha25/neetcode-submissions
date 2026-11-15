/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return helper(head, n).first;
    }

    std::pair<ListNode*, int> helper(ListNode* node, int n) {
        if (node == 0) {
            return {node,0};
        } else {
            auto res = helper(node->next, n);
            node->next = res.first;
            if (res.second == n-1) {
                return {node->next, n+1};
            } else {
                return {node, res.second+1};
            }
            
        }
    }
};
