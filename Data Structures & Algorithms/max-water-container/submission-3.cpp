class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = 0;
        int l = 0;
        int r = heights.size() - 1;
        while(l < r){
            int area = min(heights[l],heights[r]) * (r - l);
            if(area > max)
                max = area;

            if(heights[l] < heights[r]){
                int i = l + 1;
                while(heights[i] <= heights[l] && i < r){
                    i++;
                }
                l = i;
            } else{
                int i = r - 1;
                while(heights[i] <= heights[r] && l < i){
                    i--;
                }
                r = i;
            }
        }
        return max;
    }
};
