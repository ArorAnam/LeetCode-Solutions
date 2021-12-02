// Approach 1: Recursive with memoization
// using two digits or single
// etner into recursion until the string can be decoded, when cannnot be, we backtrack
// overllaping problems -> memoization
// Algo:
// start witn idx = 0
// for termination, check for enf of string: if end of string: return 1
// start with 0: return 0
// check dict memo if this substring already exists
// idx + 1, idx + 2 -> for 2 digits
// save above result in memo for future overlapping

class Solution {
public:
    map<int, int> mp;

    int numDecodingsHelper(int idx, string &str) {
        // check is already there
        if (mp.find(idx) != mp.end()) {
            return mp[idx];
        }

        // if end of the string
        // ends normally
        if (idx == str.length()) return 1;

        // it is zero
        if (str[idx] == '0') return 0;

        if (idx == str.length() - 1) return 1;

        int ans = numDecodingsHelper(idx + 1, str);
        if (stoi(str.substr(index, 2)) <= 26) {
            ans += numDecodingsHelper(idx + 2, str);
        }

        mp[idx] = ans;

        return ans;
    }

    public int numDecodings(String s) {
        numDecodingsHelper(0, s);
    }
};