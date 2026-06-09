from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:

        n = len(nums)

        if n == 1:
            return nums[0]

        def rob_linear(arr: List[int]) -> int:
            
            m = len(arr)

            if m == 1:
                return arr[0]

            dp = [0] * m

            #Base case
            dp[0] = arr[0]
            dp[1] = max(arr[0], arr[1])

            for i in range(2, m):
                dp[i] = max(dp[i-1], dp[i-2]+arr[i])

            return dp[m-1]

        #Case 1 : 不偷第一間
        case1 = rob_linear(nums[1:])
        #Case 2 : 不偷最後一間
        case2 = rob_linear(nums[:-1])

        return max(case1, case2)
        


def main():
    sol = Solution()

    test_cases = [
        ([1], 1),
        ([1, 2], 2),
        ([2, 3, 2], 3),
        ([1, 2, 3, 1], 4),
        ([1, 2, 3], 3),
        ([2, 7, 9, 3, 1], 11),
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