class Twitter {
public:
    Twitter() {
        order = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetsByUser[userId].push_back({tweetId, order});
        order++;

        if(tweetsByUser[userId].size() > 10)
            tweetsByUser[userId].pop_front();
    }
    
    vector<int> getNewsFeed(int userId) {
        auto compare = [](const pair<int,int>& a, const pair<int,int>& b){ 
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> maxHeap; 

        if(followeesByUser[userId].empty()){
            for(auto& [tweetId, currOrder] : tweetsByUser[userId]){
                maxHeap.push({tweetId, currOrder});
                if(maxHeap.size() > 10)
                    maxHeap.pop();
            }
        } else{
            // insert user tweets
            for(auto& [tweetId, currOrder] : tweetsByUser[userId]){
                cout << endl;
                maxHeap.push({tweetId, currOrder});
                if(maxHeap.size() > 10)
                    maxHeap.pop();
            }

            // insert followees tweets
            for(int& followeeId : followeesByUser[userId]){
                for(auto& [tweetId, currOrder] : tweetsByUser[followeeId]){
                    maxHeap.push({tweetId, currOrder});
                    if(maxHeap.size() > 10)
                        maxHeap.pop();
                }
            }
        }
        
        vector<int> res;
        while(!maxHeap.empty()){
            res.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId)
            return;
        
        if(auto it = find(followeesByUser[followerId].begin(), followeesByUser[followerId].end(), 
                        followeeId); it == followeesByUser[followerId].end()){
            followeesByUser[followerId].push_back(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId)
            return;

        if(auto it = find(followeesByUser[followerId].begin(), followeesByUser[followerId].end(), 
                        followeeId); it != followeesByUser[followerId].end()){
            followeesByUser[followerId].erase(it);
        }
    }

private:
    int order;
    unordered_map<int, deque<pair<int, int>>> tweetsByUser;
    unordered_map<int, vector<int>> followeesByUser;
};
