from typing import List

class Solution:
    def findCheapestPrice(
        self,
        n: int,
        flights: List[List[int]],
        src: int,
        dst: int,
        k: int
    ) -> int:
        INF = float("inf")

        prices = [INF]*n
        prices[src] = 0

        #Bellman-Ford
        #跑k次 每輪可用k條邊 
        #(k 中繼站 == k+1條邊)
        for _ in range(k+1):

            temp = prices.copy()

            for start, end, cost in flights:
                if prices[start] == INF:
                    continue

                temp[end] = min(temp[end], prices[start]+cost)

            prices = temp

        return prices[dst] if prices[dst] != INF else -1

                