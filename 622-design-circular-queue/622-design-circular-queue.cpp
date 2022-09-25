class MyCircularQueue {
private:
    int maxSize, head, tail;
    vector<int> data;
public:
    MyCircularQueue(int k) {
        data.resize(k);
        maxSize = k;
        head = 0, tail = -1;
    }
    
    bool enQueue(int val) {
        if (isFull()) return false;
        tail = (tail + 1) % maxSize;
        data[tail] = val;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        if (head == tail) head = 0, tail = -1;
        else head = (head + 1) % maxSize;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : data[head];
    }
    
    int Rear() {
        return isEmpty() ? -1 : data[tail];
    }
    
    bool isEmpty() {
        return tail == -1;
    }
    
    bool isFull() {
        return !isEmpty() and (tail + 1) % maxSize == head;
    }

};