class Solution:
    def myPow(self, x: float, n: int) -> float:
        isNeg = False
        if n < 0:
            isNeg = True

        def helper(n):
            if n == 0:
                return 1
            half = helper(n//2)

            #n is even
            if n%2 == 0:
                return half*half
            else: #n is odd:
                return half*half*x

        return helper(n) if not isNeg else 1/helper(abs(n))


def main():
    solution = Solution()

    print(solution.myPow(2.0, 10))
    # Expected: 1024.0

    print(solution.myPow(2.1, 3))
    # Expected: approximately 9.261

    print(solution.myPow(2.0, -2))
    # Expected: 0.25

    print(solution.myPow(5.0, 0))
    # Expected: 1.0

    print(solution.myPow(-2.0, 3))
    # Expected: -8.0

    print(solution.myPow(-2.0, 4))
    # Expected: 16.0


if __name__ == "__main__":
    main()