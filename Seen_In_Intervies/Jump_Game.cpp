// Solution 1:
// Naive approach
// A naive approach is to start from the first element and recursively call
// for all the elements reachable from first element. The minimum number of
// jumps to reach end from first can be calculated using minimum number of
// jumps needed to reach end from the elements reachable from first.
// minJumps(start, end) = Min(minJumps(k, end)) for all k reachable from start

class Solution {
    int minJumps(vector<int>& nums, int n) {
        if (n == 1)
            return 0;

        int res = INT_MAX;
        for (int i = n - 2; i >= 0; i--) {
            if (i + nums[i] >= n - 1) {
                int sub_res = minJumps(nums, i + 1);
                if (sub_res != INT_MAX)
                    sub_res = min(res, sub_res + 1);
            }
        }

        return res;
    }
public:
    int jump(vector<int>& nums) {

        return minJumps(nums, nums.size());
    }
};

// Time : O(n^2)
// As there are maximum n possible ways to move from an element.
// Space : O(1)


// SOLUTION 2: Dynamic Programming
// 1. Let dp[i] denote the min no. of jumps needed to reach nums[i] from nums[0]
// 2.if i < j + nums[j]
// dp[i] = min(dp[i], dp[j] + 1)
// return dp[n-1]
class Solution {
    template <typename T, size_t N>
    T* end(T (&pX)[N])
    {
        return pX + N;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || nums[0] == 0 || n == 1)
            return 0;

        int dp[n];
        std::fill(dp, dp + n, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int diff = nums[i];
            for (int j = 1; j <= diff; j++) {
                int newIndex = i + j;
                if (newIndex >= nums.size() - 1)
                    return dp[i] + 1;
                dp[newIndex] = min(dp[i] + 1, dp[newIndex]);
            }
        }

        return dp[n - 1];
    }
};

// Time : O(n^2)


// SOLUTION 3 : Dynamic Programming
// In this method we build dp array from right to left such that dp[i]
// indicates the minimum no. of jumps to reach nums[n-1] from nums[i]
// Finally return nums[0]

// SOLUTION 4
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1 || nums[0] == 0)
            return 0;

        int maxReach = nums[0], step = nums[0], jump = 1;

        for (int i = 1; i < n; i++) {
            if (i == n - 1)
                return jump;

            maxReach = max(maxReach, i + nums[i]);

            step--;

            if (step == 0) {
                jump++;
                if (i >= maxReach)
                    return -1;
                step = maxReach - i;
            }
        }

        return -1;
    }
};
