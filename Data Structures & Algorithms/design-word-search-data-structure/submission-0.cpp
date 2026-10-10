class WordDictionary {
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        words.push_back(word);
    }
    
    bool search(string word) {
        for(string s : words){
            cout << s << endl;
            bool equal = true;
            if(s.size() == word.size()){
                for(int i = 0; word.size(); i++){
                    if(word[i] != '.' && word[i] != s[i]){
                        equal = false;
                        break;
                    }
                }
                if(equal)
                    return true;
            }
        }
        cout << s << endl;
        cout << s << endl;
        return false;
    }

private:
    vector<string> words;
};
