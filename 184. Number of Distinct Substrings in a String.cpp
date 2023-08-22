#include <bits/stdc++.h> 

class trie{
    public:
    trie * node[26];
    bool flag=false;
};

string smaller(string a,string b){
  int i=0;
  int j=0;
  if(b=="1")return a;
    while(i<a.size() && j<b.size()){
       if(a[i]<b[i])return a;
       else if(a[i]>b[i])return b;
       i++;
       j++;
    }
    if(i==a.size())return a;
    return b;
}

string completeString(int n, vector<string> &a){
  trie * root=new trie();
  for(int i=0;i<n;i++){
      string st=a[i];
      trie *tmp=root;
      for(int j=0;j<st.size();j++){
         if(tmp->node[st[j]-'a']==NULL){
              trie * next=new trie();
              tmp->node[st[j]-'a']=next;
              tmp=next;
         } else {
              tmp = tmp->node[st[j] - 'a'];
         }
      }
      tmp->flag=true;
  }
  int maxi=0;
  string ans="1";
  for(int i=0;i<n;i++){
      string st=a[i];
      trie *tmp=root;
      bool tflag=true;
      for (int j = 0; j < st.size(); j++) {
        if(tmp->node[st[j]-'a']!=NULL){
            tmp=tmp->node[st[j]-'a'];
            if (tmp->flag == false) {
                tflag = false;
                break;
            }
        }
        else{
            tflag=false;
        }
      }
      if(tflag){
          if(maxi<st.size()){
              ans=st;
              maxi=st.size();
          }
          if(st.size()==maxi){
              ans=smaller(st,ans);
          }
      }
  }
  if(ans!="1")
    return ans;
  return "None";
}
