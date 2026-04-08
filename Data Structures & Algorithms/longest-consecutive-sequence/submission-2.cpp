class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> elements(nums.begin(), nums.end());

        int longest = 0; 
        for(int nbr : nums){
            if(elements.contains(nbr - 1))
                continue;

            int length = 1;
            while(elements.contains(nbr + length)){
                length++;
            }

            longest = max(longest, length);
        }
        return longest;
    }
};
