struct Task{
    int count = 0;
    int coolDown = 0;
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, Task> taskDatas;
        for(char task : tasks){
            taskDatas[task].count++;
        }

        int res = 0;
        while(!taskDatas.empty()){
            // pick available task with the highest remaining count
            auto best = taskDatas.end();
            for(auto it = taskDatas.begin(); it != taskDatas.end(); it++){
                if(it->second.coolDown > 0)
                    continue;
                if(best == taskDatas.end() || it->second.count > best->second.count)
                    best = it;
            }

            // tick cooldowns for everyone first
            for(auto& [label, data] : taskDatas){
                if(data.coolDown > 0){
                    data.coolDown--;
                }
            }

            if(best != taskDatas.end()){
                // run task
                best->second.count--;

                if(best->second.count == 0){
                    taskDatas.erase(best);
                }
                else
                    best->second.coolDown = n;
            }

            res++;
        }

        return res;
    }
};
