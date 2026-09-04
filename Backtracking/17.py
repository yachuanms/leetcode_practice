from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:

        phone = {
            "2": "abc",
            "3": "def", 
            "4": "ghi",
            "5": "jkl",
            "6": "mno", 
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz"
        }

        n = len(digits)
        ans = []
        path = []


        def dfs(i): 
            if i == n:
                ans.append("".join(path))
                return
            
            for letter in phone[digits[i]]:
                # 做選擇
                path.append(letter)
                # dfs 下一層
                dfs(i+1)
                # 撤銷選擇
                path.pop()        

        dfs(0)

        return ans

            



def main():
    sol = Solution()

    tests = [
        (
            "23",
            ["ad", "ae", "af",
             "bd", "be", "bf",
             "cd", "ce", "cf"]
        ),
        (
            "2",
            ["a", "b", "c"]
        ),
        (
            "",
            []
        ),
        (
            "79",
            [
                "pw", "px", "py", "pz",
                "qw", "qx", "qy", "qz",
                "rw", "rx", "ry", "rz",
                "sw", "sx", "sy", "sz"
            ]
        ),
    ]

    for digits, expected in tests:
        result = sol.letterCombinations(digits)

        print(f"digits   = {digits}")
        print(f"result   = {result}")
        print(f"expected = {expected}")
        print(
            "PASS"
            if sorted(result) == sorted(expected)
            else "FAIL"
        )
        print()


if __name__ == "__main__":
    main()