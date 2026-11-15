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
        ListNode startx = ListNode(0, head);
        ListNode* start = &startx;
        ListNode* first=start;
        ListNode* second=start;

        for (int i=0;i<n+1;i++) {
            second = second->next;
            
        }

        while (second != 0 && first != 0) {
            second = second->next;
            first = first->next;
        }

        first->next = first->next->next;
        
        return start->next;
    }

    
};
