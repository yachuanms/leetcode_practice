from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # handle empty input if needed

        # initialize states for day 0
        hold = -prices[0]
        sold = 0
        rest = 0

        for i in range(1, len(prices)):
            new_hold = max(hold, rest-prices[i])
            new_sold = hold+prices[i]
            new_rest = max(rest, sold)
            hold = new_hold
            sold = new_sold
            rest = new_rest

        return max(sold, rest, hold)


def main():
    sol = Solution()

    test_cases = [
        ([1, 2, 3, 0, 2], 3),
        ([1], 0),
        ([1, 2], 1),
        ([2, 1, 4], 3),
        ([6, 1, 3, 2, 4, 7], 6),
    ]

    for prices, expected in test_cases:
        result = sol.maxProfit(prices)

        print(f"prices = {prices}")
        print(f"Expected = {expected}")
        print(f"Got = {result}")
        print("PASS" if result == expected else "FAIL")
        print("-" * 40)


if __name__ == "__main__":
    main()