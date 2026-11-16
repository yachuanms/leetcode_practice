#3105. Longest Strictly Increasing or Strictly Decreasing Subarray

from typing import List


class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        inc = 1
        dec = 1
        max_length = 1

        for i in range(1, n):
            if nums[i] > nums[i-1]: #increase
                inc+=1
                max_length = max(max_length, inc)
                dec = 1
            elif nums[i] < nums[i-1]: #decrease
                dec+=1
                max_length = max(max_length, dec)
                inc =1
            else:
                dec = 1
                inc = 1

        return max_length