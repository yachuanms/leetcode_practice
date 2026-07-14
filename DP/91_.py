class Solution:
    def numDecodings(self, s: str) -> int:
        DP = [0] * (len(s)+1)

        DP[0] = 1

        for i in range(1, len(s)+1):
            if int(s[i-1]) != 0:
                DP[i] += DP[i-1]
            if i>= 2 and 10<= int(s[i-2:i]) <= 26:
                DP[i] += DP[i-2]

        return DP[len(s)]


def main():
    sol = Solution()

    test_cases = [
        ("12", 2),
        ("226", 3),
        ("06", 0),
        ("10", 1),
        ("27", 1),
        ("11106", 2),
        ("0", 0),
        ("2101", 1),
    ]

    for s, expected in test_cases:
        result = sol.numDecodings(s)

        print(f"s        = {s}")
        print(f"Output   = {result}")
        print(f"Expected = {expected}")
        print("-" * 30)


if __name__ == "__main__":
    main()