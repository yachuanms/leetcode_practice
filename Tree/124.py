class Solution(object):
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.res = float("-inf")

        def dfs(node):
            # 1. base case
            if not node:
                return 0
            # 2. 算 left gain
            left = dfs(node.left)
            # 3. 算 right gain
            right = dfs(node.right)
            # 4. 負數就不要
            if left < 0: left = 0
            if right < 0: right = 0
            # 5. 更新全域答案
            self.res = max(self.res, node.val+left+right)
            # 6. 回傳給 parent 的 gain
            return node.val+max(left, right)
            

        dfs(root)
        return self.res