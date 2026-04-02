class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.res = 0

        def dfs(node):
            # 1. base case
            if not node:
                return 0
            # 2. left height
            left = dfs(node.left)
            # 3. right height
            right = dfs(node.right)
            # 4. 更新 diameter
            self.res = max(self.res, left + right)
            # 5. 回傳 height
            return max(left, right)+1

        dfs(root)
        return self.res