class Solution:
    def subarraySum(self, nums, k):
        # TODO: 你寫
        hashMap = dict()
        n = len(nums)
        prefix = 0
        count = 0
        #正確初始化!!!!!!
        hashMap[0] = 1
        for i in range (n):
            prefix += nums[i]
            if prefix - k in hashMap:
                count += hashMap[prefix-k]
            #安全讀法d.get(key, default_value)
            hashMap[prefix] = hashMap.get(prefix, 0)+1
        return count


def run_test(nums, k, expected):
    sol = Solution()
    ans = sol.subarraySum(nums, k)
    print(f"nums={nums}, k={k}")
    print(f"  ans={ans}, expected={expected}  --> {'PASS' if ans == expected else 'FAIL'}")
    if ans != expected:
        raise AssertionError("Test failed")


if __name__ == "__main__":
    run_test([1,1,1], 2, 2)
    run_test([1,2,3], 3, 2)          # [1,2], [3]
    run_test([1,-1,0], 0, 3)         # [1,-1], [0], [1,-1,0]
    run_test([0,0,0], 0, 6)          # 3*4/2
    run_test([], 0, 0)
    print("All tests passed!")