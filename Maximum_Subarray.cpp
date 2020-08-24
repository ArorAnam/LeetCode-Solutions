class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = nums[0], max_ending_here = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            max_ending_here += nums[i];
            max_ending_here = max(nums[i], max_ending_here);
            max_so_far = max(max_so_far, max_ending_here);
        }
        return max_so_far;
    }
};
