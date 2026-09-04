from typing import List

class Solution:
    def canAttendMeetings(self,intervals: List[List[int]]) -> bool:
        
        intervals.sort() #O(n log n)

        #O(n)
        for i in range(len(intervals)-1):
            if (intervals[i][1] > intervals[i+1][0]):
                return False
            
        return True

def main():
    sol = Solution()

    tests = [
        (
            [[0,30], [5,10], [15, 20]], False
        ),
        (
            [[7,10], [2,4], [15, 20]], True
        ),
        (
            [], True
        ),
        (
            [[1,2]], True
        ),
        (
            [[1,3], [2,4]], False
        )
    ]

    for intervals, expected in tests:
        result = sol.canAttendMeetings(intervals)

        print(f"intervals = {intervals}")
        print(f"result = {result}")
        print(f"expected = {expected}")
        print("PASS" if result == expected else "FAIL")
        print()

if __name__ == "__main__":
    main()
