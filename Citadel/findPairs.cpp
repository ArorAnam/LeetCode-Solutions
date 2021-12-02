// Solution 1: using Binatry Search

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int n=nums.size();
        int ans=0;
        
        for(int i=0;i<n-1;i++){
            if(i&&nums[i]==nums[i-1])
                continue;
            int v=nums[i];
            int rem=k+v;
            auto itr=std::lower_bound(nums.begin()+i+1,nums.end(),rem);
            if(itr!=nums.end())
                if(*itr==rem)
                {
                    ans++;
                }
        }
        return ans;
    }
};

// Solution 2: Using maps

unordered_map<int,int> mp;
    int ans=0;
    
    for(int i=0;i<nums.size();i++)
    {
        int key=nums[i];
        
        if(mp.count(k+key) && mp.count(key)==0){
            ans++;
            }
        
        if(mp.count(key-k) && mp.count(key)==0){    
       ans++;
        }
        
        mp[key]++;
    }
    
    if(k==0)
    {
        int x=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            
            if(it->second>=2)
                x=x+1;
        }
        
        return x;
    }
    
    return ans;
}
};