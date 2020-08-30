class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<vector<int>> buckets(nums.size()+1);
        for(auto & k : freq) buckets[k.second].push_back(k.first);

        vector<int> res;
        for(auto bucket : buckets.rbegin(); bucket != buckets.rend(); bucket++) {
            for(auto i : *bucket) {
                res.push_back(i);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};

// Solution 2
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		multimap<int,int,greater<int>> mmap;
		unordered_map<int,int> ummap;
		vector<int> res;

		for(auto num : nums)
			ummap[num]++;

		for(auto itr : ummap)
			mmap.insert({itr.second,itr.first});

		while(k--)
		{
			res.push_back(mmap.begin()->second);
			mmap.erase(mmap.begin());
		}
		return res;
	}
};

// Solution 3
class Solution {

    static bool comp(pair<int,int>& p1,pair<int,int>& p2)
    {
        return p1.second > p2.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> ans;
        vector<pair<int,int>> vvi;

        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;

        for(auto a: mp)
            vvi.push_back({a.first,a.second});

        sort(vvi.begin(),vvi.end(),comp);

        for(int i = 0;i < k ;i++)
            ans.push_back(vvi[i].first);

        return ans;
    }
};
