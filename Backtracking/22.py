class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        # path is sting 所以不用pop 
        #回到上一層會自己回到原本的path
        def backtrack(path, left, right):
            #base case
            if len(path) == 2*n:
                res.append(path)
                return
            if left < n:
                backtrack(path+"(", left+1, right)
            if right < left:
                backtrack(path+")", left, right+1)
            
        backtrack("", 0, 0)
        return res

if __name__ == "__main__":
    s = Solution()
    print(s.generateParenthesis(3))