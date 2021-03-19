// Solution 1: 
// T: constructor : O(K), add : O(1), showForstUnique : O(1) - amortized

class FirstUnique {
    queue<int> q;
    unordered_map<int, bool> isUnique;
public:
    FirstUnique(vector<int>& nums) {
        for (int n : nums) add(n);
    }
    
    int showFirstUnique() {
        // we need to start by cleaning thr queue of any non-unique
        // values at the start.
        while (!q.empty() && (isUnique.count(q.front()) && !isUnique[q.front()])) q.pop();

        // check if still there exists any value int the queue.
        // There might me no uniques
        if (!q.empty()) return q.front(); // we don't actually remove the value

        return -1;
    }
    
    void add(int value) {
        // case 1: We need to add the number to the queue and mark it as unique.
        if (isUnique.find(value) == isUnique.end()) {
            isUnique[value] = true;
            q.push(value);
        }
        // case 2 & 3: We need to mark the number as no longer unique.
        else {
            isUnique[value] = false;
        } 
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */


// Solution 2
