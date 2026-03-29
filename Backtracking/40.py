class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res =[]
        #和39不同的地方!!!
        candidates.sort()
        def backtrack(start, path, total):
            if total == target:
                res.append(path[:])
                return
            if total > target:
                return
            for i in range(start, len(candidates)):
                if i > start and candidates[i] == candidates[i - 1]:
                    continue
                path.append(candidates[i])
                backtrack(i+1, path, total+candidates[i])
                path.pop()
        
        backtrack(0, [], 0)
        return res


if __name__ == "__main__":
    s = Solution()

    print(s.combinationSum2([10,1,2,7,6,1,5], 8))
    # expected: [[1,1,6],[1,2,5],[1,7],[2,6]]

    print(s.combinationSum2([2,5,2,1,2], 5))
    # expected: [[1,2,2],[5]]