class Solution 
{
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
    {
        // A square should have 2 pairs of equal sides & 1 pair of equal diagonals  
        return areSidesValid(p1, p2, p3) && areSidesValid(p1, p3, p4) &&
               areSidesValid(p1, p2, p4) && areSidesValid(p2, p3, p4);
    }

    // Helper function to check if 3 points form two equal sides and one diagonal of a square
    bool areSidesValid(vector<int>& a, vector<int>& b, vector<int>& c) 
    {
        int ax = a[0], ay = a[1]; // Coordinates of point a
        int bx = b[0], by = b[1]; // Coordinates of point b
        int cx = c[0], cy = c[1]; // Coordinates of point c

        // Calculate squared distances between points
        int abSquaredDist = squaredDistance(ax, ay, bx, by);
        int acSquaredDist = squaredDistance(ax, ay, cx, cy);
        int bcSquaredDist = squaredDistance(bx, by, cx, cy);
      
        // Check for two equal sides and a diagonal; also, check that sides are not zero-length
        return (abSquaredDist == acSquaredDist && abSquaredDist + acSquaredDist == bcSquaredDist && abSquaredDist > 0) ||
               (abSquaredDist == bcSquaredDist && abSquaredDist + bcSquaredDist == acSquaredDist && abSquaredDist > 0) ||
               (acSquaredDist == bcSquaredDist && acSquaredDist + bcSquaredDist == abSquaredDist && acSquaredDist > 0);
    }

private:
    // Helper function to calculate squared distance between two points
    int squaredDistance(int x1, int y1, int x2, int y2) 
    {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
};