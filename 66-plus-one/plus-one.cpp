class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            digits[i]++;
            digits[i] %= 10;
            if (digits[i] != 0) 
                return digits;//the original number is between 0-8 henceno carry return here 
            else
                continue; //else 
        }
        digits.insert(digits.begin(), 1);//inser the last carry here
        return digits;
    }
};