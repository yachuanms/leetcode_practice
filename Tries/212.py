class Solution:
    def findWords(self, board: list[list[str]], words: list[str]) -> list[str]:
        tries = {}
        rows = len(board)
        cols = len(board[0])

        for word in words:
            node = tries
            for cha in word:
                if cha not in node:
                    node[cha] = {}
                node = node[cha]
            node['#'] = word

        ans = []
        visited = set()

        def dfs(row, col, node):
            if row < 0 or row >= rows or col < 0 or col >= cols or (row, col) in visited:
                return

            char = board[row][col]

            if char not in node:
                return

            node = node[char]

            # TODO: 檢查是否找到完整單字
            if '#' in node:
                ans.append(node['#'])
                del node['#']

            # TODO: 標記目前格子已使用
            visited.add((row, col))

            dfs(row-1, col, node)
            dfs(row+1, col, node)
            dfs(row, col-1, node)
            dfs(row, col+1, node)

            # TODO: 恢復目前格子
            visited.remove((row, col))

        for row in range(rows):
            for col in range(cols):
                dfs(row, col, tries)
        return ans
    


def main():
    tests = [
        # Example 1
        (
            [
                ["o", "a", "a", "n"],
                ["e", "t", "a", "e"],
                ["i", "h", "k", "r"],
                ["i", "f", "l", "v"]
            ],
            ["oath", "pea", "eat", "rain"],
            ["oath", "eat"]
        ),

        # Cannot reuse a cell
        (
            [["a", "b"], ["c", "d"]],
            ["abcb"],
            []
        ),

        # Single cell
        (
            [["a"]],
            ["a", "b"],
            ["a"]
        ),

        # Word longer than available cells
        (
            [["a", "a"]],
            ["a", "aa", "aaa"],
            ["a", "aa"]
        ),

        # Multiple valid words
        (
            [["a", "b"], ["c", "d"]],
            ["ab", "ac", "bd", "cd"],
            ["ab", "ac", "bd", "cd"]
        ),

        # Shared prefixes
        (
            [["a", "p", "p", "l", "e"]],
            ["app", "apple", "apply"],
            ["app", "apple"]
        ),

        # Same word can be formed multiple ways
        (
            [["a", "a"], ["a", "a"]],
            ["aa", "aaa"],
            ["aa", "aaa"]
        )
    ]

    sol = Solution()

    for i, (board, words, expected) in enumerate(tests, 1):
        result = sol.findWords(
            [row[:] for row in board],
            words[:]
        )

        passed = (
            sorted(result) == sorted(expected)
            and len(result) == len(set(result))
        )

        print(f"Test {i}: {'PASS' if passed else 'FAIL'}")
        if not passed:
            print(f"  Expected: {expected}")
            print(f"  Got:      {result}")


if __name__ == "__main__":
    main()
