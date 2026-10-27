class Twitter:

    def __init__(self):
        self.tweets = {}
        self.relations = {}
        self.time = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        if userId not in self.tweets:
            self.tweets[userId] = []
        
        self.tweets[userId].append((self.time, tweetId))
        self.time += 1

    def getNewsFeed(self, userId: int) -> list[int]:
        filterPosts = []
        for followeeId, tweetList in self.tweets.items():
            if followeeId in self.relations.get(userId, set()) or followeeId == userId:
                index = len(tweetList)-1
                time, tweetId = tweetList[index]
                heapq.heappush(filterPosts, (-time, tweetId, followeeId, index))
        ans = []
        for i in range(10):
            if filterPosts:
                _, tweetId, authorId, index = heapq.heappop(filterPosts)
                ans.append(tweetId)
                if index > 0:
                    time, prevTweetId = self.tweets[authorId][index-1]
                    heapq.heappush(filterPosts, (-time, prevTweetId, authorId, index-1))

        return ans

    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId == followeeId:
            return

        if followerId not in self.relations:
            self.relations[followerId] = set()

        self.relations[followerId].add(followeeId)

        return 

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.relations.get(followerId, set()):
            self.relations[followerId].discard(followeeId)
        return
        


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)