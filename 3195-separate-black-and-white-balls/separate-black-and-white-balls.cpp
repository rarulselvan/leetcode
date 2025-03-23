class Solution 
{
public:
    long long minimumSteps(std::string s) 
    {
        long long steps = 0;
        int onesCount = 0; 
        int length = s.size();

        // Traverse the string from the end to the start...
        for (int i = length - 1; i >= 0; i--) 
        {
            if (s[i] == '1') //for every 1 calculate the steps to pack all 1's from right end
            { 
                onesCount++; // Increment the count of '1's.

                // Accumulate the distance from right-most end minus the number of '1's encountered so far.

                steps = steps + ((length -i)  - onesCount); // i starts from length-1.. hence onesCount is incremented prioir to this line
            }
        }        
        return steps;
    }
};