class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int size1=nums1.size();
        int size2=nums2.size();
        int size3=size1+size2;
        int arr3[size3];

        for (int i = 0; i < size1; ++i)
            arr3[i] = nums1[i];

        for (int i = 0; i < size2; ++i) 
            arr3[size1 + i] = nums2[i];
            
        sort(arr3, arr3+size3);

            // Calculate and return the median
        int mid = size3 / 2;
    
      // If length of array is even
        if (size3 % 2 == 0) 
            return (arr3[mid] + arr3[mid - 1])/ 2.0;
        else 
            return arr3[mid];
    }
};