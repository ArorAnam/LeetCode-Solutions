
//first pos >= target -> lower_bound and first pos >= x+1
class Solution {
    int first_pos(vector<int>& nums, int target) {
        int n = nums.size();
        int first_pos = n; // first >= x
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(nums[mid] >= target) {
                first_pos = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return first_pos;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = first_pos(nums, target);
        int last = first_pos(nums, target+1) - 1;
        if(first <= last) {
            return {first, last};
        }
        return {-1, -1};
    }
};

// SLoution 2:
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it1 = std::lower_bound(nums.begin(), nums.end(), target);
        auto it2 = std::upper_bound(nums.begin(), nums.end(), target);
        if (it1 != nums.end() && *it1 == target)
            return {it1 - nums.begin(), it2 - nums.begin()};
        return {-1, -1};
    }
};
