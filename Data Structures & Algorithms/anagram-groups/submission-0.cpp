class Solution {
public:

    bool isAnagram(const std::string& lhs, const std::string& rhs){
        if(lhs.size() != rhs.size())
            return false;

        unordered_map<char, int> mp;
        for(auto c : lhs)
            mp[c] += 1;
        for(auto c : rhs)
        {
            mp[c] -= 1;
            if(mp[c] < 0)
                return false;
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty())
            return {};

        if(strs.size() == 1)
         return {strs};

        vector<vector<string>> res;
        unordered_set<int> inserted;
        for (int i = 0; i < strs.size(); i++)
        {
            if(inserted.count(i))
                continue;
        
            std::vector<string> current{strs[i]};
            for (int j = i + 1; j < strs.size(); j++){
                if(inserted.count(j))
                    continue;
                    
                if(isAnagram(strs[i], strs[j])){
                    inserted.insert(j);
                    current.push_back(strs[j]);
                }
            }
            res.push_back(current);
        }
        return res;
    }
};
