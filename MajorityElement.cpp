// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         map<int, int> m;
//
//         for(int x : nums) {
//             m[x]++;
//             if(m[x] > nums.size()/2) {
//                 return x;
//             }
//         }
//         return -1;
//     }
// };

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int mj = nums[0], cnt = 1;
//         for(int i=1; i<nums.size(); i++) {
//             if(cnt == 0) {
//                 cnt++;
//                 mj = nums[i];
//             }
//             else if(mj == nums[i])
//                 cnt++;
//             else
//                 cnt--;
//         }
//         return mj;
//     }
// };


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
