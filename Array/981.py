from collections import defaultdict
from bisect import bisect_right

class TimeMap:
    def __init__(self):
        #自動幫你建立 list
        self.timestamps = defaultdict(list)  # key -> timestamps
        self.values = defaultdict(list)  # key -> values

    def set(self, key: str, value: str, timestamp: int) -> None:
        # timestamps 保證遞增，所以直接 append
        self.timestamps[key].append(timestamp)
        self.values[key].append(value)
        

    def get(self, key: str, timestamp: int) -> str:
        # key 不存在就回 ""
        if key not in self.timestamps:
            return ""
        

        # 找最後一個 <= timestamp
        # bisect_right 會回傳第一個 > timestamp 的位置
        idx = bisect_right(self.timestamps[key], timestamp) -1

        # idx 如果 < 0 回 ""
        if idx < 0:
            return ""

        # 否則回對應 value
        return self.values[key][idx]
    
# ===== 本機測試 =====
if __name__ == "__main__":
    tm = TimeMap()

    tm.set("foo", "bar", 1)
    print(tm.get("foo", 1), "expect bar")
    print(tm.get("foo", 3), "expect bar")

    tm.set("foo", "bar2", 4)
    print(tm.get("foo", 4), "expect bar2")
    print(tm.get("foo", 5), "expect bar2")

    print(tm.get("foo", 0), "expect ''")
    print(tm.get("nope", 10), "expect ''")

