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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode head = ListNode();
        merge(list1, list2, &head);
        return head.next;
    }

    void merge(ListNode* list1, ListNode* list2, ListNode* head) {
        if (list1 == 0) {
            head->next= list2;
        } else if (list2 == 0) {
            head->next= list1;
        } else{
            if (list1->val < list2->val) {
                head->next = list1;
                merge(list1->next, list2, list1);
            } else {
                head->next = list2;
                merge(list1, list2->next, list2);
            }
        }
    }
};
