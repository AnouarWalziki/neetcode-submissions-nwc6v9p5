class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallHeap.push(num);

        if(!largeHeap.empty() && smallHeap.top() > largeHeap.top()){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }

        if(smallHeap.size() > largeHeap.size() + 1){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }

        if(largeHeap.size() > smallHeap.size() + 1){
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        if(smallHeap.size() == largeHeap.size())
            return (smallHeap.top() + largeHeap.top()) / 2.0;
        if(smallHeap.size() > largeHeap.size())
            return smallHeap.top();
        return largeHeap.top();
    }

private:
    priority_queue<int> smallHeap;
    priority_queue<int, vector<int>, greater<int>> largeHeap;
};
