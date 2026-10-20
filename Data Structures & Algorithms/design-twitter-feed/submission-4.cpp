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
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> minHeap; 

        if(followeesByUser[userId].empty()){
            for(auto& [tweetId, currOrder] : tweetsByUser[userId]){
                minHeap.push({tweetId, currOrder});
                if(minHeap.size() > 10)
                    minHeap.pop();
            }
        } else{
            // insert user tweets
            for(auto& [tweetId, currOrder] : tweetsByUser[userId]){
                cout << endl;
                minHeap.push({tweetId, currOrder});
                if(minHeap.size() > 10)
                    minHeap.pop();
            }

            // insert followees tweets
            for(int followeeId : followeesByUser[userId]){
                for(auto& [tweetId, currOrder] : tweetsByUser[followeeId]){
                    minHeap.push({tweetId, currOrder});
                    if(minHeap.size() > 10)
                        minHeap.pop();
                }
            }
        }
        
        vector<int> res;
        while(!minHeap.empty()){
            res.push_back(minHeap.top().first);
            minHeap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId)
            return;
        
        if(!followeesByUser[followerId].contains(followeeId)){
            followeesByUser[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId)
            return;

        if(followeesByUser[followerId].contains(followeeId)){
            followeesByUser[followerId].erase(followeeId);
        }
    }

private:
    int order;
    unordered_map<int, deque<pair<int, int>>> tweetsByUser;
    unordered_map<int, unordered_set<int>> followeesByUser;
};
