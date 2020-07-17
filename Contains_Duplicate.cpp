#include <iostream>
#include <vector>

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if(nums.size() == 1 || nums.empty())
        return false;

    for(int i = 0; i < nums.size(); i++) {
        for(int j = 0; j < nums.size(); j++) {
            if(i == j) continue;
            if(abs(nums[i] - nums[j]) <= t && abs(i - j) <= k)
                return true;
        }
    }
    return false;
}

int main() {
    int k, t;
    vector<int> nums = {-1,2147483647};
    k = 1;
    t = 2147483647;

    cout << containsNearbyAlmostDuplicate(nums, k, t) << endl;
    
    return 0;
}