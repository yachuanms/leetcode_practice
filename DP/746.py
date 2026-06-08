from typing import List


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:

        #cost.append(0)
        # define dp
        stairs = len(cost)

        dp = [0]*stairs

        # base case

        dp[0] = cost[0]
        dp[1] = cost[1]

        # fill dp
        for i in range(2, stairs):
            dp[i] = min(dp[i-2], dp[i-1])+cost[i]
            

        # return answer
        #最top階不在cost裡面
        #所以可以從往下一階或是兩階跳上去
        return min(dp[stairs-1], dp[stairs-2])


def main():
    sol = Solution()

    test_cases = [
        ([10,15,20], 15),
        ([1,100,1,1,1,100,1,1,100,1], 6),
    ]

    for cost, expected in test_cases:
        result = sol.minCostClimbingStairs(cost)

        print(f"cost = {cost}")
        print(f"Expected = {expected}")
        print(f"Got = {result}")
        print("PASS" if result == expected else "FAIL")
        print("-" * 40)


if __name__ == "__main__":
    main()