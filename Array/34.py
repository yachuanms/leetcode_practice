class Solution:
    #O(log n)
    def searchRange(self, nums, target):
        # TODO: 你寫 
        #找第一個 >= target (邊界)
        def lower_bound(x):
            left = 0
            right = len(nums)

            while left < right:
                mid = (left+right)//2
                #讓他往左收 找最左(小)的target
                if nums[mid] >= x:
                    right = mid
                else: 
                    left = mid +1
            return left
        #找第一個 > target (邊界)
        def upper_bound(x):
            left = 0
            right = len(nums)
            while left < right:
                mid = (left+right)//2
                if nums[mid] <= x:
                    left = mid +1
                else:
                    right = mid 
            return left
        
        start = lower_bound(target)
        if start >= len(nums) or nums[start] != target:
            return [-1, -1]
        end = upper_bound(target)-1
        return [start, end]

    
# O(n) too slow
'''
class Solution:
    def searchRange(self, nums, target):
        # TODO: 你寫
        left = 0
        right = len(nums)-1

        while left <= right:
            mid = (left+right)//2
            if nums[mid] == target:
                start = mid
                end = mid
                while start >= 1 and nums[start-1] == target:
                    start-= 1
                while end+1 < len(nums) and nums[end+1] == target:
                    end += 1
                return [start, end]
            elif nums[mid] > target:
                right = mid -1
            else: 
                left = mid +1

        return [-1,-1]
'''
            


def run_test(nums, target, expected):
    sol = Solution()
    ans = sol.searchRange(nums, target)
    print(f"nums={nums}, target={target}")
    print(f"  ans={ans}, expected={expected}  --> {'PASS' if ans == expected else 'FAIL'}")
    if ans != expected:
        raise AssertionError("Test failed")


if __name__ == "__main__":
    run_test([5,7,7,8,8,10], 8, [3,4])
    run_test([5,7,7,8,8,10], 6, [-1,-1])
    run_test([], 0, [-1,-1])
    run_test([1], 1, [0,0])
    run_test([2,2], 2, [0,1])
    print("All tests passed!")
