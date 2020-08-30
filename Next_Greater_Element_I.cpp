class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> s;

        for(int n : nums2) {
            while(s.size() && s.top() < n) {
                mp[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }

        vector<int> res;
        for(int n : nums1) res.push_back( mp.count(n) ? mp[n] : -1 );

        return res;
    }
};
