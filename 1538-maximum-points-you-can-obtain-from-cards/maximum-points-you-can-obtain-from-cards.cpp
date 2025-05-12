class Solution 
{
   public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int n = cardPoints.size();
        int leftSum = 0;
        for (int left = 0; left < k; left++)  // Increment the left...
            leftSum = leftSum+cardPoints[left];
        
        int rightSum = 0;
        int right = n-1;
        int ans = leftSum + rightSum;

        for (int left = k - 1; left >= 0; left --) // Decrement the left...
        {                   
            leftSum = leftSum - cardPoints[left];  // shrink the left sum
            
            rightSum = rightSum + cardPoints[right];  //Increment the right sum
            ans = max(ans, leftSum + rightSum);
            right--;
        }
        return ans;
    }
};