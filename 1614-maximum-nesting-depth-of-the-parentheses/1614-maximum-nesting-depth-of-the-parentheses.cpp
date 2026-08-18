class Solution {
public:
    int maxDepth(string s) {
        int open=0;
        int depth=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                open++;
                depth=max(depth,open);
            }
            if(s[i]==')')
                open--;
        }
        return depth;
    }
};