class Solution {
public:
    bool isPathCrossing(string path) {
        
        set< pair<int,int> > s;
        int x=0,y=0;
        s.insert({x,y});
        for(char c: path)
        {
            if(c=='N') y++;
            if(c=='E') x++;
            if(c=='S')  y--;
            if(c=='W')  x--;
            if(s.count({x,y}))
            return true;
            s.insert({x,y});
        }
        return false;      
    }
};