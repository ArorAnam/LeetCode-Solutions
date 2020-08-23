// Soltion 1

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k =  k%n;

        // reverse the first n-k elements
        reverse(nums.begin(), nums.begin() + n - k);

        // reverse the last k elements
        reverse(nums.begin() + n - k, nums.begin() + n);

        // reverse all the elements
        reverse(nums.begin(), nums.begin() + n);
    }
};
