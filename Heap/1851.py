import heapq


class Solution:
    def minInterval(self, intervals: list[list[int]], queries: list[int]) -> list[int]:
        sorted_queries = sorted(enumerate(queries), key=lambda x: x[1])
        intervals.sort()

        heap = []
        ans = [-1] * len(queries)
        interval_idx = 0

        for query_idx, query in sorted_queries:
            # Add all intervals that have started
            while (
                interval_idx < len(intervals)
                and intervals[interval_idx][0] <= query
            ):
                left, right = intervals[interval_idx]
                length = right - left + 1
                heapq.heappush(heap, (length, right))
                interval_idx += 1

            # Remove expired intervals from the top
            while heap and heap[0][1] < query:
                heapq.heappop(heap)

            if heap:
                ans[query_idx] = heap[0][0]

        return ans