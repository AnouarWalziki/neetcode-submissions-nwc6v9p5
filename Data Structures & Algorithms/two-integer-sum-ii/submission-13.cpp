class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res; 
        for(int i = 0; i < numbers.size(); i++){
            if(i != 0 && numbers[i] == numbers[i-1]){
                continue;
            }

            int lookup = target - numbers[i];
            int left = i + 1;
            int right = numbers.size() - 1;
            while(left != right){
                int midle = (right + left) / 2;
                if(numbers[midle] == lookup){
                    left = right = midle;
                    break;
                }
                else if(lookup > numbers[midle]){
                    left = midle + 1; 
                } else {
                    right = midle - 1;
                }
            }
            if(numbers[left] == lookup){
                res.insert(res.end(), {i+1, left + 1});
                break;
            }
        }
        return res;
    }
};
