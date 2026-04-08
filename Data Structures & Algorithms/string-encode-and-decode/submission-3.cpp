class Solution {
public:
    string encode(vector<string>& strs) {
        if(strs.empty())
            return "-01";

        string res;
        for(auto str : strs){
            res += to_string(str.size()) + "#" + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        if(s == "-01")
            return {};
        
        vector<string> res;
        string sizeStr;
        int i = 0;
        while(i < s.size()){
            if(s[i] != '#'){
                sizeStr += s[i++];
            }            
            else {
                size_t size = stoi(sizeStr);
                sizeStr.clear();
                if(size == 0){
                    res.push_back("");
                    i++;
                }
                else{
                    res.push_back(s.substr(++i, size));
                    i += size;
                }
            }
        }
        return res;
    }
};
