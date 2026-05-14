from typing import List


class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        rows, cols = len(heights), len(heights[0])
        pac = set()
        atl = set()

        def dfs(r, c, visit, prev_height):
            #out of bound
            if r < 0 or r >= rows or c < 0 or c >= cols :
                return
            #already visited
            if (r, c) in visit:
                return
            #lower -> cannot pass
            if heights[r][c] < prev_height:
                return
            
            #add to set
            visit.add((r, c))

            #遍歷四周
            dfs(r-1, c, visit, heights[r][c])
            dfs(r+1, c, visit, heights[r][c])
            dfs(r, c+1, visit, heights[r][c])
            dfs(r, c-1, visit, heights[r][c])

            return

        
        ans = []
        #top and bottom 
        for c in range(cols):
            dfs(0, c, pac, heights[0][c])
            dfs(rows-1, c, atl, heights[rows-1][c])

        #left and right
        for r in range(rows):
            dfs(r, 0, pac, heights[r][0])
            dfs(r, cols-1, atl, heights[r][cols-1])

        for r, c in pac & atl:
            ans.append((r, c))

        return ans