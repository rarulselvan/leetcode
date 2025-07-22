/*class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int size1=nums1.size();
        int size2=nums2.size();
        int size3=size1+size2;
        vector<int> arr3;

        for (auto x: nums1)
            arr3.push_back(x);

        for (auto x: nums2)
            arr3.push_back(x);
            
        sort(arr3.begin(), arr3.end());//, arr3+size3);

            // Calculate and return the median
        int mid = size3 / 2;
    
      // If length of array is even
        if (size3 % 2 == 0) 
            return (arr3[mid] + arr3[mid - 1])/ 2.0;
        else 
            return arr3[mid];
    }
};
*/
/*
class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        for(auto x: nums2)
            nums1.push_back(x);
        sort(nums1.begin(), nums1.end());

        int len=nums1.size();
        int mid=len/2;

        if(len%2)//odd number...return the mid number
            return nums1[mid];
        else //even number return the average
            return (nums1[mid-1]+nums1[mid])/2.0;
    }
};*/
class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m=nums1.size();
        int n=nums2.size();
        int i=0;
        int j=0;

        int value1=0;
        int value2=0;
        //find one value (odd numbers)...two values for even number
        for (int count = 0; count <= (m + n) / 2; count++) 
        {
            value1=value2;
        
            if(i<m && j<n)
            {
                if(nums1[i]<nums2[j])
                {
                    value2=nums1[i];
                    i++;
                }
                else
                {
                    value2=nums2[j];
                    j++;
                }
            }
            else if(i<m)
            {
                value2=nums1[i];
                i++;
            }
            else
            {
                value2=nums2[j];
                j++;
            }
        }
        if((m+n)%2)
            return value2;
        else
            return (double)(value1+value2)/2;
    }
};