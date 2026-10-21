class Solution:
    def solveNQueens(self, n: int) -> list[list[str]]:
        queens = []
        res = []

        def isValid(row, col):
            for r, c in queens:
                if row == r or col == c or abs(row-r) == abs(col-c):
                    return False
            return True

        def backtrack(row):
            if row == n:
                res.append([])
                for r, c in queens:
                    res[-1].append('.'*c+'Q'+'.'*(n-c-1))
            for col in range(n):
                if isValid(row, col):
                    queens.append((row, col))
                    backtrack(row+1)
                    queens.pop()
            
        backtrack(0)
        return res
