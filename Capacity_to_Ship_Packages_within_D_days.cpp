class Solution {
    bool canShip(vector<int>& weights, int capacity, int D) {
        int days = 1, total = 0;
        for (auto w : weights) {
            total += w;
            if (total > capacity) {
                days++;
                // what packages appeared before have been sent the
                // previous day, now this next day  contians
                // the current packet.
                total = w;
            }
            if (days > D)
                return false;
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int n = weights.size();
        int total = 0, maxWeight = 0;
        for (auto w : weights) {
            total += w;
            if (w > maxWeight)
                maxWeight = w;
        }

        int l = maxWeight, r = total;
        int ans = 0;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (canShip(weights, mid, D)) {
                r = mid - 1;
                ans = mid;
            }
            else l = mid + 1;
        }

        return ans;
    }
};

// Soltion 2
