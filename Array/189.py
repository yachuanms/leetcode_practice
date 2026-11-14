class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        n = len(nums)

        # Normalize k
        k %= n

        if k == 0:
            return

        def reverse(left, right):
            while left < right:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1

        # 1. Reverse entire array
        reverse(0, n - 1)

        # 2. Reverse first k elements
        reverse(0, k - 1)

        # 3. Reverse remaining elements
        reverse(k, n - 1)