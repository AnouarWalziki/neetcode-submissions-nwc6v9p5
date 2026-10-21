class MedianFinder {
public:
    MedianFinder() {
        count = 0;
    }
    
    void addNum(int num) {
        count++;
        maxHeap.push(num);

        if(maxHeap.size() > count / 2){
            maxHeap.pop();
            minHeap.push(num);
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size())
            return (double)(maxHeap.top() + minHeap.top()) / 2;
        return maxHeap.top();
    }

private:
    int count;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};
  