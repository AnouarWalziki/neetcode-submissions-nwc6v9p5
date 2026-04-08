class Solution {
public:
    bool isAlnum(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');}


    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right){ // attention ! < not just !=
            while(left < right && !isAlnum(s[left])){
                left++;
            }

            while( left < right && !isAlnum(s[right])){
                right--;
            }

            if(tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};
