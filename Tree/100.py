# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        # TODO: 你寫
        if not p and not q:
            return True
        if not p or not q:
            return False
        if p.val == q.val:
            return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        else:
            return False
        



# -------------------------
# 測試用樹
# -------------------------

def build_same_tree():
    #     1
    #    / \
    #   2   3
    p = TreeNode(1)
    p.left = TreeNode(2)
    p.right = TreeNode(3)

    q = TreeNode(1)
    q.left = TreeNode(2)
    q.right = TreeNode(3)

    return p, q


def build_diff_tree():
    #     1        1
    #    /          \
    #   2            2
    p = TreeNode(1)
    p.left = TreeNode(2)

    q = TreeNode(1)
    q.right = TreeNode(2)

    return p, q


if __name__ == "__main__":
    sol = Solution()
    
    p, q = build_same_tree()
    print(sol.isSameTree(p, q))  # True

    p, q = build_diff_tree()
    print(sol.isSameTree(p, q))  # False