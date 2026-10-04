class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"
        n1 = len(num1)
        n2 = len(num2)
        res = [0] * (n1+n2)
        # cannot directly convert into int
        for i in range(n1-1, -1, -1):
            for j in range(n2-1, -1, -1):
                product_pos = i+j+1
                carry_pos = i+j
                digit1 = int(num1[i])
                digit2 = int(num2[j])
                temp = digit1 * digit2 + res[product_pos]

                res[product_pos] = temp % 10
                res[carry_pos] += temp // 10

        ans = ""
        for i in range(len(res)):
            if i == 0 and res[i] == 0:
                continue
            ans+= str(res[i])

        return ans
