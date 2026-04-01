class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        res = []

        def backtrack(start, path):
            # 1. 先加入答案
            # 2. for loop
            # 3. 同層跳過重複
            # 4. append -> recurse -> pop
            res.append(path[:])
            for i in range(start, len(nums)):
                if i > start and nums[i] == nums[i-1]:
                    continue
                path.append(nums[i])
                backtrack(i+1, path)
                path.pop()

        backtrack(0, [])
        return res


if __name__ == "__main__":
    s = Solution()

    print(s.subsetsWithDup([1,2,2]))
    # expected: [[], [1], [1,2], [1,2,2], [2], [2,2]]

    print(s.subsetsWithDup([0]))
    # expected: [[], [0]]