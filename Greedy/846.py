from typing import List
from collections import Counter


class Solution:

    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        # Step 1:
        # 如果牌的總數不是 groupSize 的倍數
        # 直接回傳 False
        if len(hand) % groupSize != 0:
            return False
        
        # Step 2:
        # 紀錄每個數字還剩幾張
        #Python 內建的Counter
        count = Counter(hand)

        # Step 3:
        # 排序，確保每次從目前最小的牌開始處理
        hand.sort()

        for start in hand:
            # 如果這張牌已經在前面的組合中用完
            # 就跳過
            if count[start] == 0:
                continue

            # Step 4:
            # 嘗試組出：
            # start, start+1, ..., start+groupSize-1
            for card in range(start, start + groupSize):

                # TODO:
                # 如果 card 已經沒有剩下
                # 代表這一組無法完成
                # 回傳 False
                if count[card] == 0:
                    return False


                # TODO:
                # 使用一張 card
                # 更新 count
                count[card] -= 1


        # 所有牌都成功分組
        return True


# -------------------------
# Testing
# -------------------------

def main():
    sol = Solution()

    test_cases = [
        ([1, 2, 3, 6, 2, 3, 4, 7, 8], 3, True),
        ([1, 2, 3, 4, 5], 4, False),
        ([1, 2, 3, 4], 4, True),
        ([1, 2, 3, 4, 5, 6], 3, True),
        ([1, 2, 3, 4, 6, 7, 8, 9], 4, True),
        ([1, 1, 2, 2, 3, 3], 3, True),
    ]

    for hand, group_size, expected in test_cases:
        result = sol.isNStraightHand(hand.copy(), group_size)

        print(f"hand      = {hand}")
        print(f"groupSize = {group_size}")
        print(f"Output    = {result}")
        print(f"Expected  = {expected}")
        print("-" * 40)


if __name__ == "__main__":
    main()