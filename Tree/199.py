from collections import deque

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """

        '''dfs
        ans = []

        def dfs(node, depth):
            if not node:
                return

            if depth == len(ans):
                ans.append(node.val)

            #先右再左
            dfs(node.right, depth+1)
            dfs(node.left, depth+1)    

        dfs(root, 0)
        return ans            
        '''
        #bfs
        if not root:
            return []
        ans = []
        queue = deque([root])

        while queue:
            level_size = len(queue)
            for i in range(level_size):
                node = queue.popleft()
                rightmost = node
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            ans.append(rightmost.val)
        return ans


def build_tree(values):
    """
    values: level-order list, use None for missing nodes
    """
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

    # Example 1
    root1 = build_tree([1, 2, 3, None, 5, None, 4])
    print(sol.rightSideView(root1))   # expected: [1, 3, 4]

    # Example 2
    root2 = build_tree([1, 2, 3, 4, None, None, None])
    print(sol.rightSideView(root2))   # expected: [1, 3, 4]

    # Example 3
    root3 = build_tree([])
    print(sol.rightSideView(root3))   # expected: []

    # Example 4
    root4 = build_tree([1])
    print(sol.rightSideView(root4))   # expected: [1]