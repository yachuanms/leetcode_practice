from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:

        if amount == 0:
            return 0
        
        INF = float("inf")

        DP = [INF] * (amount+1)

        # base case
        DP[0] = 0

        # fill dp
        for i in range(1, amount+1):
            for coin in coins:
                if i - coin >= 0:    
                    DP[i] = min(DP[i], DP[i-coin]+1)

        # return answer
        if DP[amount] == INF:
            return -1

        return DP[amount]


def main():
    sol = Solution()

    test_cases = [
        ([1, 2, 5], 11, 3),
        ([2], 3, -1),
        ([1], 0, 0),
        ([1], 1, 1),
        ([1], 2, 2),
    ]

    for coins, amount, expected in test_cases:
        result = sol.coinChange(coins, amount)

        print(f"coins = {coins}")
        print(f"amount = {amount}")
        print(f"Expected = {expected}")
        print(f"Got = {result}")
        print("PASS" if result == expected else "FAIL")
        print("-" * 40)


if __name__ == "__main__":
    main()