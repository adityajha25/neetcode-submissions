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
    bool hasCycle(ListNode* head) {
        ListNode* slow;
        ListNode* fast;

        if (head == 0) {
            return false;
        }

        slow = head;
        if (head->next != 0) {
            fast = head->next;
        } else{
            return false;
        }

        while (fast != 0 && slow != fast){
            slow = slow->next;
            fast = fast->next;
            if (fast != 0) {
                fast = fast->next;
            }
        }
        
        return fast == slow;

    }
};
