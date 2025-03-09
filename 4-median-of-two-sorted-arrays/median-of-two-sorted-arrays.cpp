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
class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        for(auto x: nums2)
            nums1.push_back(x);
        sort(nums1.begin(), nums1.end());

        int size=nums1.size();
        int mid=size/2;

        if(size%2)
            return nums1[mid];
        else
            return (nums1[mid-1]+nums1[mid])/2.0;
    }
};