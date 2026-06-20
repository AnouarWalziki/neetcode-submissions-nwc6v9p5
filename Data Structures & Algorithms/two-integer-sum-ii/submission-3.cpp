class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto maxId = numbers.size() - 1;
        int id1 = 0;
        int id2 = id1 + 1;

        while(true){
            int sum = numbers[id1] + numbers[id2]; 
            if(sum == target)
                break;
            
            if(sum < target){
                if(id2 == maxId || numbers[id2 + 1] > target)
                    id1 += 1;
                else
                    id2 += 1;
            } 
            else {
                if(id1 == 0)
                    id2 -= 1;
                else
                    id1 -= 1;
            }

            cout << "id1 " << id1 << endl;
            cout << "id2 " << id2 << endl;
        }

        return {(id1 + 1), (id2 + 1)};
    }
};
