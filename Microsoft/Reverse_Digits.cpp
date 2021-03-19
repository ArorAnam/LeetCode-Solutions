#include <iostream>

using namespace std;

class Solution {
public:
    // T: O(log10(x)), S: O(1)
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

class Solution2 {
public:
    // T: O(log10(x)), S: O(1)
    int reverse(int x) {
        string sx(to_string(x));
        if(sx[0] == '-')
            std::reverse(sx.begin()+1, sx.end());
        else
            std::reverse(sx.begin(), sx.end());
        long long lres = stoll(sx);
        if(lres > numeric_limits<int>::max() or lres < numeric_limits<int>::min())
            return 0;
        else
            return lres;
    }
};

class Solution3 {
public:
    // T: O(log10(x)), S: O(1)
    int reverse(int x) {
        long z = x;        

        string s = to_string(z);
        if (z < 0)
            s.push_back('-');
        std::reverse(s.begin(), s.end());     

        long y = stoll(s);
        if (y > INT32_MAX || y < INT32_MIN)
        return 0;
        
        return y;
    }
};

int main() {
    Solution2 *example = new Solution2();

    cout << example->reverse(-439845573) << endl;

    return 0;
}