class Solution:
    def getSum(self, a: int, b: int) -> int:
        #Python負數前面會有無限個1
        #所以這邊只取32bit
        #32-bit pattern
        MASK = 0xFFFFFFFF
        MAX_INT = 0x7FFFFFFF #Python 32-bit signed integer最大數
        #最高位是1代表負數

        a&= MASK
        b&= MASK

        while b != 0:
            new_sum = (a ^ b) & MASK
            new_carry = ((a & b) <<1) & MASK

            a = new_sum
            b = new_carry

        if a <= MAX_INT:
            return a
    
        #是負數 反轉bit再轉成真的負數
        # ~x == -x - 1
        #^ MASK 先反轉一次 bit，~ 再反轉一次，回到負數；
        #只是第二次反轉不是 32 位元了
        return ~(a ^ MASK) 
        #把「32-bit pattern 代表的負數」轉成 Python 真正的負整數

