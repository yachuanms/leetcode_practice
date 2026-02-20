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
    def mergeTwoLists(self, list1, list2):
        dummy = ListNode(0)
        tail = dummy

        while list1 and list2:
            if list1.val <= list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next

        if list1:
            tail.next = list1
        
        if list2:
            tail.next = list2


        return dummy.next
        


def run_test(a, b, expected):
    l1 = build_linked_list(a)
    l2 = build_linked_list(b)
    ans = Solution().mergeTwoLists(l1, l2)
    got = linked_list_to_list(ans)
    print(f"list1={a}, list2={b}")
    print(f"  got={got}, expected={expected}  --> {'PASS' if got == expected else 'FAIL'}")
    if got != expected:
        raise AssertionError("Test failed")


if __name__ == "__main__":
    run_test([1,2,4], [1,3,4], [1,1,2,3,4,4])
    run_test([], [], [])
    run_test([], [0], [0])
    run_test([5], [], [5])
    run_test([1,1,1], [1,1], [1,1,1,1,1])
    run_test([-3,-1,2], [-2,0,3], [-3,-2,-1,0,2,3])
    print("All tests passed!")
