class Solution {
public:
    void generateSubsets(vector<int>& nums, int idx, vector<vector<int>>& result) {
        if(idx == nums.size()-1) {
            result.push_back({});
            result.push_back({nums[idx]});
        }
        else {
            generateSubsets(nums, idx+1, result);
            int n = result.size();
            for(int  i = 0; i < n; i++) {
                vector<int> r = result[i];;
                r.push_back(nums[idx]);
                result.push_back(r);
            }
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty())
            return {{}};

        vector<vector<int>> result;
        generateSubsets(nums, 0, result);

        return result;
    }
};
