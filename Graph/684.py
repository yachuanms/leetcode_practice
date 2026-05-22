from typing import List


class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:

        parent = []
        for i in range(len(edges)+1):
            parent.append(i)

        def find(x):
            #找root
            while parent[x] != x:
                x = parent[x]
            return x
        
        def union(a, b):
            ra = find(a)
            rb = find(b)

            #已經connected-> 這是多的邊
            if ra == rb:
                return False

            #連到同一root
            parent[rb] = ra

            return True
        

        for a, b in edges:
            if not union(a, b):
                return [a, b]
        
        return [-1, -1]


def test_redundant_connection():
    s = Solution()

    print(s.findRedundantConnection([[1,2],[1,3],[2,3]]))
    # expected: [2,3]

    print(s.findRedundantConnection([[1,2],[2,3],[3,4],[1,4],[1,5]]))
    # expected: [1,4]


if __name__ == "__main__":
    test_redundant_connection()