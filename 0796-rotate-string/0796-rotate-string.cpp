class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        s+=s;
        for(int i=0;i<goal.size();i++){
            string x=s.substr(i,goal.size());
            if(x==goal)
                return true;
        }
        return false;
    }
};