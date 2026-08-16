class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string res="";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' '&& !ans.empty()){
                reverse(ans.begin(),ans.end());
                if(!res.empty())
                    res+=" ";
                res+=ans;
                ans="";
            }
            if(s[i]!=' ')
                ans+=s[i];
            if(i==0 && !ans.empty()){
                reverse(ans.begin(),ans.end());
                if(!res.empty())
                    res+=" ";
                res+=ans;
            }
        }
        return res;
    }
};