// Solution 1: We have to take window of size segement length and
// find the minimun from this window and finally we have to return the
// maximum of all minimum we found.

class Solution {
public:
    queue q;
    deque d;

    void insert(int p) {
        if (d.size() == 0) {
            d.push_back(p);
            q.push(p);
        }
        else {
            while (!d.empty() && d.back() < p)
                d.pop_back();
            d.push_back(p);
            q.push(p);
        }
    }

    void pop() {
        if (q.front() == d.front()) {
            d.pop_front();
            q.pop();
        }
        else {
            q.pop();
        }
    }

    int getMax() {
        if (d.size() == 0)
            return INT_MIN;
        else
            return d.front();
    }

    vector<int> maxSlidningWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        if (n == 0)
            return ans;

        for (int i = 0; i < k; i++)
            insert(nums[i]);

        ans.push_back(getMax());
        for (int i = 1; i <= n - k; i++) {
            pop();
            insert(nums[i + k - 1]);
            ans.push_back(getMax());
        }

        return ans;
    }
};
