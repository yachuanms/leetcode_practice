class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        #先沿對角線transpose 
        n = len(matrix)

        for i in range(n):
            #只處理主對角線其中一側，避免 (i,j) 和 (j,i) 交換兩次又換回原樣
            for j in range(i+1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        #再對row reverse
        for i in range(n):
            matrix[i].reverse()
        
        return