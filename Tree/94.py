# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def inorderTraversal(self, root):
        result = []
        
        def dfs(node):
            if not node:
                return
            
            # 左
            dfs(node.left)
            
            # 自己
            result.append(node.val)
            
            # 右
            dfs(node.right)
        
        dfs(root)
        return result
    
def build_test_tree():
    """
          1
           \
            2
           /
          3

    inorder 應該是 [1,3,2]
    """
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(3)
    return root


if __name__ == "__main__":
    root = build_test_tree()
    sol = Solution()
    print(sol.inorderTraversal(root))  # [1, 3, 2]