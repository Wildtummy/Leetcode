class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       queue<pair<string,int>> q;int ct=0;
        q.push({beginWord,1});
        vector<int> vis(wordList.size());
        for(int i=0;i<wordList.size();i++){if(wordList[i]==beginWord){vis[i]=1;}}
        while(!q.empty()){
            string w=q.front().first;
            int l=q.front().second;
            q.pop();
            // cout<<w<<l<<endl;
            if(w==endWord){return l;}
            for(int i=0;i<wordList.size();i++){
                if(vis[i]){continue;}
                for(int j=0;j<beginWord.size();j++){
                    if(w[j]!=wordList[i][j]){ct++;}
                }
                if(ct==1){q.push({wordList[i],l+1});vis[i]=1;}
                ct=0;
            }
        }
       return 0; 
    }
};