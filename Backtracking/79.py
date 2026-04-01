class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """

        rows = len(board)
        cols = len(board[0])

        def dfs(i, j, k):
            #1. base case
            if k == len(word):
                return True
            #2. 已經用過 + 超出邊界
            if i >= rows or i < 0 or j >= cols or j < 0 or board[i][j] == "#":
                return False
            #3. match-> 標記用過; 不match -> 回去
            temp = board[i][j]
            if temp == word[k]:
                board[i][j] = "#"
            else:
                return False
            #4. 往四個方向走
            ans = dfs(i+1, j, k+1) or dfs(i-1, j, k+1) or dfs(i, j+1, k+1) or dfs(i, j-1, k+1)
            #5. 這層結束 恢復未標記
            board[i][j] = temp
            return ans
        
        for i in range(rows):
            for j in range(cols):
                if dfs(i, j, 0):
                    return True

        return False


if __name__ == "__main__":
    s = Solution()

    board = [
        ["A","B","C","E"],
        ["S","F","C","S"],
        ["A","D","E","E"]
    ]

    print(s.exist(board, "ABCCED"))  # True
    print(s.exist(board, "SEE"))     # True
    print(s.exist(board, "ABCB"))    # False