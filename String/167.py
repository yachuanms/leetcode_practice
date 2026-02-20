class Solution:
    def twoSum(self, numbers, target):
        # TODO: 你寫
        left = 0
        right = len(numbers)-1
        if right < 2:
            return [1, 2]

        #為什麼不是left <= right？
        #當 left == right 時：
        #會變成同一個元素加自己。
        #題目保證是兩個不同 index
        while left < right:
            sum = numbers[left]+numbers[right]
            if sum == target:
                return [left+1, right+1]
            elif sum < target:
                left+=1
            else:
                right -= 1
        return [-1, -1]


def run_test(numbers, target, expected):
    sol = Solution()
    ans = sol.twoSum(numbers, target)
    print(f"numbers={numbers}, target={target}")
    print(f"  ans={ans}, expected={expected}  --> {'PASS' if ans == expected else 'FAIL'}")
    if ans != expected:
        raise AssertionError("Test failed")


if __name__ == "__main__":
    run_test([2,7,11,15], 9, [1,2])
    run_test([2,3,4], 6, [1,3])
    run_test([-1,0], -1, [1,2])
    run_test([1,2,3,4,4,9], 8, [4,5])
    print("All tests passed!")
