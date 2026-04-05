from collections import deque

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        node = root
        while node:
            if p.val < node.val and q.val < node.val:
                node = node.left
            elif p.val > node.val and q.val > node.val:
                node = node.right
            else:
                return node


def build_tree(values):
    if not values:
        return None

    root = TreeNode(values[0])
    queue = deque([root])
    i = 1

    while queue and i < len(values):
        node = queue.popleft()

        if i < len(values) and values[i] is not None:
            node.left = TreeNode(values[i])
            queue.append(node.left)
        i += 1

        if i < len(values) and values[i] is not None:
            node.right = TreeNode(values[i])
            queue.append(node.right)
        i += 1

    return root


def find_node(root, target):
    if not root:
        return None
    if root.val == target:
        return root

    left = find_node(root.left, target)
    if left:
        return left
    return find_node(root.right, target)


if __name__ == "__main__":
    sol = Solution()

    root1 = build_tree([6, 2, 8, 0, 4, 7, 9, None, None, 3, 5])
    p1 = find_node(root1, 2)
    q1 = find_node(root1, 8)
    print(sol.lowestCommonAncestor(root1, p1, q1).val)  # expected: 6

    root2 = build_tree([6, 2, 8, 0, 4, 7, 9, None, None, 3, 5])
    p2 = find_node(root2, 2)
    q2 = find_node(root2, 4)
    print(sol.lowestCommonAncestor(root2, p2, q2).val)  # expected: 2