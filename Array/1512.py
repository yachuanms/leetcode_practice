class Solution:
    def numIdenticalPairs(self, nums: list[int]) -> int:
        #use a hashMap to record all the num's index
        #key: num, value: index shown
        shown = {}
        for i, num in enumerate(nums):
            if num not in shown:
                shown[num] = []
            shown[num].append(i)

        #calculate good pairs
        count = 0

        for idx_list in shown.keys():
            count += len(shown[idx_list])*(len(shown[idx_list])-1)//2

        return count

