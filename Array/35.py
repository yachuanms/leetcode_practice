class Solution:
    def searchInsert(self, nums, target):
        left = 0
        right = len(nums)-1

        while left <= right:
            mid = (left+right)//2
            if target > nums[mid]:
                left = mid+1
            elif target < nums[mid]:
                right = mid-1
            else:
                return mid
        return left


def run_test(nums, target, expected):
    sol = Solution()
    ans = sol.searchInsert(nums, target)
    print(f"nums={nums}, target={target}")
    print(f"  ans={ans}, expected={expected}  --> {'PASS' if ans == expected else 'FAIL'}")
    if ans != expected:
        raise AssertionError("Test failed")


if __name__ == "__main__":
    run_test([1,3,5,6], 5, 2)
    run_test([1,3,5,6], 2, 1)
    run_test([1,3,5,6], 7, 4)
    run_test([1,3,5,6], 0, 0)
    run_test([1], 0, 0)
    run_test([1], 2, 1)
    run_test([], 3, 0)
    print("All tests passed!")
