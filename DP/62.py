#2D DP
#可用排組公式解

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # define dp table
        # initialize first row and first column (填一)
        DP = [[1]*n for _ in range(m)] 

        # fill dp table
        for r in range(1, m):
            for c in range(1, n):
                DP[r][c] = DP[r-1][c]+DP[r][c-1]

        # return answer
        return DP[m-1][n-1]
        


def main():
    sol = Solution()

    test_cases = [
        (3, 7, 28),
        (3, 2, 3),
        (7, 3, 28),
        (1, 1, 1),
        (1, 5, 1),
        (5, 1, 1),
    ]

    for m, n, expected in test_cases:
        result = sol.uniquePaths(m, n)

        print(f"m = {m}, n = {n}")
        print(f"Expected = {expected}")
        print(f"Got = {result}")
        print("PASS" if result == expected else "FAIL")
        print("-" * 40)


if __name__ == "__main__":
    main()