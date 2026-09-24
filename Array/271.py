class Codec:
    def encode(self, strs: List[str]) -> str:
        """Encodes a list of strings to a single string.
        """
        #use num_lenght+# in front of each string
        ans = []

        for word in strs:
            count = len(word)
        
            ans.append(f"{count}#{word}")

        return "".join(ans)

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings.
        """

        ans = []
        i = 0

        while i < (len(s)):
            j = i+1
            while s[j] != "#":
                j+=1
            length = int(s[i:j])
            word = s[j+1:j+1+length]

            ans.append(word)
            i = j+length+1

        return ans


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))