class Solution:
    def isValid(self, s):
        stack = []

        #要用閉括號當key!!!!
        mapping = {
            ')': '(',
            ']': '[',
            '}': '{'
        }

        for cha in s:
            if cha in "([{":
                stack.append(cha)
            else:
                if not stack or stack[-1] != mapping[cha]:
                    return False
                stack.pop()

        return not stack
        


def run_test(s, expected):
    sol = Solution()
    ans = sol.isValid(s)
    print(f"s='{s}'")
    print(f"  ans={ans}, expected={expected}  --> {'PASS' if ans == expected else 'FAIL'}")
    if ans != expected:
        raise AssertionError("Test failed")


if __name__ == "__main__":
    run_test("()", True)
    run_test("()[]{}", True)
    run_test("(]", False)
    run_test("([)]", False)
    run_test("{[]}", True)
    run_test("", True)
    print("All tests passed!")