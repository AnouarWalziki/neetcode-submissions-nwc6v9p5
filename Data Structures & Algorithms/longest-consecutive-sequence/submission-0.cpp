class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1){
            return n;
        }

        unordered_set<int> elements;
        for(int nbr : nums)
            elements.insert(nbr);
        
        vector<int> starts;
        for(int nbr : nums){
            if(!elements.contains(nbr - 1))
                starts.push_back(nbr);
        }

        int max = 0; 
        for(int nbr : starts){
            int currentSeq = 1;
            int next = nbr + 1;

            while(elements.contains(next)){
                currentSeq++;
                next++;
            }

            if(max < currentSeq)
                max = currentSeq;
        }
        return max;
    }
};
