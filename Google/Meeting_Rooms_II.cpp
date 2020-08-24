#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// Strategy
// When a room is taken, the room can not be used for another meeting
// until the current meeting is over.
// We can sort the meetings by start timestamps and sequentially assign
// each meeting a room. Each time when we assign a room for a meeting
// we check if any other meeting is finished, so that its room can be reused
// In order to effciently track the earliest ending meeting
// we can use min heap.

// T: O()

int minMeetingRooms(vector<pair<int, int>> intervals) {
    sort(intervals.begin(), intervals.end());

    priority_queue<int, vector<int>, greater<int>> heap;
    int count = 0;
    for(auto x : intervals) {
        if(heap.empty()) {
            count++;
            heap.push(x.second);
        }
        else {
            if(x.first >= heap.top())
                heap.pop();
            else
                count++;
            heap.push(x.second);
        }
    }
    return count;
}

int main() {
    vector<pair<int, int>> intervals = {{2,15}, {36,45}, {9,29}, {16,23}, {4,9}};
    cout << minMeetingRooms(intervals) << '\n';
    return 0;
}
