from typing import List


class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:

        total = sum(nums)

        #不能是奇數
        if (total+target)%2 != 0:
            return 0

        #湊不出來
        if abs(target) > total:
            return 0

        # P = (total + target)/2 -> float 
        # P = (total + target)//2 -> int
        # 後面range, DP[P] 那些不能用float去用 即使P = 4.0 也不行
        # Python type的問題
        #要湊P

        #P+N = total
        #P-N = target
        #-> 2P = (total+target)
        P = (total+target)//2

        #DP table
        #DP[i] = sum i 的方法數
        DP = [0] * (P+1)

        #Base Case
        DP[0] = 1

        #倒著跑 因為正著跑會重複用數字
        #這輪剛湊出的數字(剛變成True)然後馬上又被用
        for num in nums:
            for i in range(P, num-1, -1):
                DP[i] += DP[i-num]

        return DP[P]
