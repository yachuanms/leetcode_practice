class Solution:
    def hammingWeight(self, n: int) -> int:
        bit = 0

        while n > 0:
            #bit += n%2
            #n//=2
						#等價
            bit += n&1 #取得最右邊
            n >>= 1  #去掉最右邊
        
        #return bin(n).count("1")
        return bit
        