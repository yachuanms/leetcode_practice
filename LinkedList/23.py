# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

import heapq
class Solution:
    def mergeKLists(self, lists: list[ListNode | None]) -> ListNode | None:
        k = len(lists)

        # put the current node inside a min heap
        # find the node with min value and add it into ans linked list
        # if the node has next, put the next node into min heap
        heap = []
        for i, node in enumerate(lists):
            if node: # might have empty linked list
                heapq.heappush(heap, (node.val, i, node))
        
        dummy = ListNode()
        cur = dummy
        while heap:
            min_val, min_i, min_node = heapq.heappop(heap)
            cur.next = min_node
            if min_node.next:
                heapq.heappush(heap, (min_node.next.val, min_i, min_node.next))
            
            cur = cur.next
        return dummy.next