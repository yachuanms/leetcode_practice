class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []

        def backtrack(start, path):
            # TODO
            #👉 path[:]複製一份新的 list（copy）
            res.append(path[:])
            for i in range(start, len(nums)):
                path.append(nums[i])
                backtrack(i+1, path)
                path.pop()


        backtrack(0, [])
        return res


# testing
if __name__ == "__main__":
    s = Solution()
    print(s.subsets([1,2,3]))