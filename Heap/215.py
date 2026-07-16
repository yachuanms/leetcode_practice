from typing import List
import heapq


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:

        heap = []

        for i in range(len(nums)):
            if (len(heap)< k):
                heapq.heappush(heap, nums[i])
            else:
                if(nums[i] > heap[0]):
                    heapq.heappop(heap)
                    heapq.heappush(heap, nums[i])

        return heap[0]



# -------------------------
# Testing
# -------------------------

def main():
    sol = Solution()

    test_cases = [
        ([3,2,1,5,6,4], 2, 5),
        ([3,2,3,1,2,4,5,5,6], 4, 4),
        ([1], 1, 1),
        ([7,6,5,4,3,2,1], 3, 5),
    ]

    for nums, k, expected in test_cases:
        result = sol.findKthLargest(nums, k)
        print(f"nums     = {nums}")
        print(f"k        = {k}")
        print(f"Output   = {result}")
        print(f"Expected = {expected}")
        print("-" * 30)


if __name__ == "__main__":
    main()