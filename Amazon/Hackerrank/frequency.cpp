#include <iostream>
#include <vector>
#include <string>

using namespace std;

void frequency (string S) {

    vector<int> res(26, 0);

    for (int i = 0; i < S.length(); ) {

        if (i+2 < S.length() && S[i + 2] == '#') {
            int c1 = S[i] - '0';
            int c2 = S[i + 1] - '0';
            int c3 = (c1 * 10) + c2;
            if (S[i + 3] == '(') {
                int k = i + 4, l = k;
                while (S[l] != ')') l++;
                int count = stoi(S.substr(k, l-1));
                res[c3 - 1] += count;
                i = l + 1;
            }
            else {
                res[c3 - 1]++;
                i += 3;
            }
        }
        else if (i+1 < S.length() && S[i + 1] == '(') {
            int k = i + 2, l = k;
            while (S[l] != ')') l++;
            int count = stoi(S.substr(k, l-1));
            res[int(S[i] - '0') - 1] += count;
            i = l + 1;
        }
        else {
            res[int(S[i] - '0') - 1]++;
            i++;
        }
    }

    for (auto x : res) cout << x << " ";
    //return res;
}

int main() {
    frequency("23#(2)2(56)24#25#(2345)26#5723#(31)");
    return 0;
}