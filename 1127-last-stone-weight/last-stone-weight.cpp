class Solution 
{
private:
    priority_queue<int> maxQ;
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        for(auto stone: stones)
            maxQ.push(stone);
        return getLastStoneWeight();
    }
    int getLastStoneWeight()
    {
        if(maxQ.size()==1)
            return maxQ.top();
        int second=0;
        int first=0;
        while(maxQ.size()>1)
        {
            first=maxQ.top();
            maxQ.pop();    
            second=maxQ.top(); 
                 maxQ.pop();
            if(first==second)
                continue;
            else
            {
           
                maxQ.push(abs(first-second));
            }
        }
        if(maxQ.size()==0)
            return 0;
        else
            return maxQ.top();
    }
};