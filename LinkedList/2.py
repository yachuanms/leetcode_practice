# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1, l2):
        # TODO: 你寫
        dummy = ListNode(0)
        cur = dummy

        carry = 0
        while l1 or l2 or carry:
            if l1: n1 = l1.val
            else: n1 =0
            if l2: n2 = l2.val
            else: n2 = 0
            sum = n1+n2+carry
            cur.next = ListNode(sum%10)
            carry = sum // 10
            l1 = l1.next if l1 else 0
            l2 = l2.next if l2 else 0
            cur = cur.next

        return dummy.next
        


# ------------------------
# Helper functions for testing
# ------------------------

def build_list(arr):
    dummy = ListNode()
    cur = dummy
    for num in arr:
        cur.next = ListNode(num)
        cur = cur.next
    return dummy.next


def print_list(node):
    result = []
    while node:
        result.append(node.val)
        node = node.next
    print(result)


# ------------------------
# Testing main
# ------------------------

if __name__ == "__main__":
    l1 = build_list([2, 4, 3, 2, 2])
    l2 = build_list([5, 6, 4])

    sol = Solution()
    result = sol.addTwoNumbers(l1, l2)

    print_list(result)   # Expected: [7, 0, 8]