from typing import Optional, List

class ListNode:
    def __init__(self, val: int = 0, next: Optional["ListNode"] = None):
        self.val = val
        self.next = next

def build_linked_list(arr: List[int]) -> Optional[ListNode]:
    dummy = ListNode(0)
    cur = dummy
    for x in arr:
        cur.next = ListNode(x)
        cur = cur.next
    return dummy.next

def linked_list_to_list(head: Optional[ListNode]) -> List[int]:
    out = []
    cur = head
    while cur:
        out.append(cur.val)
        cur = cur.next
    return out

class Solution:
    def reverseList(self, head):
        cur = head
        prev = None

        while cur:
            nxt = cur.next
            cur.next = prev
            prev = cur
            cur = nxt

        return prev

def run_test(arr: List[int], expected: List[int]):
    head = build_linked_list(arr)
    ans = Solution().reverseList(head)
    got = linked_list_to_list(ans)
    print(f"in : {arr}")
    print(f"out: {got}  expected: {expected}  --> {'PASS' if got == expected else 'FAIL'}")
    if got != expected:
        raise AssertionError("Test failed")

if __name__ == "__main__":
    run_test([1,2,3,4,5], [5,4,3,2,1])
    run_test([1,2], [2,1])
    run_test([], [])
    run_test([7], [7])
    print("All tests passed!")
