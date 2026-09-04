from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ans = []
        left = 0
        right = len(matrix[0]) - 1
        top = 0
        bottom = len(matrix) - 1

        while left <= right and top <= bottom:
		        # 上
            for i in range(left, right+1):
                ans.append(matrix[top][i])
                
            top+=1
						
						#右
            for i in range(top, bottom+1):
                ans.append(matrix[i][right])
            
            right-=1
						
						#下
						#如果走完了可能會重走 所以要先檢查邊界
            if top <= bottom:
                for i in range(right, left-1, -1):
                    ans.append(matrix[bottom][i])
                
            bottom -= 1
						
						#左
            if left <= right:
                for i in range(bottom, top-1, -1):
                    ans.append(matrix[i][left])

            left += 1

        return ans