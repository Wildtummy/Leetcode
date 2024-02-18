class Solution {
public:
    bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to square root of n
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}
    int mostFrequentPrime(vector<vector<int>>& mat) {
         pair<int,int> v[]={{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
        map <int,int> m;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                for(auto k:v){
                    int x=i,y=j;
                    int num=0;
                    
                    while(x<mat.size() && y<mat[0].size()){
                       
                        num=(10*num)+mat[x][y];
                        m[num]++; x+=k.first;y+=k.second;
                        
                    }
                }
            }
            
        }
       
        int mx=0,ans=-1;
        for(auto i:m){
            if(i.second>=mx && isPrime(i.first) && i.first>10){mx=i.second;ans=i.first;}
        }
        return ans;
        
    }
};