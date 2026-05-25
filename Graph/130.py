from typing import List


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        rows, cols = len(board), len(board[0])

        #把和邊界連接的O改成T(temp)註記
        def dfs(r, c):
            if 0 <= r < rows and 0 <= c < cols and board[r][c] == "O":
                board[r][c] = "T"
                #向四周擴散dfs
                dfs(r+1, c)
                dfs(r-1, c)
                dfs(r, c+1)
                dfs(r, c-1)

        #掃過board 把 和邊界相連的O 做dfs改成T
        #top and bottom
        for c in range(cols):
            dfs(0, c)
            dfs(rows-1, c)

        #left and right
        for r in range(rows):
            dfs(r, 0)
            dfs(r, cols-1)

        #重新掃一遍board 把
        #O -> X
        #T -> O
        for r in range(rows):
            for c in range(cols):
                if board[r][c] == "O":
                    board[r][c] = "X"
                if board[r][c] == "T":
                    board[r][c] = "O"

        return board


def test_surrounded_regions():
    s = Solution()

    board1 = [
        ["X","X","X","X"],
        ["X","O","O","X"],
        ["X","X","O","X"],
        ["X","O","X","X"]
    ]

    expected1 = [
        ["X","X","X","X"],
        ["X","X","X","X"],
        ["X","X","X","X"],
        ["X","O","X","X"]
    ]

    result1 = s.solve(board1)
    print(result1)
    print(result1 == expected1)  # expected: True

    board2 = [
        ["X"]
    ]

    expected2 = [
        ["X"]
    ]

    result2 = s.solve(board2)
    print(result2)
    print(result2 == expected2)  # expected: True


if __name__ == "__main__":
    test_surrounded_regions()