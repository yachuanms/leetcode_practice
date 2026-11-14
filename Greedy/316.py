class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        #use a hashmap to remeber the last place of each letter appears
        last_shown = {}
        in_ans = set()

        for i, cha in enumerate(s):
            last_shown[cha] = i

        ans = []

        for i, cha in enumerate(s):
            if cha in in_ans:
                continue
            while ans and ans[-1] > cha and last_shown[ans[-1]] > i:
                in_ans.remove(ans[-1])
                ans.pop()
                
            ans.append(cha)
            in_ans.add(cha)

        return "".join(ans)

