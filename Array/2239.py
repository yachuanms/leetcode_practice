class Solution(object):
    def findClosestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        minD = 100001
        index =0
        for i in range(len(nums)):
            absnum = abs(nums[i])
            if absnum < minD:
                minD = absnum
                index = i
            if absnum == minD:
                if nums[index]< nums[i]:
                    index = i

        return nums[index]
        