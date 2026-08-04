from typing import List
from collections import deque
import heapq

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        counts = {}
        heap = []
        #數每個task有幾次
        for task in tasks:
            counts[task] = counts.get(task, 0)+1

        #放進min heap中 --> 轉負數
        for count in counts.values():
            heapq.heappush(heap, -count)

        time = 0
        q = deque()

        while heap or q:
            time+=1
            if heap:
                count = heapq.heappop(heap)
                count += 1
                #如果還有count還沒歸0
                if count <0:
                    q.append((count, time+n))
            if q and q[0][1] == time:
                count, ava_time = q.popleft()
                #前面判斷過了所以不會有count > 0的
                heapq.heappush(heap, count)

        
        return time


# -------------------------
# Testing
# -------------------------

def main():
    sol = Solution()

    test_cases = [
        (["A","A","A","B","B","B"], 2, 8),
        (["A","A","A","B","B","B"], 0, 6),
        (["A","A","A","A","B","C","D","E"], 2, 10),
        (["A","A","A","B","B","B","C","C"], 2, 8),
    ]

    for tasks, n, expected in test_cases:
        result = sol.leastInterval(tasks, n)
        print(f"tasks={tasks}, n={n}")
        print(f"Output   = {result}")
        print(f"Expected = {expected}")
        print("-" * 40)


if __name__ == "__main__":
    main()