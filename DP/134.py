from typing import List


class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        # 如果總油量不足，直接不可能
        if sum(gas) < sum(cost):
            return -1

        start = 0
        tank = 0

        for i in range(len(gas)):
            # TODO:
            # 把第 i 站取得的油與前往下一站的消耗，
            # 加入目前油箱 tank
            tank += gas[i]-cost[i]

            # TODO:
            # 如果 tank 變成負數：
            # 1. start 到 i 都不可能是答案
            # 2. 更新新的 start
            # 3. 重設 tank
            if tank < 0:
                start = i+1
                tank = 0

        return start


# -------------------------
# Testing
# -------------------------

def main():
    sol = Solution()

    test_cases = [
        (
            [1, 2, 3, 4, 5],
            [3, 4, 5, 1, 2],
            3,
        ),
        (
            [2, 3, 4],
            [3, 4, 3],
            -1,
        ),
        (
            [5],
            [4],
            0,
        ),
        (
            [1],
            [2],
            -1,
        ),
        (
            [3, 1, 1],
            [1, 2, 2],
            0,
        ),
    ]

    for gas, cost, expected in test_cases:
        result = sol.canCompleteCircuit(gas, cost)

        print(f"gas      = {gas}")
        print(f"cost     = {cost}")
        print(f"Output   = {result}")
        print(f"Expected = {expected}")
        print("-" * 40)


if __name__ == "__main__":
    main()