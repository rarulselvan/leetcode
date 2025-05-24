class Solution {
public:
    int maximumSwap(int num) {

string s=to_string(num);
string maxNum = s; // Store the max number found

    // Try swapping every pair of digits (i, j)
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            swap(s[i], s[j]);
            maxNum = max(maxNum, s);
            swap(s[i], s[j]);
        }
    }
    return stoi(maxNum);

    }
};