class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        ans = []
        #split sentence into words
        words = sentence.split()

        #check each words
        #  Is it a valid price? (start with $ and decimal behind only)
        for word in words:
            if word.startswith('$') and word[1:].isdecimal():
                price = int(word[1:])
                #if it's valid -> apply discount
                price -= price * discount / 100
                price = format(price, '.2f')
                ans.append("${}".format(price))

            else:
                ans.append(word)
        
        return " ".join(ans)
        