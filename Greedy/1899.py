from typing import List


class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        
        #用來存找到哪些index了
        found = set()

        for triplet in triplets:
            #如果該triplet有值大於target, 代表那行完全不能被merge
            if(triplet[0] > target[0] or 
               triplet[1] > target[1] or
               triplet[2] > target[2]):
               continue

            #如果有一樣的值就代表找到了
            #因為比target大的值已經都被刪掉了
            #跟target一樣大就可以保證是全部最大
            for i in range(3):
                if (triplet[i] == target[i]):
                    found.add(i)

        #每個位置都有找到值
        return len(found)==3
        


# -------------------------
# Testing
# -------------------------

def main():
    sol = Solution()

    test_cases = [
        (
            [[2,5,3],[1,8,4],[1,7,5]],
            [2,7,5],
            True
        ),
        (
            [[3,4,5],[4,5,6]],
            [3,2,5],
            False
        ),
        (
            [[2,5,3],[2,3,4],[1,2,5]],
            [2,5,5],
            True
        ),
    ]

    for triplets, target, expected in test_cases:
        result = sol.mergeTriplets(triplets, target)

        print(f"Output   = {result}")
        print(f"Expected = {expected}")
        print("-"*40)


if __name__ == "__main__":
    main()