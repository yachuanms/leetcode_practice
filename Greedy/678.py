class Solution:
    def checkValidString(self, s: str) -> bool:
        left = []
        star = []

        for i in range(len(s)):
            if s[i] == '(':
                left.append(i)
            elif s[i] == '*':
                star.append(i)
            else:
                if left:
                    left.pop()
                elif star:
                    star.pop()

                else:
                    return False
        
        while left and star:
            if left[-1] < star[-1]:
                left.pop()
                star.pop()
            else:
                return False

        return False if left else True