from collections import deque

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        def build(preorder, inorder):
            if not preorder or not inorder:
                return None

            root_val = preorder[0]
            root = TreeNode(root_val)
            left_size = inorder.index(root_val)

            root.left = build(preorder[1:1+left_size], inorder[:left_size])
            root.right = build(preorder[1+left_size:], inorder[left_size+1:])

            return root
        
        return build(preorder, inorder)


def level_order_values(root):
    """
    Serialize tree to level-order list for easy checking.
    Trim trailing None values.
    """
    if not root:
        return []

    result = []
    queue = deque([root])

    while queue:
        node = queue.popleft()
        if node:
            result.append(node.val)
            queue.append(node.left)
            queue.append(node.right)
        else:
            result.append(None)

    while result and result[-1] is None:
        result.pop()

    return result


if __name__ == "__main__":
    sol = Solution()

    root1 = sol.buildTree(
        [3, 9, 20, 15, 7],
        [9, 3, 15, 20, 7]
    )
    print(level_order_values(root1))   # expected: [3, 9, 20, None, None, 15, 7]

    root2 = sol.buildTree(
        [-1],
        [-1]
    )
    print(level_order_values(root2))   # expected: [-1]

    root3 = sol.buildTree(
        [1, 2],
        [2, 1]
    )
    print(level_order_values(root3))   # expected: [1, 2]