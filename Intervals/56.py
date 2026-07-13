from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:

        #排序 用第0位
        intervals.sort(key=lambda x: x[0])

        answers = []

        answers.append(intervals[0])

        for i in range(1, len(intervals)):
        #[1,3],[2,6] -> [1,6]
            if answers[-1][1] >= intervals[i][0]:
                answers[-1][1] = max(answers[-1][1], intervals[i][1])
            else:
                answers.append(intervals[i])

        return answers
# -------------------------
# Testing
# -------------------------

def main():
    sol = Solution()

    test_cases = [
        ([[1,3],[2,6],[8,10],[15,18]],
         [[1,6],[8,10],[15,18]]),

        ([[1,4],[4,5]],
         [[1,5]]),

        ([[1,4],[2,3]],
         [[1,4]]),

        ([[1,4],[5,6]],
         [[1,4],[5,6]]),

        ([[2,3],[4,5],[6,7],[8,9],[1,10]],
         [[1,10]])
    ]

    for intervals, expected in test_cases:
        ans = sol.merge(intervals)
        print(f"Input    : {intervals}")
        print(f"Output   : {ans}")
        print(f"Expected : {expected}")
        print("-" * 40)


if __name__ == "__main__":
    main()