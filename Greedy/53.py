from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # TODO:
        # 初始化 current_sum 和 max_sum
        # 提示：全負數測資要考慮
        current_sum = nums[0]
        max_sum = nums[0]

        # TODO:
        # 從第二個元素開始掃描
        for i in range(1, len(nums)):
            # TODO:
            # 更新 current_sum
            current_sum = max(nums[i], current_sum+nums[i])
            # 是延續前面的 subarray？
            # 還是從 nums[i] 重新開始？

            # TODO:
            # 更新 max_sum
            max_sum = max(max_sum, current_sum)

        # TODO:
        # 回傳答案
        return max_sum


# -------------------------
# Testing
# -------------------------

def main():
    sol = Solution()

    test_cases = [
        ([-2,1,-3,4,-1,2,1,-5,4], 6),
        ([1], 1),
        ([5,4,-1,7,8], 23),
        ([-3,-2,-5], -2),
        ([1,-2,3,4], 7),
    ]

    for nums, expected in test_cases:
        result = sol.maxSubArray(nums)

        print(f"nums     = {nums}")
        print(f"Output   = {result}")
        print(f"Expected = {expected}")
        print("-" * 40)


if __name__ == "__main__":
    main()