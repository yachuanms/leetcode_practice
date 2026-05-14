from collections import deque
from typing import List


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        queue = deque()
        fresh = 0

        # TODO 1: 初始化
        # - 把所有 rotten (2) 加進 queue
        # - 計算 fresh (1) 數量
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    queue.append((r, c))
                elif grid[r][c] == 1:
                    fresh += 1

        minutes = 0

        # TODO 2: BFS
        while queue and fresh > 0:
            # 一層 = 一分鐘
            # TODO: 跑當前 queue size
            for _ in range(len(queue)):
                r, c = queue.popleft()

                # TODO: 走四個方向
                for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    nr = r + dr
                    nc = c + dc
                    # 如果是 fresh:
                    if 0<= nr< rows and 0<= nc < cols and grid[nr][nc] == 1:
                        #   變 rotten
                        grid[nr][nc] = 2
                    #   fresh -= 1
                        fresh -= 1
                    #   加進 queue
                        queue.append((nr, nc))

            minutes += 1

        # TODO 3:
        # 如果還有 fresh → return -1
        # 否則 return minutes

        return minutes if fresh == 0 else -1


def test_rotting_oranges():
    s = Solution()

    grid1 = [
        [2,1,1],
        [1,1,0],
        [0,1,1]
    ]
    print(s.orangesRotting(grid1))  # expected: 4

    grid2 = [
        [2,1,1],
        [0,1,1],
        [1,0,1]
    ]
    print(s.orangesRotting(grid2))  # expected: -1

    grid3 = [
        [0,2]
    ]
    print(s.orangesRotting(grid3))  # expected: 0


if __name__ == "__main__":
    test_rotting_oranges()