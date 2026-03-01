# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        # TODO: 你寫
        if not root:
            return
        root.right, root.left = root.left, root.right
        self.invertTree(root.right)
        self.invertTree(root.left)
        return root
#訪問每一個 node 一次
#O(n)


# -------------------------
# 測試用樹
# -------------------------

def build_tree():
    #         4
    #        / \
    #       2   7
    #      / \ / \
    #     1  3 6  9

    root = TreeNode(4)
    root.left = TreeNode(2)
    root.right = TreeNode(7)
    root.left.left = TreeNode(1)
    root.left.right = TreeNode(3)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(9)
    return root


def inorder(root):
    if not root:
        return []
    return inorder(root.left) + [root.val] + inorder(root.right)


if __name__ == "__main__":
    root = build_tree()
    sol = Solution()
    new_root = sol.invertTree(root)
    
    # 反轉後 inorder 應該是 [9,7,6,4,3,2,1]
    print(inorder(new_root))