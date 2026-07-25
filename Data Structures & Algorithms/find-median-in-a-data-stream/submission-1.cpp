class MedianFinder {
    priority_queue<int, vector<int>, std::greater<int>> minHeap;
    priority_queue<int> maxHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxHeap.empty() || num < maxHeap.top()){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }

        // balancing
        int minSize = minHeap.size();
        int maxSize = maxHeap.size();
        // maxHeap size can be 1 more than minHeap size
        if (maxSize > minSize + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        // minHeap size can only be the same as maxHeap size
        else if (minSize > maxSize){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        // scenario 1: odd count of elements -> return top of maxHeap
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        // scenario 2: even -> return the top of maxHeap and minHeap
        return (maxHeap.top() + minHeap.top())/2.0;
    }
};
