
from typing import List
import heapq


class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)

        visited = set()
        minHeap = [(grid[0][0], 0, 0)]  # (height, r, c)
        res = 0

        while minHeap:
            height, r, c = heapq.heappop(minHeap)

            # TODO:
            # if visited, continue
            if (r, c) in visited:
                continue

            # TODO:
            # add visited
            visited.add((r, c))
            # update res = max(res, height)
            res = max(res, height)

            # TODO:
            # if reach bottom-right, return res
            if r == n-1 and c == n-1:
                return res

            # TODO:
            # push 4-direction valid neighbors into heap
            for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nr = dr+r
                nc = dc+c
                if 0 <= nr <= n and 0 <= nc <= n and (nr,nc) not in visited:
                    heapq.heappush(minHeap, (grid[nr][nc], nr, nc))


        return res