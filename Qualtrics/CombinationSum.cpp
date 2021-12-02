







class Solution {
public:
    
    vector<int>num;
    int *dp;
    // top down approach using memoization.
    // Find the solution for the target element. If already found then return it
    // otherwise calculate the result for that element. and memoize it in the dp array.
    // This way we can avoid recomputation of the solution.
    // Find the solution for target by summing the combination after removing a particular coins.
    // do it for all the coins.
    int recur(int target){
        if(target < 0)
            return 0;
        if(dp[target] != -1)
            return dp[target];
        int sum = 0;
        for(int i=0;i<num.size();i++){
            sum += recur(target - num[i]); 
        }
        dp[target] = sum;
        return sum;
    }
    
    // initialize the dp value as -1 which will indicate we haven't found the solution for that amount
    // initialize for amount 0 as 0 as we can make it by not taking any element.
    int combinationSum4(vector<int>& nums, int target) {
        num = nums;
        dp = new int[target+1];
        dp[0] = 1;
        for(int i=1;i<=target;i++){
            dp[i] = -1;
        }
        recur(target);
        
        return dp[target];
    }
};