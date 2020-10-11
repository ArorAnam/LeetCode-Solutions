// Naive Approach - Given an array the the solution is to find the maximum
// sum subsequence where no two selected elements are adjacent. Recursive Approach
// 1. If an element is selected then the next element cannot be selected
// 2. If an element is not selected then the next element can be selected.
// Time : O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        int dp[n];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
            dp[i] = max(dp[i] + dp[i - 2], dp[i - 1]);

        return dp[n - 1];
    }
};


// Soltiuon 2 - Avoiding the space
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int value1 = nums[0];
        if (n == 1)
            return value1;
        int value2 = max(nums[0], nums[1]);
        if (n == 2)
            return value2;

        int max_val;

        for (int i = 2; i < n; i++) {
            max_val = max(value1 + nums[i], value2);
            value1 = value2;
            value2 = max_val;
        }

        return max_val;
    }
};
