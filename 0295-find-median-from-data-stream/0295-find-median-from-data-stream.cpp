class MedianFinder {
private:
    priority_queue<double> maxHeap;
    priority_queue<double, vector<double>, greater<double>> minHeap;
public:
    MedianFinder() {
     
    }
    
    void addNum(int num) {
        if(maxHeap.empty() or maxHeap.top()>num) maxHeap.push(num);
        else minHeap.push(num);
        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(minHeap.size() > maxHeap.size() + 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        double ans = 0.0;
        if(maxHeap.size() == minHeap.size()) {
            ans = (maxHeap.top() + minHeap.top()) / 2;
        }
        else if(maxHeap.size() > minHeap.size()) ans = maxHeap.top();
        else ans = minHeap.top();
        
        return ans;
    }
};
