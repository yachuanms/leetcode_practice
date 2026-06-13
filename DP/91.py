class Solution:
    def numDecodings(self, s: str) -> int:

        n = len(s)

        #DP
        #dp[i] = 前 i 個字元有幾種解碼方式
        DP = [0] * (n+1)

        #Base Case
        DP[0] = 1

        for i in range(1, n+1):
            #last one digit
            #只看最後一位 有沒有解(不是0)
            one = int(s[i-1])
            if 1 <= one <= 9:
                DP[i] += DP[i-1]

            #last two digit
            #看最後兩位
            if i >= 2:
                two = int(s[i-2:i])
                if 10 <= two <= 26:
                    DP[i]+=DP[i-2]

        return DP[n]

        


def main():
    sol = Solution()

    test_cases = [
        ("12", 2),
        ("226", 3),
        ("06", 0),
        ("10", 1),
        ("20", 1),
        ("30", 0),
        ("11106", 2),
    ]

    for s, expected in test_cases:
        result = sol.numDecodings(s)

        print(f"s = {s}")
        print(f"Expected = {expected}")
        print(f"Got = {result}")
        print("PASS" if result == expected else "FAIL")
        print("-" * 40)


if __name__ == "__main__":
    main()