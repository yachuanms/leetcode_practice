class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        l = 0
        table = set()
        max_count = 0
        for r in range(len(s)):
            while s[r] in table:
                table.remove(s[l])
                l+=1
            table.add(s[r])
            max_count = max_count = max(max_count, r - l + 1)
        return max_count
            

