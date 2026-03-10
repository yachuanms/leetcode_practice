class Solution:
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """

        if not grid:
            return -1
        
        rows = len(grid)
        cols = len(grid[0])

        #把小島淹掉
        def dfs(r,c):
            if r<0 or r>=rows or c<0 or c>=cols:
                return
            #遇到水就不用再延伸了
            if grid[r][c]=="0":
                return
            #遇到陸地
            grid[r][c] = "0"
            dfs(r-1,c)
            dfs(r+1,c)
            dfs(r,c-1)
            dfs(r,c+1)
        
        count = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == "1":
                    count+=1
                dfs(i,j)
        return count


if __name__ == "__main__":
    s = Solution()

    grid = [
        ["1","1","0","0","0"],
        ["1","1","0","0","0"],
        ["0","0","1","0","0"],
        ["0","0","0","1","1"]
    ]

    print(s.numIslands(grid))  # 3