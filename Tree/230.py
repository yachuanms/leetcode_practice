from collections import deque

class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        self.count = 0
        self.ans = None
        #Inorder
        def dfs(node):
            #Python3 才有nonlocal
            #nonlocal count,ans

            if not node:
                return
            #找到就停 early stop!!
            if self.ans is not None:
                return
            #左
            dfs(node.left)
            #中
            self.count +=1
            if self.count == k:
                self.ans = node.val
                return
            #右
            dfs(node.right)
        dfs(root)
        return self.ans


def build_tree(values):
    if not values:
        return None

    root = TreeNode(values[0])
    queue = deque([root])
    i = 1

    while queue and i < len(values):
        node = queue.popleft()

        if i < len(values) and values[i] is not None:
            node.left = TreeNode(values[i])
            queue.append(node.left)
        i += 1

        if i < len(values) and values[i] is not None:
            node.right = TreeNode(values[i])
            queue.append(node.right)
        i += 1

    return root


if __name__ == "__main__":
    sol = Solution()

    root1 = build_tree([3,1,4,None,2])
    print(sol.kthSmallest(root1, 1))  # expected: 1

    root2 = build_tree([5,3,6,2,4,None,None,1])
    print(sol.kthSmallest(root2, 3))  # expected: 3