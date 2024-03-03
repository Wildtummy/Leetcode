class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long ans=0;
        // int i=0;
        // sort(nums.begin(),nums.end());
        multiset<long long> s(nums.begin(),nums.end());
        // while(nums[i]<k && i!=nums.size()){s.insert((long long)nums[i]);i++;}
      // for(auto k:s){cout<<k<<" ";}cout<<endl;
        while(*s.begin()<k){
            long long l=*s.begin(); s.erase(s.begin());
            long long r=*s.begin(); s.erase(s.begin());
            long long a=(2*l)+r;
            s.insert(a);
           // cout<< l<<" "<<r<<endl;
         ans++;
        }
          // cout<<s.size()<<" ";
        // cout<<*s.begin()<<endl;
        // if(s.size()){ans++;}
       
        return ans;
    }
};