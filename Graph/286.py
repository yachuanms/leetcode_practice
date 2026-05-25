from typing import List
from collections import deque

INF = 2147483647


class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        rows, cols = len(grid), len(grid[0])

        q = deque()

        #把 gates(0)/treasure(0)加入queue中
        for x in range(rows):
            for y in range(cols):
                if grid[x][y] == 0:
                    q.append((x, y))

        #BFS
        def bfs():
            directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
            while q:
                x, y = q.popleft()
                for dx, dy in directions:
                    nx = x+dx
                    ny = y+dy

                    if 0<= nx < rows and 0 <= ny < cols and grid[nx][ny] == INF:
                        grid[nx][ny] = grid[x][y]+1
                        q.append((nx, ny))

        bfs()

        return grid


def test_islands_and_treasure():
    INF = 2147483647
    s = Solution()

    grid1 = [
        [INF, -1, 0, INF],
        [INF, INF, INF, -1],
        [INF, -1, INF, -1],
        [0, -1, INF, INF]
    ]

    expected1 = [
        [3, -1, 0, 1],
        [2, 2, 1, -1],
        [1, -1, 2, -1],
        [0, -1, 3, 4]
    ]

    result1 = s.islandsAndTreasure(grid1)
    print(result1)
    print(result1 == expected1)  # expected: True

    grid2 = [
        [0, -1],
        [INF, INF]
    ]

    expected2 = [
        [0, -1],
        [1, 2]
    ]

    result2 = s.islandsAndTreasure(grid2)
    print(result2)
    print(result2 == expected2)  # expected: True


if __name__ == "__main__":
    test_islands_and_treasure()