from typing import List


class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:

        if len(edges) != n-1:
            return False
        # TODO:
        # 1. 建 undirected graph adjacency list
        graph = {}

        for i in range(n):
            graph[i] = []

        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)

        visited = set()
    
        # 2. DFS 檢查 cycle
        def dfs(node, parent):
            if node in visited:
                return False
            
            visited.add(node)
            for nei in graph[node]:
                if nei == parent:
                    continue
                if not dfs(nei, node):
                    return False
                
            return True
        if not dfs(0, -1):
            return False
        
        # 3. 確認所有 node 都 visited
        return len(visited) == n
        


def test_valid_tree():
    s = Solution()

    print(s.validTree(5, [[0,1],[0,2],[0,3],[1,4]]))  
    # expected: True

    print(s.validTree(5, [[0,1],[1,2],[2,3],[1,3],[1,4]]))  
    # expected: False

    print(s.validTree(4, [[0,1],[2,3]]))  
    # expected: False

    print(s.validTree(1, []))  
    # expected: True


if __name__ == "__main__":
    test_valid_tree()