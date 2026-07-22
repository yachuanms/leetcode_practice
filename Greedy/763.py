from typing import List


class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        # TODO: 記錄每個字母最後一次出現的位置
        last = {}

        for i in range(len(s)):
            last[s[i]] = i

        ans = []
        end = 0
        start = 0
        
        # TODO: Greedy 掃描字串
        for i in range(len(s)):
            end = max(end, last[s[i]])
            #如果end == i: 這一段需要包含的所有字母，都已經走完了
            if end == i:
                ans.append(end-start+1)
                start = end+1
                
        # TODO: 回傳每段長度
        return ans


# -------------------------
# Testing
# -------------------------

def main():
    sol = Solution()

    test_cases = [
        ("ababcbacadefegdehijhklij", [9, 7, 8]),
        ("eccbbbbdec", [10]),
        ("abc", [1, 1, 1]),
        ("aaaaa", [5]),
        ("abac", [3, 1]),
    ]

    for s, expected in test_cases:
        result = sol.partitionLabels(s)

        print(f"s        = {s}")
        print(f"Output   = {result}")
        print(f"Expected = {expected}")
        print("-" * 40)


if __name__ == "__main__":
    main()