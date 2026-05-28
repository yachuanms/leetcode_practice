from typing import List
from collections import defaultdict


class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        #如果 key 不存在  預設 value 是 []
        graph = defaultdict(list)

        # TODO 1:
        # build graph
        for start, des in tickets:
            if start not in graph:
                graph[start] = []
            graph[start].append(des)
            

        # TODO 2:
        # sort each destination list in reverse order
        # 因為之後可以用 pop() 拿最小字典序
        for airport in graph:
            graph[airport].sort(reverse=True)

        route = []

        def dfs(airport):
            # TODO:
            # while graph[airport]:
            #     next_airport = graph[airport].pop()
            #     dfs(next_airport)
            while graph[airport]:
                next = graph[airport].pop()
                dfs(next)
            # TODO:
            # append airport to route after no outgoing edge left
            route.append(airport)
            return

        dfs("JFK")

        return route[::-1]#reverse
        #route是反著建立的