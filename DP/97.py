class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        len1 = len(s1)
        len2 = len(s2)

        if len(s3) != len1 + len2:
            return False

        # DP[i][j] =
        # s1 前 i 個字元 + s2 前 j 個字元
        # 能不能組成 s3 前 i+j 個字元
        DP = [[False] * (len2 + 1) for _ in range(len1 + 1)]

        DP[0][0] = True

        # 只用 s1 組成 s3
        for i in range(1, len1 + 1):
            DP[i][0] = DP[i - 1][0] and s1[i - 1] == s3[i - 1]

        # 只用 s2 組成 s3
        for j in range(1, len2 + 1):
            DP[0][j] = DP[0][j - 1] and s2[j - 1] == s3[j - 1]

        for i in range(1, len1 + 1):
            for j in range(1, len2 + 1):
                from_s1 = DP[i - 1][j] and s1[i - 1] == s3[i + j - 1]
                from_s2 = DP[i][j - 1] and s2[j - 1] == s3[i + j - 1]

                DP[i][j] = from_s1 or from_s2

        return DP[len1][len2]


def main():
    sol = Solution()

    test_cases = [
        ("aabcc", "dbbca", "aadbbcbcac", True),
        ("aabcc", "dbbca", "aadbbbaccc", False),
        ("", "", "", True),
        ("abc", "", "abc", True),
        ("", "abc", "abc", True),
        ("abc", "def", "adbcef", True),
        ("abc", "def", "abdfec", False),
    ]

    for s1, s2, s3, expected in test_cases:
        result = sol.isInterleave(s1, s2, s3)

        print(f"s1 = {s1}, s2 = {s2}, s3 = {s3}")
        print(f"Expected = {expected}")
        print(f"Got = {result}")
        print("PASS" if result == expected else "FAIL")
        print("-" * 40)


if __name__ == "__main__":
    main()