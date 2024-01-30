class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         vector<int> ans;
        for(auto i:nums1){
            bool b=0;
            for(auto j:nums2)
            {if(j==i){b=1;}
            if(b && j>i){ans.push_back(j);b=0;break;}}
            if(b){ans.push_back(-1);b=0;}
        }
        return ans;
    }
};