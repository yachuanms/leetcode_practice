from typing import List
import heapq


class Solution:
    #Minimum spanning tree
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)

        total_cost = 0
        visited = set()

        minHeap = [(0, 0)] #cost, point_index

        #Prim
        #heap放把node加進tree要花多少成本
        while len(visited) < n:
            cost, i = heapq.heappop(minHeap)

            if i in visited:
                continue

            visited.add(i)
            total_cost += cost

            for j in range(n):
                if j not in visited:
                    #Manhattan distance abs(x1-x2)+abs(y1-y2)
                    dis = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])
                    heapq.heappush(minHeap, (dis, j))

        return total_cost


def test_min_cost_connect_points():
    s = Solution()

    print(s.minCostConnectPoints([[0,0],[2,2],[3,10],[5,2],[7,0]]))
    # expected: 20

    print(s.minCostConnectPoints([[3,12],[-2,5],[-4,1]]))
    # expected: 18


if __name__ == "__main__":
    test_min_cost_connect_points()