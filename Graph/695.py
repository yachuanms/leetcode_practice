from typing import List


class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])

        def dfs(r, c):
            # TODO:
            # 1. base case: out of bounds or water -> return 0
            # 2. mark visited
            # 3. return 1 + dfs(4 directions)
            if r < 0 or c < 0 or r >= rows or c >= cols or grid[r][c] == 0:
                return 0
            grid[r][c] = 0
            
            return 1 + dfs(r+1, c)+dfs(r-1, c)+dfs(r, c+1)+dfs(r, c-1) 
            

        max_area = 0

        for r in range(rows):
            for c in range(cols):
                # TODO:
                # if land:
                #   area = dfs(...)
                #   update max_area
                if grid[r][c] == 1:
                    area = dfs(r, c)
                    max_area = max(area, max_area)    

        return max_area


def test_max_area():
    s = Solution()

    grid1 = [
        [0,0,1,0,0],
        [1,1,1,0,1],
        [0,1,0,0,1],
        [0,0,0,1,1]
    ]
    print(s.maxAreaOfIsland(grid1))  # expected: 5

    grid2 = [
        [0,0,0],
        [0,0,0]
    ]
    print(s.maxAreaOfIsland(grid2))  # expected: 0

    grid3 = [
        [1]
    ]
    print(s.maxAreaOfIsland(grid3))  # expected: 1


if __name__ == "__main__":
    test_max_area()