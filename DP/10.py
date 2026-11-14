from functools import cache
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        sLen = len(s)
        pLen = len(p)

        @cache #記住每組 (i, j) 的結果
        def dfs(i, j):
            #Base case: pattern用完了 只要s也用完就true
            if j == pLen:
                return i == sLen

            #匹配兩字元
            first_match = (i<sLen and (s[i]==p[j] or p[j]=="."))

            #若下一個pattern 是 *
            if j < pLen-1 and p[j+1] == "*":
                #匹配一次(s+1, p不動繼續配) or 匹配0次
                return (first_match and dfs(i+1, j)) or dfs(i, j+2)
            else:
                #沒*匹配 s+1, p+1
                return first_match and dfs(i+1, j+1)

        return dfs(0,0)
            