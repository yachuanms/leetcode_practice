from typing import Optional


class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        # TODO: handle empty graph

        old_to_new = {}

        def dfs(cur):
            # TODO:
            
            if cur is None:
                return 
            if cur in old_to_new:
                return old_to_new[cur]
            
            copy = Node(cur.val)
            #在DFS前立刻存進 dict（超重要）
            #避免CYCLE繞回來
            old_to_new[cur] = copy
            #處理 neighbors 
            for neighbor in cur.neighbors:
                #dfs: 把neighbor clone出來才能連到copy上
                #不是neighbor本人直接clone到copy上 要做新的node
                copy.neighbors.append(dfs(neighbor))
            
            return copy

        return dfs(node)


def build_graph(adjList):
    if not adjList:
        return None

    nodes = {i + 1: Node(i + 1) for i in range(len(adjList))}

    for i, neighbors in enumerate(adjList, start=1):
        for nei in neighbors:
            nodes[i].neighbors.append(nodes[nei])

    return nodes[1]


def graph_to_adjlist(node):
    if not node:
        return []

    visited = {}
    queue = [node]

    while queue:
        cur = queue.pop(0)

        if cur.val in visited:
            continue

        visited[cur.val] = sorted([nei.val for nei in cur.neighbors])

        for nei in cur.neighbors:
            if nei.val not in visited:
                queue.append(nei)

    return [visited[i] for i in range(1, len(visited) + 1)]


def test_clone_graph():
    s = Solution()

    node1 = build_graph([[2,4], [1,3], [2,4], [1,3]])
    clone1 = s.cloneGraph(node1)
    print(graph_to_adjlist(clone1))  # expected: [[2,4], [1,3], [2,4], [1,3]]
    print(clone1 is not node1)       # expected: True

    node2 = build_graph([[]])
    clone2 = s.cloneGraph(node2)
    print(graph_to_adjlist(clone2))  # expected: [[]]
    print(clone2 is not node2)       # expected: True

    node3 = build_graph([])
    clone3 = s.cloneGraph(node3)
    print(graph_to_adjlist(clone3))  # expected: []


if __name__ == "__main__":
    test_clone_graph()