from typing import Optional


class Node:
    def __init__(self, x: int, next=None, random=None):
        self.val = x
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: Optional[Node]) -> Optional[Node]:
        # made the copy of Nodes first and record the old_to_new mapping in a dict
        cur = head
        old_to_new = {}

        while cur:
            newNode = Node(cur.val)
            old_to_new[cur] = newNode
            cur = cur.next

        # map None to None cause node.random might be None!!
        old_to_new[None] = None 
        # traverse linked-list again and link copied node to next and random copied node
        cur = head
        while cur:
            # A'.next = old_to_new[A.next]
            old_to_new[cur].next = old_to_new[cur.next]
            old_to_new[cur].random = old_to_new[cur.random]
            cur = cur.next

        #head'
        return old_to_new[head]



def build_list(values, random_indices):
    if not values:
        return None

    nodes = [Node(v) for v in values]

    for i in range(len(nodes) - 1):
        nodes[i].next = nodes[i + 1]

    for i, random_idx in enumerate(random_indices):
        if random_idx is not None:
            nodes[i].random = nodes[random_idx]

    return nodes[0]


def print_list(head):
    nodes = []
    current = head

    while current:
        nodes.append(current)
        current = current.next

    result = []

    for node in nodes:
        random_idx = None

        if node.random:
            random_idx = nodes.index(node.random)

        result.append((node.val, random_idx))

    print(result)


def main():
    sol = Solution()

    # 7 -> 13 -> 11 -> 10 -> 1
    # random relationships represented by indices:
    # 7.random  = None
    # 13.random = node 0
    # 11.random = node 4
    # 10.random = node 2
    # 1.random  = node 0

    head = build_list(
        [7, 13, 11, 10, 1],
        [None, 0, 4, 2, 0]
    )

    copied = sol.copyRandomList(head)

    print("Original:")
    print_list(head)

    print("Copied:")
    print_list(copied)


if __name__ == "__main__":
    main()