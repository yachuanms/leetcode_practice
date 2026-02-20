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
    def reorderList(self, head):
        if not head or not head.next:
            return
        
        #找中間 用快慢指針
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        #斷開前後段
        second = slow.next
        slow.next = None

        #反轉
        prev = None
        while second:
            nxt = second.next
            second.next = prev
            prev = second
            second = nxt
        
        #merge
        first = head
        second = prev
        while second:
            tmp1 = first.next
            tmp2 = second.next

            first.next = second
            second.next = tmp1

            first = tmp1
            second = tmp2
            
        return head
        
            


        


def run_test(arr, expected):
    head = build_linked_list(arr)
    Solution().reorderList(head)
    got = linked_list_to_list(head)
    print(f"in : {arr}")
    print(f"out: {got}  expected: {expected}  --> {'PASS' if got == expected else 'FAIL'}")
    if got != expected:
        raise AssertionError("Test failed")


if __name__ == "__main__":
    run_test([1,2,3,4], [1,4,2,3])
    run_test([1,2,3,4,5], [1,5,2,4,3])
    run_test([1,2], [1,2])
    run_test([1], [1])
    print("All tests passed!")
