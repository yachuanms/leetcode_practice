import heapq
class MedianFinder:

    def __init__(self):
        #left side: max heap (store neg num cause Python heap is min heap)
        #right side: min heap
        self.right = []
        self.left = []

    def addNum(self, num: int) -> None:
        if not self.left:
            heapq.heappush(self.left, -num)
            return
        #insert 
        left_max = -self.left[0] #turn back to pos value
        if num <= left_max:
            heapq.heappush(self.left, -num)
        else:
            heapq.heappush(self.right, num)
        #rebalance (Keep the heap sizes within 1 of each other)
        if abs(len(self.left)-len(self.right)) > 1:
            if len(self.left) > len(self.right):
                left_max = heapq.heappop(self.left)
                heapq.heappush(self.right, -left_max)
            else:
                right_min = heapq.heappop(self.right)
                heapq.heappush(self.left, -right_min)

    def findMedian(self) -> float:
        # length is odd -> rtn the middle one
        if (len(self.left) + len(self.right))%2 == 1:
            return -self.left[0] if len(self.left) > len(self.right) else self.right[0]
        # legth is even -> rtn the mean of the two middle values
        else:
            return (self.right[0]- self.left[0])/2 


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()

def main():
    mf = MedianFinder()

    mf.addNum(1)
    print(mf.findMedian())  # 1.0

    mf.addNum(2)
    print(mf.findMedian())  # 1.5

    mf.addNum(3)
    print(mf.findMedian())  # 2.0

    mf.addNum(4)
    print(mf.findMedian())  # 2.5


if __name__ == "__main__":
    main()