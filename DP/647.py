class Solution:
    def countSubstrings(self, s: str) -> int:

        count = 0

        for i in range(len(s)):

            # odd length
            left = i
            right = i
            
            while left >= 0 and right < len(s) and s[left]== s[right]:
                count+=1
                left -= 1
                right +=1

            # even length
            left = i
            right = i + 1
            
            while left >= 0 and right < len(s) and s[left]== s[right]:
                count+=1
                left -= 1
                right +=1

        return count


def main():
    sol = Solution()

    test_cases = [
        ("abc", 3),
        ("aaa", 6),
        ("aba", 4),
        ("abba", 6),
        ("a", 1),
    ]

    for s, expected in test_cases:
        result = sol.countSubstrings(s)

        print(f"s = {s}")
        print(f"Expected = {expected}")
        print(f"Got = {result}")
        print("PASS" if result == expected else "FAIL")
        print("-" * 40)


if __name__ == "__main__":
    main()