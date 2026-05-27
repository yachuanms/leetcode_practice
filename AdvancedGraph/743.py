from typing import List
import heapq

#Dijkstra
class Solution:
    def networkDelayTime(
        self,
        times: List[List[int]],
        n: int,
        k: int
    ) -> int:

        # TODO 1:
        # build adjacency list
        # graph[u] = [(v, w)]
        graph = {}
        for i in range(n):
            graph[i+1] = []

        #weighted directed graph
        for a, b, time in times:
            graph[a].append([b, time])

        # TODO 2:
        # minHeap = [(time, node)]
        #到起點的時間是0
        minHeap = [(0, k)]


        # TODO 3:
        # visited set
        visited = set()
        res = 0

        # TODO 4:
        # Dijkstra
        while minHeap:
            # pop smallest time node
            cur_time, node = heapq.heappop(minHeap)
            
            if node in visited:
                continue

            visited.add(node)
            res = cur_time

            for nei, time in graph[node]:
                if nei not in visited:
                        if nei not in visited:
                            heapq.heappush(minHeap, (cur_time + time, nei))

        # TODO 5:
        # if not all nodes reached -> return -1
        return res if len(visited) == n else -1



def test_network_delay():
    s = Solution()

    print(
        s.networkDelayTime(
            [[2,1,1],[2,3,1],[3,4,1]],
            4,
            2
        )
    )
    # expected: 2

    print(
        s.networkDelayTime(
            [[1,2,1]],
            2,
            1
        )
    )
    # expected: 1

    print(
        s.networkDelayTime(
            [[1,2,1]],
            2,
            2
        )
    )
    # expected: -1


if __name__ == "__main__":
    
    test_network_delay()