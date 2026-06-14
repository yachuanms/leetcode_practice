from typing import List

#*List 有負數!
#DP 以 nums[i] 結尾的最大，最小乘積(因為負負會得正)

class Solution:
    def maxProduct(self, nums: List[int]) -> int:

        n = len(nums)

        # initialize
        INF = float("inf")
        NINF = float("-inf")

        maxP = [NINF]*(n+1)
        minP = [INF]*(n+1)

        maxP[0] = nums[0]
        minP[0] = nums[0]
        res = nums[0]

        # iterate through nums
        for i in range(1, n):
            candidates = [nums[i], maxP[i-1]*nums[i], minP[i-1]*nums[i]]
            maxP[i] = max(candidates)
            minP[i] = min(candidates)

            res = max(res, maxP[i])

        return res            
        


def main():
    sol = Solution()

    test_cases = [
        ([2,3,-2,4], 6),
        ([-2,0,-1], 0),
        ([-2,3,-4], 24),
        ([0,2], 2),
        ([-2], -2),
    ]

    for nums, expected in test_cases:
        result = sol.maxProduct(nums)

        print(f"nums = {nums}")
        print(f"Expected = {expected}")
        print(f"Got = {result}")
        print("PASS" if result == expected else "FAIL")
        print("-" * 40)


if __name__ == "__main__":
    main()