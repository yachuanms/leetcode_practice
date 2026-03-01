# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        # TODO: 你寫
        # 提示：寫一個 helper(node) 回傳高度
        # 如果發現不平衡就回傳 -1
        
        def height(node):
            if not node:
                return 0
            left = height(node.left)
            right = height(node.right)
            if left == -1 or right == -1:
                return -1
            balance = abs(left-right)
            if balance > 1:
                return -1
            else:
                return 1+max(left, right)
        return height(root) != -1


# -------------------------
# 測試用樹
# -------------------------

def build_balanced_tree():
    #       3
    #      / \
    #     9  20
    #       /  \
    #      15   7
    # True
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    return root


def build_unbalanced_tree():
    #       1
    #      /
    #     2
    #    /
    #   3
    # False
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.left.left = TreeNode(3)
    return root


if __name__ == "__main__":
    sol = Solution()
    print(sol.isBalanced(build_balanced_tree()))    # True
    print(sol.isBalanced(build_unbalanced_tree()))  # False