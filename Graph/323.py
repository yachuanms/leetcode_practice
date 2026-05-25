from typing import List

#323
#有多少個未相連的components?

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:

        #build adjacency list
        graph = {i:[] for i in range(n)}

        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)

        visited = set()

        #dfs
        def dfs(node):
            if node not in visited:
                visited.add(node)
                #遍歷鄰居
                for nei in graph[node]:
                    dfs(nei)

            return

        count = 0

        for node in range(n):
            if node not in visited:
                dfs(node)
                count += 1

        return count



def test_connected_components():
    s = Solution()

    print(s.countComponents(5, [[0,1],[1,2],[3,4]]))
    # expected: 2

    print(s.countComponents(5, [[0,1],[1,2],[2,3],[3,4]]))
    # expected: 1

    print(s.countComponents(5, []))
    # expected: 5

    print(s.countComponents(4, [[0,1],[2,3]]))
    # expected: 2


if __name__ == "__main__":
    test_connected_components()