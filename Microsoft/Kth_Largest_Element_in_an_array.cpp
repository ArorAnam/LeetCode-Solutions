class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int>> heap;

        for (int x : nums) {
            heap.push(x);
            if (heap.size() > k) heap.pop();
        }

        return heap.top();
    }
};


// Solution 2 :: Quickselect
// T: O(N) - average, O(N ^ 2) - worst case, S: O(1)

class Solution {
    vector<int> nums;
public:
    void swap (int a, int b) {
        int tmp = this->nums[a];
        this->nums[a] = this->nums[b];
        this->nums[b] = tmp;
    }

    int partition(int left, int right, int pivot_index) {
        int pivot = this->nums[pivot_index];
        // 1. move pivot to end
        swap (pivot_index, right);
        int store_index = left;

        // 2. move all smaller elements to the left
        for (int i = left; i <= right; i++) {
            if (this->nums[i] < pivot) {
                swap (store_index, i);
                store_index++;
            }
        }

        // 3. move pivot to its final place
        swap (store_index, right);

        return store_index;
    }

    int quickselect(int left, int right, int kth_smallest) {
        if (left == right)
            return this->nums[left];

        // select a random pivot index
        int pivot_index = left + rand() % (right - left);

        pivot_index = partition(left, right, pivot_index);

        if (kth_smallest == pivot_index) 
            return this->nums[kth_smallest];
        // go to left side
        else if (kth_smallest < pivot_index)
            return quickselect(left, pivot_index - 1, kth_smallest);
        // go to right side
        return quickselect(pivot_index + 1, right, kth_smallest);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        this->nums = vector<int>(n);
        this->nums = nums;
        srand(time(0));
        return quickselect(0, n - 1, n - k);
    }
};