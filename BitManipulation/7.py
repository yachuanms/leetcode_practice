class Solution:
    def reverse(self, x: int) -> int:
        #因python 處理負數很麻煩所以先把負號取出當正數處理

        #是否為正
        sign = 1 if x >= 0 else -1
        x = abs(x)

        ans = 0

        while x > 0:
            digit = x % 10
            x //= 10

            ans = ans * 10 + digit

        ans *= sign

        if ans < -(2**31) or ans > (2**31)-1:
            return 0

        return ans

        