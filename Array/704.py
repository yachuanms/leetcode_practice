def search(self, nums, target):

    left = 0
    right = len(nums)-1
    
    while left <= right:
        mid = (left + right)//2
        if nums[mid] == target:
            return mid
        elif nums[mid] > target:
            right = mid-1
        else:
            left = mid +1
    return -1


def run_test(nums, target, expected):
    ans = search(nums, target)
    print(f"nums={nums}, target={target}")
    print(f"  ans={ans}, expected={expected}  --> {'PASS' if ans == expected else 'FAIL'}")
    if ans != expected:
        raise AssertionError("Test failed")


if __name__ == "__main__":
    run_test([-1,0,3,5,9,12], 9, 4)
    run_test([-1,0,3,5,9,12], 2, -1)
    run_test([1], 1, 0)
    run_test([1], 0, -1)
    run_test([1,2,3,4,5], 1, 0)
    run_test([1,2,3,4,5], 5, 4)
    run_test([1,2,3,4,5], 3, 2)
    print("All tests passed!")
