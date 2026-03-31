class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        used = [False] * len(nums)

        def backtrack(path):
            # TODO:
            # 1. 什麼時候加入答案？
            # 2. for loop
            # 3. 跳過用過的
            # 4. append -> recurse -> pop
            if len(path) == len(nums):
                res.append(path[:])
                return
            for i in range(len(nums)):
                if used[i]:
                    continue
                path.append(nums[i])
                used[i] = True
                backtrack(path)
                path.pop()
                used[i] = False

        backtrack([])
        return res


if __name__ == "__main__":
    s = Solution()
    print(s.permute([1,2,3]))