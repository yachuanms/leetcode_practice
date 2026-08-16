class Solution:
    def reverseBits(self, n: int) -> int:

        res = 0

        for i in range(32):
            bit = n&1 #取最右位
            n>>=1 #右移
						#第一次寫我先|才<<=1 這樣會多一位變33位數
						#用小點的範例自己做做看
            res <<= 1 #左移
            res |= bit #放到最左
            
        return res
        