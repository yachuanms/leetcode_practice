class Solution:
    def isHappy(self, n: int) -> bool:
        showed = set()

        while n not in showed:
            temp = 0
            showed.add(n)
            while n > 0:
                digit  = n%10
                temp += digit**2
                n//= 10
            if temp == 1:
                return True
            n = temp
            
        return False
        

        



        