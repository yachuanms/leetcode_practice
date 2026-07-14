from typing import List


class Solution:
    def numDistinct(self, s: str, t: str) -> int:

        # lengths
        lens = len(s)
        lent = len(t)

        # define dp
        DP = [[0] *(lent+1) for _ in range(lens+1)]

        # base case
        for i in range(lens+1):
            DP[i][0] = 1

        #要避開DP[0][0]
        for j in range(1, lent+1):
            DP[0][j] = 0

        # fill dp
        for i in range(1, lens+1):
            for j in range(1, lent+1):
                #最後一個字元相同:
                #1. 留下
                #2. 刪掉
                if s[i-1] == t[j-1]:
                    DP[i][j] = DP[i-1][j-1]+DP[i-1][j]
                else:
                    #刪掉
                    DP[i][j] = DP[i-1][j]

        # return answer
        return DP[lens][lent]


def main():
    sol = Solution()

    test_cases = [
        ("rabbbit", "rabbit", 3),
        ("babgbag", "bag", 5),
        ("abc", "abc", 1),
        ("abc", "abcd", 0),
        ("", "", 1),
    ]

    for s, t, expected in test_cases:
        result = sol.numDistinct(s, t)

        print(f"s = {s}, t = {t}")
        print(f"Expected = {expected}")
        print(f"Got = {result}")
        print("PASS" if result == expected else "FAIL")
        print("-" * 40)


if __name__ == "__main__":
    main()