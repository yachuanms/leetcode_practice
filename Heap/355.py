import heapq  # 記得在檔案最上方 import

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


def main():
    def check(name, actual, expected):
        if actual == expected:
            print(f"PASS | {name}")
        else:
            print(f"FAIL | {name}")
            print(f"  Expected: {expected}")
            print(f"  Actual:   {actual}")

    # Test 1: User's own tweets
    twitter = Twitter()
    twitter.postTweet(1, 5)
    check("Own tweets", twitter.getNewsFeed(1), [5])

    # Test 2: Follow another user
    twitter.follow(1, 2)
    twitter.postTweet(2, 6)
    check("Follow", twitter.getNewsFeed(1), [6, 5])

    # Test 3: Unfollow
    twitter.unfollow(1, 2)
    check("Unfollow", twitter.getNewsFeed(1), [5])

    # Test 4: No tweets
    twitter = Twitter()
    check("Empty feed", twitter.getNewsFeed(1), [])

    # Test 5: Do not include unrelated users
    twitter.postTweet(1, 10)
    twitter.postTweet(2, 20)
    twitter.postTweet(3, 30)
    twitter.follow(1, 2)
    check("Filter unrelated users", twitter.getNewsFeed(1), [20, 10])

    # Test 6: Only return the latest 10 tweets
    twitter = Twitter()
    for i in range(1, 16):
        twitter.postTweet(1, i)
    check("Latest 10 tweets", twitter.getNewsFeed(1),
          [15, 14, 13, 12, 11, 10, 9, 8, 7, 6])

    # Test 7: K-way merge across multiple users
    twitter = Twitter()
    twitter.postTweet(1, 101)
    twitter.postTweet(2, 201)
    twitter.postTweet(1, 102)
    twitter.postTweet(3, 301)
    twitter.postTweet(2, 202)

    twitter.follow(1, 2)
    twitter.follow(1, 3)
    check("K-way merge", twitter.getNewsFeed(1),
          [202, 301, 102, 201, 101])

    # Test 8: Follow yourself
    twitter.follow(1, 1)
    check("Self-follow", twitter.getNewsFeed(1),
          [202, 301, 102, 201, 101])

    # Test 9: Unfollow a user who was never followed
    twitter.unfollow(1, 99)
    check("Unfollow nonexistent relation", twitter.getNewsFeed(1),
          [202, 301, 102, 201, 101])

    # Test 10: Repeated follow
    twitter.follow(1, 2)
    twitter.follow(1, 2)
    check("Repeated follow", twitter.getNewsFeed(1),
          [202, 301, 102, 201, 101])

    print("\nAll tests finished!")


if __name__ == "__main__":
    main()