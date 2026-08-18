class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        vector<int>charvec(256 , 0);
        for(int i=0;i<s.length();i++){
            charvec[(int)s[i]]++;
        }
        int max=0;
        int i=0;
        char c='\0';
        while(ans.length()!=s.length()){
            while(i<256){
                if(charvec[i]>max){
                    max=charvec[i];
                    c=(char)i;
                }
                i++;
            }
            while(max!=0){
                ans+=c;
                max--;
            }
            charvec[(int)c]=0;
            max=0;
            i=0;

        }
        return ans;
    }
};