class Solution:
    def minimumSteps(self, s: str) -> int:
        #算每個0左邊有幾個1 -> 要跨過的黑球
        black_count = 0
        steps = 0

        for ball in s:
            if ball == "1":
                black_count += 1
            else:
                steps += black_count

        return steps