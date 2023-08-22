class Solution{
	public:
	vector<string> AllPossibleStrings(string s){
        vector<string>ans;
        int n = pow(2,s.length());
        for(int  i=1;i<n;i++){
           string str  = "";
           int pos = 0;
           int run = i;
           while(run){
               if(run&1){str+=s[pos];}
               pos++;
               run = run>>1;
           }
           ans.push_back(str);
           str = "";
        }
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};
