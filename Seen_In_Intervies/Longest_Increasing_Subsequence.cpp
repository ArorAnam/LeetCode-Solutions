// T: O(n^2)
// S: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> dp(n, 0);
        dp[0] = 1;

        //bottom up manner
        for (int i = 1; i < n; i++) {
            int temp = 0;
            for (int j = 0; j < i; i++) {
                if (nums[j] < nums[i])
                    temp = max(temp, dp[j]);
            }
            dp[i] = temp + 1;
        }

        int ans = 0;
        for (int x : dp)
            ans = max(ans, x);

        return ans;
    }
};

// Soltion 2 -
// T; O(NlogN)
class Solution {
    int CeilIndex(vector<int>& v, int i, int l, int r, int key) {
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (v[m] >= key)
                r = m;
            else
                l = m;
        }
        return r;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> tail(n, 0);
        int length = 1; // always points to an empty slot in tail

        tail[0] = nums[0];
        for (size_t i = 1; i < n; i++) {
            // new smallest value
            if (nums[i] < tail[0])
                tail[0] = nums[i];

            // nums[i] extends largest subsequence
            else if (nums[i] > tail[length - 1])
                tail[length++] = nums[i];

            // v[i] will become end candidate of an existing
            // subsequence or Throw away larger elements in all
            // LIS, to make room for upcoming grater elements
            // than v[i] (and also, v[i] would have already
            // appeared in one of LIS, identify the location
            // and replace it)
            else
                tail[CeilIndex(tail, -1, length - 1, nums[i])] = nums[i];
        }

        return length;
    }
};

// Soltion 3
// user lower_bound instead of binary search
class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        if (v.size() == 0)
            return 0;

        std::vector<int> tail(v.size(), 0);
        int length = 1; // always points empty slot in tail

        tail[0] = v[0];

        for (int i = 1; i < v.size(); i++) {

            // Do binary search for the element in
            // the range from begin to begin + length
            auto b = tail.begin(), e = tail.begin() + length;
            auto it = lower_bound(b, e, v[i]);

            // If not present change the tail element to v[i]
            if (it == tail.begin() + length)
                tail[length++] = v[i];
            else
                *it = v[i];
        }
        return length;
    }
};
