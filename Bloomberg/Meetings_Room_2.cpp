int minMeetingRooms(vector<vector<int>>& intervals) {
        if(!intervals.size())
            return 0;
        int res = 0;
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<>> pq;
        pq.push(intervals[0][1]);
        res++;
        for(int i = 1; i < intervals.size(); i++) {
            if(pq.size()) {
                auto p = pq.top();
                if(p > intervals[i][0])
                    res++;
                else
                    pq.pop();
                 pq.push(intervals[i][1]);
            }
        }
        return pq.size();
    }