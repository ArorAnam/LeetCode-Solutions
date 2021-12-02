class Solution {
    public int minNumberOperations(int[] target) {
        if (target.length == 1)
            return target[0];
        
        int result = target[0];
        
        // 3,1,5,4,2
        // 1,2,3,2,1

        for (int i = 1; i < target.length; i ++) {
            if (target[i]>target[i-1]) {
                result += target[i]-target[i-1];
            }
        }
        
        return result;
    }
}