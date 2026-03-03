import math

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        # TODO: 你寫
        # 提示：寫 helper(node, low, high)
        
        def helper(node, low, high):
            if not node:
                return True
            if not (low < node.val < high):
                return False
            
            return helper(node.left, low, node.val) and helper(node.right, node.val, high)
        
        return helper(root, float('-inf'), float('inf'))


# -------------------------
# 測試用樹
# -------------------------

def build_valid_tree():
    #     2
    #    / \
    #   1   3
    root = TreeNode(2)
    root.left = TreeNode(1)
    root.right = TreeNode(3)
    return root


def build_invalid_tree():
    #     5
    #    / \
    #   1   7
    #      /
    #     4
    root = TreeNode(5)
    root.left = TreeNode(1)
    root.right = TreeNode(7)
    root.right.left = TreeNode(4)
    return root


if __name__ == "__main__":
    sol = Solution()
    print(sol.isValidBST(build_valid_tree()))   # True
    print(sol.isValidBST(build_invalid_tree())) # False