class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        std::next_permutation(nums.begin(), nums.end());
    }
};

// Solution 2 :
// 1. From the right find the first number not in the descending order
// 2. Swap the found number with the closest greater(or smallest greater)
//    element on the right of it.
// 3. Sort the numbers after the position of number found in step 1.
// Some optimazations
// 1. Since the sequence is sorted in decreasing order, we can use binary
//    to find the closest element.
// 2. Since the sequence is already sorted in decreasing order(even after swapping
//    as we swapped with the closest greater), we can get the sequence sorted
//    in increasing order) after reversing it.
// Time : O(n) + O(logn) + O(n)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1)
            return;
        int i,j,f=1;
        for(i=nums.size()-2;i>=0;i--){  //for finding the first decreasing element
            if(nums[i]<nums[i+1]){
                f=0;
                break;
            }
        }
        if(f)
            reverse(nums.begin(),nums.end());   // if all are increasing then simply reverse the array
        else
        {
            for(j=nums.size()-1;j>i;j--){           //for finding the next larger element than at index i
                if(nums[j]>nums[i])
                    break;
            }
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1,nums.end());        // reversing array from index i to end
        }
    }
};
