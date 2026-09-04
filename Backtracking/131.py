class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []

        path = []

        start = 0

        def dfs(start):
            if start == len(s):
                res.append(path[:])
                return

            for end in range(start, len(s)):
                part  = s[start: end+1]
                #如果不是回文 跳過
                if part != part[::-1]:#反轉part
                    continue

                path.append(part[:]) #copy path
                dfs(end+1)
                path.pop() #這條路走完了 換下一條走

            return
        
        dfs(0)

        return res