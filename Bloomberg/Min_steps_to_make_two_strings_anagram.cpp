class Solution {
public:
    int minSteps(string s, string t) {
        int cnt[26] = {};
        for (auto ch : s) ++cnt[ch - 'a'];
        for (auto ch : t) --cnt[ch - 'a'];
        return accumulate(begin(cnt), end(cnt), 0, [](int s, int n) {return s + abs(n);}) / 2;
    }
};

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freqS(26), freqT(26);

        for (int i = 0; i < s.size(); i++) {
            freqS[s[i] - 'a']++;
            freqT[t[i] - 'a']++;
        }

        int minSteps = 0;
        for (int i = 0; i < freqS.size(); i++) {
            if (freqS[i] > 0 && freqS[i] > freqT[i])
                minSteps += freqS[i] - freqT[i];
        }

        return minSteps;
    }
};

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int, int> m;
        for (auto c : s) ++m[c];    
        for (auto c : t) --m[c];

        int res = 0;
        for (auto &[a, b] : m) res += abs(b);

        return res / 2;
    }
};