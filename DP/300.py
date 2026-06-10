from typing import List

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:

        # define dp
        n = len(nums)
        DP = [1] * (n)

        # fill dp
        for i in range(n):
            for j in range(i):
                if nums[j] < nums[i]:
                    DP[i] = max(DP[i], DP[j]+1)

        # return answer
        #不一定DP[n-1]是最長的subsequence!!!
        return max(DP)


def main():
    sol = Solution()

    test_cases = [
        ([10,9,2,5,3,7,101,18], 4),
        ([0,1,0,3,2,3], 4),
        ([7,7,7,7,7], 1),
        ([1,3,6,7,9,4,10,5,6], 6),
    ]

    for nums, expected in test_cases:
        result = sol.lengthOfLIS(nums)

        print(f"nums = {nums}")
        print(f"Expected = {expected}")
        print(f"Got = {result}")
        print("PASS" if result == expected else "FAIL")
        print("-" * 40)


if __name__ == "__main__":
    main()