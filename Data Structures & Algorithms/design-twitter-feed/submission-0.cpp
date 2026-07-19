class Twitter {
public:
    unordered_map<int, vector<std::pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> follow_relation;
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        vector<pair<int, int>> user_post; // {time, tweetId}

        unordered_set<int> follow_list = follow_relation[userId];
        for (auto person: follow_list){
            for (auto tweet: tweets[person]){
                user_post.push_back(tweet);
            }
        }
        // add the post written by his own
        for (auto tweet: tweets[userId]){
            user_post.push_back(tweet);
        }
        // sort based on the time, and we want the post with greatest timestamp to be at the front

        sort(user_post.begin(), user_post.end(), greater<pair<int, int>>());
        int post_count = user_post.size();
        for (int i = 0; i < min(post_count, 10); i++){
            feed.push_back(user_post[i].second);
        }

        return feed;

    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId){
            follow_relation[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        follow_relation[followerId].erase(followeeId);
    }
};
