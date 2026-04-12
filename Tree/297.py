from collections import deque

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        ans = []

        def dfs(node):
            if not node:
                ans.append("#")
                return

            ans.append(str(node.val))

            dfs(node.left)
            dfs(node.right)

        dfs(root)
        return ",".join(ans)


    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        vals = iter(data.split(","))

        def dfs():
            val = next(vals)
            if val == "#":
                return None
            
            node = TreeNode(int(val))
            node.left = dfs()
            node.right = dfs()
            return node
        
        return dfs()



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


def level_order_values(root):
    """
    Serialize tree to level-order list for easy checking.
    Trim trailing None values.
    """
    if not root:
        return []

    result = []
    queue = deque([root])

    while queue:
        node = queue.popleft()
        if node:
            result.append(node.val)
            queue.append(node.left)
            queue.append(node.right)
        else:
            result.append(None)

    while result and result[-1] is None:
        result.pop()

    return result


if __name__ == "__main__":
    ser = Codec()
    deser = Codec()

    root1 = build_tree([1, 2, 3, None, None, 4, 5])
    data1 = ser.serialize(root1)
    print("serialized:", data1)
    rebuilt1 = deser.deserialize(data1)
    print("rebuilt:", level_order_values(rebuilt1))   # expected: [1, 2, 3, None, None, 4, 5]

    root2 = build_tree([])
    data2 = ser.serialize(root2)
    print("serialized:", data2)
    rebuilt2 = deser.deserialize(data2)
    print("rebuilt:", level_order_values(rebuilt2))   # expected: []

    root3 = build_tree([1])
    data3 = ser.serialize(root3)
    print("serialized:", data3)
    rebuilt3 = deser.deserialize(data3)
    print("rebuilt:", level_order_values(rebuilt3))   # expected: [1]