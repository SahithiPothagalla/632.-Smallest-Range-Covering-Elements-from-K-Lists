class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> vp;

        for(int i=0;i<nums.size();i++){
            for(auto it:nums[i]){
                vp.push_back({it,i});
            }
        }
        sort(vp.begin(),vp.end());
        int mini=1e9;
        vector<int> ans;
        int j=0;
        int diff=nums.size();
        int total=0;

        int n=vp.size();
        unordered_map<int,int> um;

       

        for(int i=0;i<n;i++){
            auto a=vp[i];
            um[a.second]++;
            if(um[a.second]==1)total++;
            if(total==diff){
                if(a.first-vp[j].first+1<mini){
                    mini=a.first-vp[j].first+1;
                    ans={vp[j].first,a.first};
                }
            }
            if(total==diff){
                while(total==diff){
                    if(um[vp[j].second]>1) {
                        um[vp[j].second]--;j++;
                    }
                    else break;
                }
                if(a.first-vp[j].first+1<mini){
                    mini=a.first-vp[j].first+1;
                    ans={vp[j].first,a.first};
                }
                 
            }
        }


        return ans;
    }
};
