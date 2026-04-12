from typing import List


class Solution:
    def numIslands(self, grid) -> int:
        rows, cols = len(grid), len(grid[0])
        
        def dfs(r, c):
            # TODO:
            # 1. base case: out of bounds / water
            # 2. mark current land as visited
            # 3. dfs 4 directions
            if r < 0 or c < 0 or r >= rows or c >= cols or grid[r][c]=="0":
                return
            
            grid[r][c] = "0"
            dfs(r+1, c)
            dfs(r-1, c)
            dfs(r, c+1)
            dfs(r, c-1)
            return


        islands = 0

        for r in range(rows):
            for c in range(cols):
                # TODO:
                # if this cell is land:
                #   islands += 1
                #   dfs(r, c)
                if grid[r][c] == "1":
                    islands+=1
                dfs(r,c)

        return islands


def test_num_islands():
    s = Solution()

    grid1 = [
        ["1","1","1","1","0"],
        ["1","1","0","1","0"],
        ["1","1","0","0","0"],
        ["0","0","0","0","0"]
    ]
    print(s.numIslands(grid1))  # expected: 1

    grid2 = [
        ["1","1","0","0","0"],
        ["1","1","0","0","0"],
        ["0","0","1","0","0"],
        ["0","0","0","1","1"]
    ]
    print(s.numIslands(grid2))  # expected: 3

    grid3 = [
        ["1","0","1","0"],
        ["0","1","0","1"],
        ["1","0","1","0"]
    ]
    print(s.numIslands(grid3))  # expected: 6

    grid4 = [
        ["0","0","0"],
        ["0","0","0"]
    ]
    print(s.numIslands(grid4))  # expected: 0

    grid5 = [
        ["1"]
    ]
    print(s.numIslands(grid5))  # expected: 1


if __name__ == "__main__":
    test_num_islands()