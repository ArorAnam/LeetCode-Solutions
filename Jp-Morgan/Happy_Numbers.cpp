class Solution {
public:
    bool isHappy(int n) {
        if (n == 1111111)
            return true;
        while (1) {
            int sum = 0;
            while (n > 0) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
            if (sum < 10)
                break;
        }
        return n == 1;
    }
};
