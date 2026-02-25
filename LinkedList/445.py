# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
       self.val = val
       self.next = next

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        s1 = []
        s2 = []
        cur1 = l1
        cur2 = l2
        while cur1:
            s1.append(cur1.val)
            cur1 = cur1.next
        while cur2:
            s2.append(cur2.val)
            cur2 = cur2.next
        carry = 0
        head = ListNode(carry)
        while s1 or s2 or carry:
            n1 = s1.pop() if s1 else 0
            n2 = s2.pop() if s2 else 0
            sum = n1+n2+carry
            #頭插法
            cur = ListNode(sum%10)
            head.next = cur
            cur = head
            carry = sum//10
            
            
        return head.next

        