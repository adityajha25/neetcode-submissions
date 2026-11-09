# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = None
        if head != None:
            fast = head.next
        else:
            return False

        while fast != None and slow != fast:
            slow = slow.next
            fast = fast.next
            if fast != None:
                fast = fast.next
        
        if fast == slow:
            return True
        else:
            return False