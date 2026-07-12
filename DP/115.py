from typing import List


class Solution:
    def numDistinct(self, s: str, t: str) -> int:

        # lengths

        # define dp

        # base case

        # fill dp

        # return answer

        pass


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