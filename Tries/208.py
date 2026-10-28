class Trie:

    def __init__(self):
        #use a dict to record all the children
        self.children = {}
        self.is_end = False

    def insert(self, word: str) -> None:
        current = self

        #go through the word
        for c in word:
            #if there's not yet have this character -> create a trie
            if c not in current.children:
                current.children[c] = Trie()
            #move current to the next character
            current = current.children[c]

        #on the end of the word
        current.is_end = True

    def search(self, word: str) -> bool:
        current = self

        for c in word:
            if c not in current.children:
                return False
            current = current.children[c]
        #check whether this is a word's end
        return current.is_end

    def startsWith(self, prefix: str) -> bool:
        current = self

        for c in prefix:
            if c not in current.children:
                return False
            current = current.children[c]
        #check whether this is a word's end
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)