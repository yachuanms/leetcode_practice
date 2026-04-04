from collections import deque

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def goodNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        
        def dfs(node, max_so_far):
            if not node:
                return 0
            count = 0
            if node.val >= max_so_far:
                count +=1
            max_so_far = max(node.val, max_so_far)
            count+=dfs(node.left, max_so_far)
            count+=dfs(node.right, max_so_far)
            return count

        ans = dfs(root, root.val)
        return ans


def build_tree(values):
    """
    Build tree from level-order list.
    Use None for missing nodes.
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

    root1 = build_tree([3, 1, 4, 3, None, 1, 5])
    print(sol.goodNodes(root1))  # expected: 4

    root2 = build_tree([3, 3, None, 4, 2])
    print(sol.goodNodes(root2))  # expected: 3

    root3 = build_tree([1])
    print(sol.goodNodes(root3))  # expected: 1