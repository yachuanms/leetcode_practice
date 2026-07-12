from typing import List


class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        ROWS = len(matrix)
        COLS = len(matrix[0])

        memo = {}

        def dfs(r: int, c: int) -> int:
            # if already computed, return memo
            if (r, c) in memo:
                return memo[(r, c)]
            # at least this cell itself
            path = 1
            # explore 4 directions
            directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]
            for dr, dc in directions:
                nr = r+dr
                nc = c+dc
                if (0 <= nr< ROWS and 0 <= nc < COLS  and matrix[nr][nc]> matrix[r][c]):
                    nei = dfs(nr, nc)
                    path = max(path, 1+nei)
            # save to memo
            memo[(r, c)] = path
            # return result
            return path

        result = 0

        for r in range(ROWS):
            for c in range(COLS):
                result = max(result, dfs(r, c))

        return result


def main():
    sol = Solution()

    test_cases = [
        (
            [
                [9,9,4],
                [6,6,8],
                [2,1,1]
            ],
            4
        ),
        (
            [
                [3,4,5],
                [3,2,6],
                [2,2,1]
            ],
            4
        ),
        (
            [[1]],
            1
        ),
        (
            [
                [1,2],
                [4,3]
            ],
            4
        ),
    ]

    for matrix, expected in test_cases:
        result = sol.longestIncreasingPath(matrix)

        print(f"matrix = {matrix}")
        print(f"Expected = {expected}")
        print(f"Got = {result}")
        print("PASS" if result == expected else "FAIL")
        print("-" * 40)


if __name__ == "__main__":
    main()