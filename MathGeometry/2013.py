from typing import List

class DetectSquares:

    def __init__(self):
        self.counts = {}
        

    def add(self, point: List[int]) -> None:
        point = tuple(point)
        self.counts[point] = self.counts.get(point, 0)+1
        

    def count(self, point: List[int]) -> int:
        x, y = point
        ans = 0
        for (x2, y2), time in self.counts.items():
            #找是不是對角點
            if x-x2 != 0 and abs(x-x2) == abs(y-y2):
                #看有幾種排列組合
                pt2 = self.counts.get((x2, y2), 0)
                pt3 = self.counts.get((x, y2), 0)
                pt4 = self.counts.get((x2, y), 0)

                ans += pt2*pt3*pt4

        return ans

        


# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)