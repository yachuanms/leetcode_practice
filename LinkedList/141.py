class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def build_linked_list_with_cycle(arr, pos):
    """
    arr: list of values
    pos: the index (0-based) where the tail connects to, or -1 for no cycle
    return: head of linked list
    """
    if not arr:
        return None

    nodes = [ListNode(x) for x in arr]
    for i in range(len(nodes) - 1):
        nodes[i].next = nodes[i + 1]

    if pos != -1:
        nodes[-1].next = nodes[pos]

    return nodes[0]


class Solution:
    def hasCycle(self, head):
        # TODO: 你寫這裡
        if not head or not head.next:
            return False
        
        slow = head
        fast = head
        #如果有環：fast 終究會追上 slow（在環裡相遇）
        #如果沒環：fast 會先走到 None
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False



def run_test(arr, pos, expected):
    head = build_linked_list_with_cycle(arr, pos)
    ans = Solution().hasCycle(head)
    print(f"arr={arr}, pos={pos}")
    print(f"  ans={ans}, expected={expected}  --> {'PASS' if ans == expected else 'FAIL'}")
    if ans != expected:
        raise AssertionError("Test failed")


if __name__ == "__main__":
    run_test([3,2,0,-4], 1, True)   # tail connects to node index 1
    run_test([1,2], 0, True)        # tail connects to head
    run_test([1], -1, False)        # no cycle
    run_test([], -1, False)         # empty list
    run_test([1,2,3,4,5], -1, False)
    print("All tests passed!")
