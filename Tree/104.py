# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

''' DFS
class Solution:
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # TODO: 你寫
        if not root:
            return 0

        left = self.maxDepth(root.left)
        right = self.maxDepth(root.right)

        return 1+max(left,right)
'''

#BFS
from collections import deque
class Solution:
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # TODO: 你寫
        if not root :
            return 0
        queue = deque([root])
        level = 0
        while queue:
            level+=1
            for i in range(len(queue)):
                node = queue.popleft()
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

        return level
        

# -------------------------
# 測試用樹
# -------------------------

def build_tree_1():
    #     3
    #    / \
    #   9  20
    #     /  \
    #    15   7
    # 深度 = 3
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    return root


def build_tree_2():
    # 單節點
    # 深度 = 1
    return TreeNode(1)


def build_tree_3():
    # 空樹
    # 深度 = 0
    return None


def run_test(root, expected):
    sol = Solution()
    result = sol.maxDepth(root)
    print("Result:", result, " Expected:", expected)
    assert result == expected
    print("OK\n")


if __name__ == "__main__":
    run_test(build_tree_1(), 3)
    run_test(build_tree_2(), 1)
    run_test(build_tree_3(), 0)