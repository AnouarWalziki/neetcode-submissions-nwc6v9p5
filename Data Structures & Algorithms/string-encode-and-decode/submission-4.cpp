class Solution {
public:
    string encode(vector<string>& strs) {
        string res;
        for(auto str : strs){
            res += to_string(str.size()) + "#" + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }

            size_t size = stoi(s.substr(i, j - i));
            i = j + 1;
            res.push_back(s.substr(i, size));
            i += size ;
        }
        return res;
    }
};
