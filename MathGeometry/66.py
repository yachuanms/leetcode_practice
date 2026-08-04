from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:

        # TODO:
        # 從右往左遍歷
        for i in range(len(digits)-1, -1, -1):
            if digits[i] != 9:
                digits[i]+= 1
                return digits

            # Case 1:
            # 如果不是 9
            # +1 後直接 return
            else:
                digits[i] = 0
            # Case 2:
            # 如果是 9
            # 改成 0，繼續往左

        # TODO:
        # 如果全部都是 9
        # 最前面插入 1
        #list.insert(index, value)
        digits.insert(0, 1)

        return digits


# -------------------------
# Testing
# -------------------------

def main():
    sol = Solution()

    test_cases = [
        ([1,2,3], [1,2,4]),
        ([1,2,9], [1,3,0]),
        ([9], [1,0]),
        ([9,9,9], [1,0,0,0]),
        ([4,3,2,1], [4,3,2,2]),
    ]

    for digits, expected in test_cases:
        result = sol.plusOne(digits[:])   # 複製一份避免修改原資料
        print(f"Input    : {digits}")
        print(f"Output   : {result}")
        print(f"Expected : {expected}")
        print("-" * 40)


if __name__ == "__main__":
    main()