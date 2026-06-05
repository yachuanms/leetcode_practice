class Solution:
    def climbStairs(self, n: int) -> int:

        if n <= 1:
            return 1

        # base case
        dp = [0] * (n+1)

        dp[1] = 1
        dp[2] = 2 #1+1 or 2

        # dp array
        for i in range(3, n+1):
            dp[i] = dp[i-1] + dp[i-2]

        # fill dp

        # return answer

        return dp[n]


def main():
    sol = Solution()

    test_cases = [
        (1, 1),
        (2, 2),
        (3, 3),
        (4, 5),
        (5, 8),
        (10, 89),
    ]

    for n, expected in test_cases:
        result = sol.climbStairs(n)

        print(f"n = {n}")
        print(f"Expected = {expected}")
        print(f"Got = {result}")
        print("PASS" if result == expected else "FAIL")
        print("-" * 30)


if __name__ == "__main__":
    main()