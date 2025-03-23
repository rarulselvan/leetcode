/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
class MedianFinder 
{
private:
    priority_queue<int> maxQ;
    priority_queue<int, vector<int>, greater<int>> minQ;
public:
    
    void addNum(int num)
    {
        maxQ.push(num);
        minQ.push(maxQ.top());
        maxQ.pop();

        if (minQ.size() > maxQ.size() + 1)
        {
            maxQ.push(minQ.top());
            minQ.pop();
        }
    }
    double findMedian()
    {
        if (minQ.size() == maxQ.size()) 
            return (minQ.top() + maxQ.top())/ 2.0 ;
        else
            return  minQ.top();
    }
};
