from typing import List
import heapq


class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # TODO: convert stones into a max heap using negative values
        stones = [-x for x in stones]

        heapq.heapify(stones)

        # TODO: repeatedly remove the two heaviest stones
        while(len(stones)>1):
            one = heapq.heappop(stones)
            two = heapq.heappop(stones)

            diff = abs(one - two)

            if (diff):
                heapq.heappush(stones, diff*(-1))

        return (stones[0])*(-1) if stones else 0


# -------------------------
# Testing
# -------------------------

def main():
    sol = Solution()

    test_cases = [
        ([2, 7, 4, 1, 8, 1], 1),
        ([1], 1),
        ([2, 2], 0),
        ([3, 7, 2], 2),
        ([10, 4, 2, 10], 2),
        ([], 0),
    ]

    for stones, expected in test_cases:
        result = sol.lastStoneWeight(stones.copy())

        print(f"stones   = {stones}")
        print(f"Output   = {result}")
        print(f"Expected = {expected}")
        print("-" * 30)


if __name__ == "__main__":
    main()