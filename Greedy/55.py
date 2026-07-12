from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        farest = 0

        for i in range(len(nums)):
            #根本到不了這格 (那一定不可能到最後一格)
            if farest < i:
                return False

            #farest = max(i+nums[i], farest)
            if i + nums[i] > farest:
                farest = i + nums[i]

        return True if farest >= len(nums)-1 else False

# -------------------------
# Testing
# -------------------------

def main():
    sol = Solution()

    test_cases = [
        ([2, 3, 1, 1, 4], True),
        ([3, 2, 1, 0, 4], False),
        ([0], True),
        ([2, 0], True),
        ([1, 0, 1], False),
        ([2, 5, 0, 0], True),
        ([1, 2, 0, 1], True),
        ([0, 2], False),
    ]

    for nums, expected in test_cases:
        result = sol.canJump(nums)
        print(f"nums = {nums}")
        print(f"Output   = {result}")
        print(f"Expected = {expected}")
        print("-" * 30)


if __name__ == "__main__":
    main()