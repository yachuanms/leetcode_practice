from typing import List


class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        
        if amount == 0:
            return 1

        # define dp
        DP = [0] * (amount+1)

        # base case
        DP[0] = 1

        # fill dp
        for coin in coins:
            for i in range(amount+1):
                #這個coin沒辦法增加i的方法數
                if i < coin:
                    continue
                else:
                    DP[i]+=DP[i-coin]

        # return answer

        return DP[amount]


def main():
    sol = Solution()

    test_cases = [
        (5, [1, 2, 5], 4),
        (3, [2], 0),
        (10, [10], 1),
        (0, [1, 2, 5], 1),
        (5, [5, 1, 2], 4),
    ]

    for amount, coins, expected in test_cases:
        result = sol.change(amount, coins)

        print(f"amount = {amount}, coins = {coins}")
        print(f"Expected = {expected}")
        print(f"Got = {result}")
        print("PASS" if result == expected else "FAIL")
        print("-" * 40)


if __name__ == "__main__":
    main()