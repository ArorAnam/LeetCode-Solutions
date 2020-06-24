class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int low_bits=0, high_bits=0;

        for(int i=0;i<nums.size();i++) {
            low_bits = ~high_bits & (low_bits ^ nums[i]);
            high_bits = ~low_bits & (high_bits ^ nums[i]); 
        }
        return low_bits;
    }
};