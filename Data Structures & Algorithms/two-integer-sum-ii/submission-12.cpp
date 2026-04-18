class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto maxId = numbers.size() - 1;
        int id1 = 0;
        int id2 = maxId;

        while(id1 < id2){
            int sum = numbers[id1] + numbers[id2]; 
            
            if(sum < target){
                id1 += 1;
            } 
            else if (sum > target){
                id2 -= 1;
            }
            else{
                return {(id1 + 1), (id2 + 1)};
            }
        }

        return {};
    }
};
