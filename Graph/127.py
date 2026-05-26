from typing import List
from collections import deque


class Solution:
    def ladderLength(
        self,
        beginWord: str,
        endWord: str,
        wordList: List[str]
    ) -> int:   

        # TODO 1:
        # 如果 endWord 不在 wordList
        if endWord not in wordList:
            return 0

        # TODO 2:
        # wordSet for O(1) lookup
        # wordList lookup -> O(n) --> faster!!
        wordSet = set(wordList)

        # TODO 3:
        # BFS queue
        q = deque()
        # (word, steps)
        q.append((beginWord, 1))

        # TODO 4:
        # visited set
        visited = set([beginWord])

        # TODO 5:
        # BFS
        # while queue:
        while q:

            # pop current word and step
            word, step = q.popleft()
            
            if word == endWord:
                return step

            # 嘗試改每個字元
            # h o t
            # ^
            # a-z
            for cha in range(len(word)):
                for ch in "abcdefghijklmnopqrstuvwxyz":
                    new_word = word[:cha] + ch + word[cha+1:]
                    #print(new_word)

                    if (new_word in wordSet) and (new_word not in visited):
                        visited.add(new_word)
                        q.append((new_word, step + 1))

        return 0


def test_word_ladder():
    s = Solution()

    print(
        s.ladderLength(
            "hit",
            "cog",
            ["hot","dot","dog","lot","log","cog"]
        )
    )
    # expected: 5

    print(
        s.ladderLength(
            "hit",
            "cog",
            ["hot","dot","dog","lot","log"]
        )
    )
    # expected: 0

    print(
        s.ladderLength(
            "a",
            "c",
            ["a","b","c"]
        )
    )
    # expected: 2


if __name__ == "__main__":
    test_word_ladder()