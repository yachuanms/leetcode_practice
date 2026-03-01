from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root):
        # TODO: 你寫
        if not root:
            return []
        
        queue = deque([root])
        result = []
        while queue:
            n = len(queue)
            level = []
            for i in range(n):
                node = queue.popleft()
                level.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            result.append(level)
        return result



def build_tree_1():
    #     3
    #    / \
    #   9  20
    #     /  \
    #    15   7
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    return root


def build_tree_2():
    # empty
    return None


def build_tree_3():
    # single node: 1
    return TreeNode(1)


def run_case(root, expected):
    sol = Solution()
    got = sol.levelOrder(root)
    print("got      =", got)
    print("expected =", expected)
    assert got == expected
    print("OK\n")


if __name__ == "__main__":
    run_case(build_tree_1(), [[3], [9, 20], [15, 7]])
    run_case(build_tree_2(), [])
    run_case(build_tree_3(), [[1]])