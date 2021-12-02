#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#include <regex>
#include <unordered_set>


using namespace std;

int longestSpike (vector<int> &arr) {
    
    vector<int> visited(arr.size());
    unordered_set<int> inc, dec;
    int maxVal = INT_MIN;

    for (int i = 0; i < arr.size(); i++) {

        if (inc.find(arr[i]) == inc.end()) {
            inc.insert(arr[i]);
            visited[i] = 1;
        }
        maxVal = std::max (arr[i], maxVal);
    }

    for (int i = 0; i < arr.size(); i++) {

        if (visited[i] != 1 && arr[i] != maxVal)
            dec.insert(arr[i]);
    }

    return inc.size() + dec.size();
}

int main() {

    vector<int> arr1 = {1, 2};
    vector<int> arr2 = {2, 5, 3, 2, 4, 1};
    vector<int> arr3 = {2, 3, 3, 2, 2, 2, 1};

    cout << longestSpike(arr1) << endl;
    cout << longestSpike(arr2) << endl;
    cout << longestSpike(arr3) << endl;

    return 0;
}