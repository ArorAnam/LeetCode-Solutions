class Solution {
public:
    int numWays(self, n, k) {
        if (k == 0 || n == 0)
            return 0;
        if (n == 1)
            return k;

        int same = k, diff = k * (k - 1);
        for (int i = 3; i <= n; i++) {
            same = diff;
            diff = (same + diff) * (k - 1);
        }

        return same + diff;
    }
};
