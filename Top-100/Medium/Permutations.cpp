// Loop through the array, in each iteration, a new number is added to different
// locations of results of previous iteration. Start frokm an empty list.

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        queue<vector<int>> permutations;
        vector<vector<int>> ans;
        permutations.push(vector<int>());   // push an empty array
        for (auto num : nums) {
            int n = permutations.size();
            for(int i = 0; i < n; i++) {
                // for every current permutation in the queue add the current
                // number at every point possible in the list
                vector<int> oldPermutataion = permutations.front();
                permutations.pop();
                for (int j = 0; j <= oldPermutataion.size(); j++) {
                    vector<int> newPermutation(oldPermutataion);
                    newPermutation.insert(newPermutation.begin() + j, num);
                    permutations.push(newPermutation);
                    // If newPermutation size is equal to the originl array size
                    // Add it to the ans as one possible permutation
                    if (newPermutation.size() == nums.size())
                        ans.push_back(newPermutation);
                }
            }
        }

        return ans;
    }
};

// Solution 2 - with built in STL function
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        do {
            res.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));

        return ans;
    }
}
