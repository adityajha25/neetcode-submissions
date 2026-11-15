# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        start = ListNode(0, head)
        first=start
        second=start

        for i in range(0, n+1):
            second=second.next

        while second is not None:
            first = first.next
            second = second.next
        
        first.next = first.next.next
        return start.next