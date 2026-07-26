from typing import List


class Solution:
    def jump(self, nums: List[int]) -> int:

        n = len(nums)

        jump = 0
        current_end = 0
        farest= 0

        for i in range(n-1):
            farest = max(farest, i+nums[i])

            #必須得跳一次了
            if i == current_end:
                jump += 1
                #最遠跳多遠
                current_end= farest

            #跳到最後一格就不跳了
            if current_end >= n-1:
                break

        return jump



# -------------------------
# Testing
# -------------------------

def main():
    sol = Solution()

    test_cases = [
        ([2,3,1,1,4], 2),
        ([2,3,0,1,4], 2),
        ([1], 0),
        ([1,2], 1),
        ([3,2,1], 1),
    ]

    for nums, expected in test_cases:
        result = sol.jump(nums)

        print(f"nums     = {nums}")
        print(f"Output   = {result}")
        print(f"Expected = {expected}")
        print("-" * 40)


if __name__ == "__main__":
    main()