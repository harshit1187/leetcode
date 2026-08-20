class Solution {
public:
    pair<int,int>expandaroundcentre(string x,int left,int right){
        while(left>=0&&right<x.size()&&(x[left]==x[right])){
            left--;
            right++;
        }
        return{left+1,right-1};
    }
    string longestPalindrome(string s) {
        int start=0;int end=0;
        for(int i=0;i<s.size();i++){
        auto odd=expandaroundcentre(s,i,i);
        auto even=expandaroundcentre(s,i,i+1);
        if((odd.second-odd.first+1)>(end-start+1)){
            start=odd.first;
            end=odd.second;
        }
        if((even.second-even.first+1)>(end-start+1)){
            start=even.first;
            end=even.second;
        }
        }
        return s.substr(start,end-start+1);
    }
};