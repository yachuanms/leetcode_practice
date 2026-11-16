#Create Grid With Exactly One Path (Easy)

class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        ans = []
        
        for i in range(m):
            path = []
            for j in range(n):
                if i == 0 or j== n-1:
                    path.append(".")
                else:
                    path.append("#")
            ans.append("".join(path))

        return ans