# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def postorderTraversal(self, root):
        result = []
        
        def dfs(node):
            if not node:
                return
            
            # 左
            dfs(node.left)
            
            # 右
            dfs(node.right)

            #自己
            result.append(node.val)
        
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
    print(sol.postorderTraversal(root))  # [3, 2, 1]