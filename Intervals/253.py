from typing import List
import heapq

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:

        if not intervals:
            return 0

        intervals.sort()

        room_end = []
        heapq.heappush(room_end, intervals[0][1])

        for i in range(1, len(intervals)):
            #如果最早結束的會議室比下場會議早結束
            # --> 這間會議室繼續安排下場會議
            if room_end[0] <= intervals[i][0]:
                heapq.heappop(room_end)
                #更新會議室結束時間
                heapq.heappush(room_end, intervals[i][1])
            else:
                heapq.heappush(room_end, intervals[i][1])


        return len(room_end)
            


if __name__ == "__main__":
    solution = Solution()

    # 測試範例 1
    # 解釋：[0, 30] 與 [5, 10] 重疊，[5, 10] 結束後 [15, 20] 開始。最少需要 2 間會議室。
    intervals1 = [[0, 30], [5, 10], [15, 20]]
    expected1 = 2
    result1 = solution.minMeetingRooms(intervals1)
    print(f"測試範例 1 結果: {result1} (預期值: {expected1})")

    # 測試範例 2
    # 解釋：兩個會議時間完全錯開，1 間會議室即可。
    intervals2 = [[7, 10], [2, 4]]
    expected2 = 1
    result2 = solution.minMeetingRooms(intervals2)
    print(f"測試範例 2 結果: {result2} (預期值: {expected2})")

    # 測試範例 3 (額外邊界測試)
    # 解釋：多個會議在同一時間重疊，或是剛好銜接（例如一個在 5 結束，另一個在 5 開始，通常算不重疊）
    intervals3 = [[1, 5], [5, 10], [2, 6]]
    expected3 = 2
    result3 = solution.minMeetingRooms(intervals3)
    print(f"測試範例 3 結果: {result3} (預期值: {expected3})")
