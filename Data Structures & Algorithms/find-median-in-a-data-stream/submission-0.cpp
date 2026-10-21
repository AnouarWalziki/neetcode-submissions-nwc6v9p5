class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        vals.push_back(num);
    }
    
    double findMedian() {
        ranges::sort(vals);
        if(vals.size() % 2 != 0)
            return vals[vals.size() / 2 ];

        int firstMid = vals.size() / 2 - 1;
        int secondMid = firstMid + 1;
        if(firstMid < 0)
            return vals[secondMid]; 

        return  double(vals[secondMid] + vals[firstMid]) / 2;
    }

private:
    vector<double> vals;
};
