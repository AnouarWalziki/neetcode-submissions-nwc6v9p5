class Solution {
public:
    string encode(vector<string>& strs) {
        if(strs.empty())
            return "";

        string res;
        for(auto str : strs){
            auto size = str.size();
            if(size < 10)
                res += "00" + to_string(size) + str;
            else if (size >= 10 && size < 100)
                res += "0" + to_string(size) + str;
            else
                res += to_string(size) + str; 
        }
        return res;
    }

    vector<string> decode(string s) {
        if(s.empty())
            return {s};
        
        vector<string> res;
        int i = 0;
        while(i < s.size()){
            size_t size = (stoi(s.substr(i, 3)));
                                            cout << s.substr(i, 3) << endl;
            i += 3;
            if(size == 0){
                res.push_back("");
            }
            else{
                res.push_back(s.substr(i, size));
                i += size;
            }
        }
        return res;
    }
};
