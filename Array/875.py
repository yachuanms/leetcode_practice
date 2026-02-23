class Solution:
    def minEatingSpeed(self, piles, h):
        # TODO: 你寫
        left = 1
        '''
        max = 0
        for i in range (n):
            if piles[i] > max:
                max = piles[i]
        '''
        max_piles = max(piles)
        right = max_piles
        #區間縮到只剩 1 個
        #找邊界 不是找值
        while left < right:
            mid = (left+right)//2
            time = 0
            for p in piles:
                time += (p+mid-1)//mid
            #太慢
            if time > h:
                left = mid+1
            #太快
            else:
                #最小可行
                right = mid
                #最大可行
                #mid = (l+r+1)//2  left = mid
        return left


def run_test(piles, h, expected):
    sol = Solution()
    ans = sol.minEatingSpeed(piles, h)
    print(f"piles={piles}, h={h}")
    print(f"  ans={ans}, expected={expected}  --> {'PASS' if ans == expected else 'FAIL'}")
    if ans != expected:
        raise AssertionError("Test failed")


if __name__ == "__main__":
    run_test([3,6,7,11], 8, 4)
    run_test([30,11,23,4,20], 5, 30)
    run_test([30,11,23,4,20], 6, 23)
    run_test([1,1,1,1], 4, 1)
    print("All tests passed!")