class Solution:
    def countBits(self, n: int) -> List[int]:
        ans = [0]*(n+1)

        for i in range(1, n+1):
            ans[i] = ans[i>>1]+(i&1)
            #取出最右邊的數字 (i&1)
            #ans[i>>1] -> 踢掉最右邊, 剩下的數字已經算過了!!
            #eg. 5 = 101, 5&1 = 1(個位數), 5>>1 = 2 (10)

        return ans
        