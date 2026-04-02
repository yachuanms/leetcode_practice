class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def isSubtree(self, root, subRoot):
        """
        :type root: TreeNode
        :type subRoot: TreeNode
        :rtype: bool
        """

        def isSame(a, b):
            # 1. 兩個都空
            # 2. 一個空一個不空
            # 3. 值不同
            # 4. 遞迴比左右
            if not a and not b:
                return True
            if not a or not b:
                return False
            if a.val != b.val:
                return False
            return isSame(a.left, b.left) and isSame(a.right, b.right)

        def dfs(node):
            # 1. base case
            if not node:
                return False
            # 2. 如果這棵一樣，回傳 True
            if isSame(node, subRoot):
                return True
            # 3. 不然往左 / 右找
            return dfs(node.left) or dfs(node.right)

        return dfs(root)


if __name__ == "__main__":
    s = Solution()

    # root = [3,4,5,1,2], subRoot = [4,1,2]
    root = TreeNode(3)
    root.left = TreeNode(4)
    root.right = TreeNode(5)
    root.left.left = TreeNode(1)
    root.left.right = TreeNode(2)

    subRoot = TreeNode(4)
    subRoot.left = TreeNode(1)
    subRoot.right = TreeNode(2)

    print(s.isSubtree(root, subRoot))  # True

    s = Solution()
    # root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
    root2 = TreeNode(3)
    root2.left = TreeNode(4)
    root2.right = TreeNode(5)
    root2.left.left = TreeNode(1)
    root2.left.right = TreeNode(2)
    root2.left.right.left = TreeNode(0)

    subRoot2 = TreeNode(4)
    subRoot2.left = TreeNode(1)
    subRoot2.right = TreeNode(2)

    print(s.isSubtree(root2, subRoot2))  # False