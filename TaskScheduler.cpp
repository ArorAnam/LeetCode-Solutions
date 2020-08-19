class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.empty()) return 0;
        if(n == 0) return tasks.size();

        unordered_map(char, int) freq;
        for(char ch : tasks) freq[ch]++;
        priority_queue<pair<int, char>> pq;
        for(auto task: freq) pq.emplace_back(task.second, task.first);

        int res = 0;
        while(true) {
            vector<pair<int, char>> temp;
            temp.reserve(n+1);
            for(int i=0; i < n+1; i++) {
                //add idle
                if(pq.empty()) {
                    if(!temp.empty()) {
                        res++;
                        continue;
                    }
                    else continue;
                }
                auto task = pq.top();
                pq.pop();
                if(--task.first != 0) temp.push_back(task);
                res++;
            }
            if(!temp.empty())
                for(auto i : temp) pq.push(i);
            else if(pq.empty()) return res;
        }
    }
};


//Solution 2 - key is to go through n items in the pq at a time
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        unordered_map<char, int> cnt;
        for(auto i:tasks){
            cnt[i]++;
        }
        for(auto i:cnt){
            pq.push(i.second);
        }
        int alltime = 0;
        while(!pq.empty()){
            vector<int> tmp;
            int last_time = 0;
            for(int i=0; i<=n; i++){
                if(!pq.empty()){
                    tmp.push_back(pq.top());
                    pq.pop();
                    last_time++;
                }
            }
            for(int i=0; i<tmp.size(); i++){
                if(--tmp[i]){
                    pq.push(tmp[i]);
                }
            }
            alltime += pq.empty() ? last_time : n+1;
        }
        return alltime;
    }
};

//Solution -3: math method
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0) return tasks.size();
        unordered_map<char, int> cnt;
        for(auto i:tasks){
            cnt[i]++;
        }
        int max_freq = 0;
        int max_cnt = 0;
        for(auto i: cnt){
            if(i.second > max_freq){
                max_freq = i.second;
                max_cnt = 1;
            }
            else if(i.second == max_freq) max_cnt++;
        }
        int avaliable_slots = n - (max_cnt-1);
        int empties = (max_freq-1) * avaliable_slots;
        int idles = max(0, (int)(empties - (tasks.size() - max_cnt * max_freq)));
        return idles + tasks.size();
    }
};
