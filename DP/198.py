from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len((nums))

        if n == 1:
            return nums[0]

        dp = [0] * n

        #Base case
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])

        for i in range(2, n):
            dp[i] = max(dp[i-1], dp[i-2]+nums[i])

        return dp[n-1]

        


def main():
    sol = Solution()

    test_cases = [
        ([1], 1),
        ([1, 2], 2),
        ([1, 2, 3, 1], 4),
        ([2, 7, 9, 3, 1], 12),
        ([2, 1, 1, 2], 4),
    ]

    for nums, expected in test_cases:
        result = sol.rob(nums)

        print(f"nums = {nums}")
        print(f"Expected = {expected}")
        print(f"Got = {result}")
        print("PASS" if result == expected else "FAIL")
        print("-" * 40)


if __name__ == "__main__":
    main()