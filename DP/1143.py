class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # lengths
        len1 = len(text1)
        len2 = len(text2)

        # define dp table
        DP = [[0]*(len2+1) for _ in range(len1+1)]

        #Base Case
        #DP[0][0] = 0 空字串

        # fill dp table
        for r in range(1, len1+1):
            for c in range(1, len2+1):
                if text1[r-1] == text2[c-1]:
                    #代表最新的字元這次匹配要用
                    #所以取DP[i-1][j-1] 避免aaa/aa這種例子 字元被算到用了兩次
                    DP[r][c] = DP[r-1][c-1]+1
                else:
                    DP[r][c] = max(DP[r-1][c], DP[r][c-1])

        # return answer
        return DP[len1][len2]


def main():
    sol = Solution()

    test_cases = [
        ("abcde", "ace", 3),
        ("abc", "abc", 3),
        ("abc", "def", 0),
        ("bsbininm", "jmjkbkjkv", 1),
        ("ezupkr", "ubmrapg", 2),
    ]

    for text1, text2, expected in test_cases:
        result = sol.longestCommonSubsequence(text1, text2)

        print(f"text1 = {text1}, text2 = {text2}")
        print(f"Expected = {expected}")
        print(f"Got = {result}")
        print("PASS" if result == expected else "FAIL")
        print("-" * 40)


if __name__ == "__main__":
    main()