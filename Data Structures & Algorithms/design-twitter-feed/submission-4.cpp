class Twitter {
    unordered_map<int, set<int>> followings;
    unordered_map<int, vector<pair<int, int>>> posts;
    int ts = 0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({ts++, tweetId});
        followings[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> v;
        for(auto& uid: followings[userId]){
            v.insert(v.end(), posts[uid].rbegin(), posts[uid].rend());
        }
        sort(v.rbegin(), v.rend());
        while(v.size()>10)v.pop_back();
        vector<int>feed;
        for(auto f: v){
            feed.push_back(f.second);
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId)return;
        followings[followerId].erase(followeeId);
    }
};
