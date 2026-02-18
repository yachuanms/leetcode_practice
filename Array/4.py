from typing import List
import math

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # 題目要求 O(log(m+n))，通常會用 binary search 切割 partition
        a, b = nums1, nums2
        #a是短邊  避免 j = half - i 跑到 b 的範圍外
        if len(a) > len(b):
            a, b = b, a
        lena = len(a)
        lenb = len(b)
        
        total = lena + lenb
        half = total //2
        left = 0
        right = lena

        neg_inf = float("-inf")
        pos_inf = float("inf")

        while left <= right:
            i = (left + right)//2
            j = half - i

            if i > 0:
                a_left = a[i-1]
            else:
                a_left = neg_inf
            if i < lena:
                a_right = a[i]
            else:
                a_right = pos_inf
            if j > 0:
                b_left = b[j-1]
            else:
                b_left = neg_inf
            if j < lenb:
                b_right = b[j]
            else:
                b_right = pos_inf
            
            #check if it's valid partition
            if a_left <= b_right and b_left <= a_right:
                #odd
                if total %2 == 1:
                    return float(min(a_right, b_right))
                else:
                    left_max = max(a_left, b_left)
                    right_min = min(a_right, b_right)
                    return float((left_max+right_min)/2)
                
            if a_left > b_right:
                right = i -1
            else:
                left = i +1


        raise ValueError("No valid median found; input arrays may not be sorted.")


def run_test(nums1, nums2, expected, eps=1e-9):
    sol = Solution()
    ans = sol.findMedianSortedArrays(nums1, nums2)
    ok = (abs(ans - expected) <= eps)
    print(f"nums1={nums1}, nums2={nums2}")
    print(f"  ans={ans}, expected={expected}  --> {'PASS' if ok else 'FAIL'}")
    if not ok:
        raise AssertionError("Test failed")


if __name__ == "__main__":
    # 官方常見例子
    run_test([1, 3], [2], 2.0)
    run_test([1, 2], [3, 4], 2.5)

    # 邊界：其中一個空
    run_test([], [1], 1.0)
    run_test([], [1, 2], 1.5)
    run_test([2], [], 2.0)

    # 重複值
    run_test([1, 1], [1, 1], 1.0)

    # 長度差很多
    run_test([1, 2, 3, 4, 5, 6, 7], [8], 4.5)

    # 負數
    run_test([-5, -3, -1], [-2, 0, 2], -1.5)

    print("All tests passed!")
