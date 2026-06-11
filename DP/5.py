class Solution:
    def longestPalindrome(self, s: str) -> str:

        result = ""
        resultLen = 0

        for i in range(len(s)):

            # odd length
            left = i
            right = i
            while left >= 0 and right < len(s) and s[left] == s[right]:
                if right - left +1 > resultLen:
                    resultLen = right - left +1
                    result = s[left:right+1]
                    #print("odd", result)
                left -= 1
                right +=1
            # even length
            left = i
            right = i + 1
            while left >= 0 and right < len(s) and s[left] == s[right]:
                if right - left +1 > resultLen:
                    resultLen = right - left +1
                    result = s[left:right+1]
                    #print("even", result)
                left -= 1
                right +=1

        return result


def main():
    sol = Solution()

    test_cases = [
        ("babad", {"bab", "aba"}),
        ("cbbd", {"bb"}),
        ("a", {"a"}),
        ("ac", {"a", "c"}),
        ("racecar", {"racecar"}),
    ]

    for s, expected in test_cases:
        result = sol.longestPalindrome(s)

        print(f"s = {s}")
        print(f"Got = {result}")
        print("PASS" if result in expected else "FAIL")
        print("-" * 40)


if __name__ == "__main__":
    main()