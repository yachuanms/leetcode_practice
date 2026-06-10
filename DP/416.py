from typing import List

#有沒有辦法把數字分成兩組總和一樣?

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        # total sum
        total = sum(nums)

        # if total is odd, return False
        if total%2 == 1:
            return False

        # target = total // 2
        target = total // 2

        # dp[i] = whether we can form sum i
        DP = [False] * (target+1)

        # base case
        DP[0] = True

        # fill dp
        for num in nums:
            #倒著跑 因為正著跑會重複用數字
            #這輪剛湊出的數字(剛變成True)然後馬上又被用
            for i in range(target, num - 1, -1):
                if DP[i-num]:
                    DP[i] = True

        # return answer
        return DP[target]


def main():
    sol = Solution()

    test_cases = [
        ([1, 5, 11, 5], True),
        ([1, 2, 3, 5], False),
        ([1, 2, 5], False),
        ([2, 2, 1, 1], True),
        ([100], False),
    ]

    for nums, expected in test_cases:
        result = sol.canPartition(nums)

        print(f"nums = {nums}")
        print(f"Expected = {expected}")
        print(f"Got = {result}")
        print("PASS" if result == expected else "FAIL")
        print("-" * 40)


if __name__ == "__main__":
    main()