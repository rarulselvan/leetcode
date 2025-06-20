/*

class Solution
 {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        priority_queue<int> heap;
        int i=0;
        for (i = 0; i < size(heights) - 1; i++) 
        {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0) 
            {
                heap.push(diff); //On top max bricks used will always there
                if(bricks-diff >=0)// we can use bricks
                {
                    bricks=bricks-diff;
                    //heap.push(diff); //On top max bricks used will always there
                }
                else // bricks not sufficient hence use ladder
                {
                    cout <<bricks<<" "<<endl;
                    if(ladders>0)
                    {
                        ladders--;
                        //use the ladder on the previous highest brick usage
                        int x = heap.top(); heap.pop();
                        bricks=bricks+x; // gather the previously used highest bricks
                    }
                    else
                        break;
                }
            }
        }
        return i;
    }
};
*/
class Solution
{
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        // max heap to store difference between two adjacent
        // towers which we have covered using blocks
        priority_queue<int> maxB;
        int ans = 0;

        for(int i=0; i<heights.size()-1; i++)
        {
            // Calculate the difference between the current tower and the next tower
            int diff = heights[i + 1]- heights[i];

            if (diff > 0) 
            {
                //first try to use the bricks
                bricks = bricks -diff;
                maxB.push(diff);

                // If all the bricks are used(negative?), start using ladders
                if (bricks < 0) 
                {
                    if (ladders == 0)
                        break;
                    ladders--;

                    bricks += maxB.top(); //get the maximum including the current one and add to the bricks
                    maxB.pop();
                }
            }
            ans++;
        }
        return ans;
    }
};