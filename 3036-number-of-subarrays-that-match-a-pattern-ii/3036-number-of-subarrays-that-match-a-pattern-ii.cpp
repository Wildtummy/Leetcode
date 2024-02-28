class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        
                vector<int>v(nums.size()+pattern.size()),lps(nums.size()+pattern.size());
        for(int i=0;i<pattern.size();i++){v[i]=pattern[i];}
        v[pattern.size()]=10;
        for(int i=1;i<nums.size();i++){
           if( nums[i]>nums[i-1]){v[i+pattern.size()]=1;}
            if( nums[i]<nums[i-1]){v[i+pattern.size()]=-1;}
            
            
        }
       
        int i=1,len=0;
        while(i<nums.size()+pattern.size()){
           if(v[i]==v[len]){len++;lps[i]=len;i++;}
            else{if(len>0){len=lps[len-1];}else{lps[i]=0;i++;}}  
        }
       
        
        int k=0;
        for(int i=0;i<nums.size()+pattern.size();i++){if(lps[i]==pattern.size()){k++;}}
        return k;
        
    }
};