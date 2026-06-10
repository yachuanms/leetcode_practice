from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:

        # convert wordDict to set for faster lookup
        wordSet = set(wordDict)
        #if "leet" in wordSet  -> O(1)
        #if "leet" in wordDict -> O(n)

        # define dp
        sLen = len(s)
        DP = [False] * (sLen+1)
        
        #DP[i] = s前i個字(s[0:i])可不可以成功切
        # base case
        DP[0] = True

        # fill dp
        for i in range(1, sLen+1):
            for j in range(i):
                if DP[j] and s[j:i] in wordSet:
                    DP[i] = True
                    break

        # return answer

        return DP[sLen]


def main():
    sol = Solution()

    test_cases = [
        ("leetcode", ["leet", "code"], True),
        ("applepenapple", ["apple", "pen"], True),
        ("catsandog", ["cats", "dog", "sand", "and", "cat"], False),
        ("aaaaaaa", ["aaaa", "aaa"], True),
        ("cars", ["car", "ca", "rs"], True),
    ]

    for s, wordDict, expected in test_cases:
        result = sol.wordBreak(s, wordDict)

        print(f"s = {s}")
        print(f"wordDict = {wordDict}")
        print(f"Expected = {expected}")
        print(f"Got = {result}")
        print("PASS" if result == expected else "FAIL")
        print("-" * 40)


if __name__ == "__main__":
    main()