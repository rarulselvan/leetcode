class Solution 
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        //sort using lamda function
        sort(points.begin(), points.end(), [](const vector<int> a, const vector<int> b)
                                            {
                                               // int x = (a[0] * a[0] + a[1] * a[1]);
                                               // int y = (b[0] * b[0] + b[1] * b[1]);
                                               // cout << x <<"  "<< y<<endl;
                                               // return x < y;

                                                return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
                                            }
        );
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
