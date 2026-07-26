from typing import List


class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:

        remove = 0
        intervals.sort(key=lambda x: x[1])

        end = intervals[0][1]

        for i in range(1, len(intervals)):
            if (intervals[i][0]<end):
                remove+=1
            else:
                end = intervals[i][1]


        return remove


# -------------------------
# Testing
# -------------------------

def main():
    sol = Solution()

    test_cases = [
        ([[1,2],[2,3],[3,4],[1,3]], 1),
        ([[1,2],[1,2],[1,2]], 2),
        ([[1,2],[2,3]], 0),
        ([[1,100],[11,22],[1,11],[2,12]], 2),
    ]

    for intervals, expected in test_cases:
        result = sol.eraseOverlapIntervals(intervals)

        print(f"intervals = {intervals}")
        print(f"Output    = {result}")
        print(f"Expected  = {expected}")
        print("-" * 40)


if __name__ == "__main__":
    main()