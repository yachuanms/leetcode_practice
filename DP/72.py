class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        table = {} #key: (i, j), value: min change from word1 to word2

        def dfs(i, j):
            if (i, j) in table:
                return table[(i, j)]
            
            if i == len(word1): #insert the rest alphabet of word2[j:] into word1
                table[(i, j)] = len(word2)-j
                return table[(i, j)]
            if j == len(word2):
                table[(i, j)] = len(word1)-i
                return table[(i, j)]

            #if word1[i] == word2[j] -> no change needed
            if word1[i] == word2[j]:
                table[(i, j)] = dfs(i+1, j+1)
                return table[(i, j)]

            #three options: insert, delete, replace
            table[(i, j)] = min(dfs(i, j+1)+1, dfs(i+1, j)+1, dfs(i+1, j+1)+1)
            return table[(i, j)]

        return dfs(0, 0)


def main():
    solution = Solution()

    tests = [
        ("horse", "ros", 3),
        ("intention", "execution", 5),
        ("", "", 0),
        ("abc", "", 3),
        ("", "abc", 3),
        ("a", "a", 0),
        ("a", "b", 1),
    ]

    for word1, word2, expected in tests:
        result = solution.minDistance(word1, word2)

        print(f"word1 = {word1!r}, word2 = {word2!r}")
        print(f"result = {result}, expected = {expected}")
        print()


if __name__ == "__main__":
    main()