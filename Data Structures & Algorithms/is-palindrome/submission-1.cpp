class Solution {
public:
    bool isAlnum(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');}


    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while(left != right){
            if(!isAlnum(s[left])){
                left++;
                continue;
            }

            if(!isAlnum(s[right])){
                right--;
                continue;
            }

            if(tolower(s[left]) != tolower(s[right])){
                return false;
            } else if(right - left == 1){
                return true;
            } else {
                left++;
                right--;
            }
        }

        return true;
    }
};
