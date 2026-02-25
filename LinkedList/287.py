from typing import List

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # TODO: 你寫
        s = set()

        for n in nums:
            if n in s:
                return n
            s.add(n)
        

        '''
        # Hint: 這題常見兩條路
        # 1) Floyd cycle detection (tortoise & hare)
        slow, fast = 0,0
        #Phase 1 快慢指針先找環相遇點
        while 1:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break
        p1 = 0
        p2 = slow
        while p1 != p2:
            p1 = nums[p1]
            p2 = nums[p2]
        
        return p1
        '''

        '''
        # 2) Binary search on answer (count <= mid 的單調性)
        left = 1
        right = len(nums)-1
        while left < right:
            count =0
            mid = (left+right)//2
            for n in nums:
                if n <= mid:
                    count+=1
            if count > mid:
                right = mid
            else:
                left = mid +1
        return left
        '''


def run_case(nums, expected):
    sol = Solution()
    got = sol.findDuplicate(nums)
    print("nums =", nums)
    print("got =", got, " expected =", expected)
    assert got == expected
    print("OK\n")


if __name__ == "__main__":
    # 基本
    run_case([1, 3, 4, 2, 2], 2)
    run_case([3, 1, 3, 4, 2], 3)

    # 重複出現多次
    run_case([2, 2, 2, 2, 2], 2)

    # 重複在尾/頭附近
    run_case([1, 4, 6, 2, 3, 5, 6], 6)