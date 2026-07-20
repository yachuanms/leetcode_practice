from typing import List
import heapq


class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        # TODO
        heap = []

        for i in range(len(points)):

            dis2 = points[i][0]**2+points[i][1]**2

            if (len(heap))<k:
                heapq.heappush(heap, (-dis2, i))

            else:
                if(-heap[0][0] > dis2):
                    heapq.heappop(heap)
                    heapq.heappush(heap, (-dis2, i))

        ans = []

        for _, idx in heap:
            ans.append(points[idx])

        return ans

# -------------------------
# Testing
# -------------------------

def main():
    sol = Solution()

    test_cases = [
        (
            [[1, 3], [-2, 2]],
            1,
            [[-2, 2]]
        ),
        (
            [[3, 3], [5, -1], [-2, 4]],
            2,
            [[3, 3], [-2, 4]]
        ),
        (
            [[0, 1], [1, 0]],
            2,
            [[0, 1], [1, 0]]
        ),
        (
            [[1, 1], [2, 2], [3, 3]],
            1,
            [[1, 1]]
        ),
    ]

    for points, k, expected in test_cases:
        result = sol.kClosest(points, k)

        # 因為答案順序不限，所以排序後再比較
        result_sorted = sorted(result)
        expected_sorted = sorted(expected)

        print(f"points   = {points}")
        print(f"k        = {k}")
        print(f"Output   = {result_sorted}")
        print(f"Expected = {expected_sorted}")
        print("-" * 40)


if __name__ == "__main__":
    main()