class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        '''
        n = len(nums)
        target = (1+n)*n//2

        total = sum(nums)

        return target-total
        '''
        #x^x = 0 0^x = x
        #0^1^2^3^3^0^1會把出現過的都消掉
        #最後0^ans = ans
        #先把n放進來 因為for loop不會輪到n
        xor = len(nums)
        #0 ~ n-1
        for i in range(len(nums)):
            xor^= i
            xor^=nums[i]

        return xor