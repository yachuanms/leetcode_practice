class WordDictionary:

    def __init__(self):
        self.children= {}
        self.is_end = False
    def addWord(self, word: str) -> None:
        current = self

        for c in word:
            if c not in current.children:
                current.children[c] = WordDictionary()

            current = current.children[c]
        current.is_end = True

    def search(self, word: str) -> bool:
        current = self

        def dfs(idx, current):
            if len(word) == idx:
                return current.is_end

            c = word[idx]

            if c == ".":
                #traverse all the possible path
                #check every path!! 
                for child in current.children.values():
                    if dfs(idx+1, child):
                        return True
                return False
            else: # c != "."
                if c not in current.children:
                    return False
                else:
                    return dfs(idx+1, current.children[c])
        
        return dfs(0, self)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)