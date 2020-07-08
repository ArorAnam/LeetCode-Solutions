class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> genSet;

        if(nums.size() < 3)
            return {genSet.begin(), genSet.end()};

        int sum = 0;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++) {
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                sum = 0 - nums[i];
                int x = i+1, y = nums.size()-1;

                while (x < y) {
                    if (nums[x] + nums[y] == sum) {
                        //vector<int> temp = {nums[i], nums[x], nums[y]};
                        genSet.insert({nums[i], nums[x], nums[y]});

                    } else if (nums[x] + nums[y] < sum) {
                        x++;
                    } else
                        y--;
                }
            }
        }

        return {genSet.begin(), genSet.end()};
    }
};