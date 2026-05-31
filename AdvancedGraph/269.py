from typing import List
from collections import defaultdict

#給一串字母以按照設定的順序排列好
#試問順序為何

class Solution:
    def alienOrder(self, words: List[str]) -> str:

        #1. build graph
        graph = defaultdict(list)
        for word in words:
            for char in word:
                graph[char]

        #2. build directed edges
        for i in range(len(words)-1):
            w1 = words[i]
            w2 = words[i+1]

            min_len = min(len(w1), len(w2))
            #"abc", "ab" -> 不合法 return
            if len(w1) > len(w2) and w1[:min_len] == w2[:min_len]:
                return ""
            
            for j in range(min_len):
                if w1[j] != w2[j]:
                    graph[w1[j]].append(w2[j])
                    break #只有第一個不一樣能比

        visited = {}
        #True -> visiting
        #False -> visited

        order = []

        #判斷有沒有cycle
        def dfs(char):
            #cycle detection
            if char in visited:
                return visited[char]
            
            visited[char] =  True

            for nei in graph[char]:
                if dfs(nei): #visiting -> Cycle
                    return True
            
            visited[char] = False

            order.append(char)
            return False
        
        for char in graph:
            if dfs(char):
                return ""
            
        return "".join(order[::-1])


    
if __name__ == "__main__":
    s = Solution()
    print(s.alienOrder(["wrt", "ert", "bkt", "yqz"]))