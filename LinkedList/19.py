class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def build_linked_list(arr):
    dummy = ListNode(0)
    cur = dummy
    for x in arr:
        cur.next = ListNode(x)
        cur = cur.next
    return dummy.next


def linked_list_to_list(head):
    out = []
    cur = head
    while cur:
        out.append(cur.val)
        cur = cur.next
    return out


class Solution:
    def removeNthFromEnd(self, head, n):
        dummy = ListNode(0)
        dummy.next =head
        slow = dummy
        fast = dummy

        #fast先走n+1步
        for i in range(n+1):
            fast = fast.next

        #一起走slow停在要刪除的node前
        while fast:
            slow = slow.next
            fast = fast.next
        
        slow.next = slow.next.next
        return dummy.next


def run_test(arr, n, expected):
    head = build_linked_list(arr)
    new_head = Solution().removeNthFromEnd(head, n)
    got = linked_list_to_list(new_head)
    print(f"in : {arr}, n={n}")
    print(f"out: {got}, expected={expected}  --> {'PASS' if got == expected else 'FAIL'}")
    if got != expected:
        raise AssertionError("Test failed")


if __name__ == "__main__":
    run_test([1,2,3,4,5], 2, [1,2,3,5])
    run_test([1], 1, [])
    run_test([1,2], 2, [2])
    run_test([1,2], 1, [1])
    print("All tests passed!")