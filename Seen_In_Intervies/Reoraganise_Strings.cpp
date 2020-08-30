// Approach I -
class Solution {
public:
    string reorganizeString(string S) {
        vector<int> cnt(26);
        int mostFreq = 0, i = 0;

        for(char c : S)
            if(++cnt[c - 'a'] > cnt[mostFreq])
                mostFreq = c - 'a';

        if(2 * cnt[mostFreq] - 1 > S.size()) return "";

        while(cnt[mostFreq]) {
            S[i] = ('a' + mostFreq);
            i += 2;
            cnt[mostFreq]--;
        }

        for(int j = 0; j < 26; j++) {
            while(cnt[j]) {
                if(i >= S.size()) i = 1;
                S[i] = ('a' + j);
                cnt[j]--;
                i += 2;
            }
        }

        return S;
    }
};



// Approach II - c create a max heap
class Solution {
public:
    string reorganizeString(string S) {
        string res = "";
        map<char,int> cntMap;
        for(int i = 0; i < S.size(); ++i) {
            cntMap[S[i]]++;
        }

        priority_queue<pair<int,char>> pq;
        for(auto p : cntMap) {
            if(p.second > (S.size()+1)/2) return "";
            pq.emplace(p.second,p.first);
        }
        pair<int,char> prev(0,' ');
        while(!pq.empty()) {
            auto curr = pq.top();
            //cout << curr.first << " " << curr.second << endl;
            pq.pop();
            res += curr.second;
            --curr.first;
            if(prev.first>0) {
                pq.emplace(prev);
            }
            // curr was used to construct res, its removed now so that
            //  in the next iteration we don't look at it.
            prev = curr;
        }

        return res;
    }
}


// Approach III
// Use an unor_map to count occurence
// use priority queue to store the occurenece,

class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> mp;
        for(auto c : S)
            mp[c]++;

        priority_queue<pair<int, char>> pq;
        for(auto x : mp) {
            if(x.second > (S.length()+1)/2) return "";
            pq.push({x.second, x.first});
        }

        string res;
        while(pq.size()>=2) {
            auto tmp1 = pq.top(); pq.pop();
            auto tmp2 = pq.top(); pq.pop();
            res.push_back(tmp1.second);
            res.push_back(tmp2.second);
            if(--tmp1.first > 0) pq.push(tmp1);
            if(--tmp2.first > 0) pq.push(tmp2);
        }
        if(!pq.empty())
            res.push_back(pq.top().second);
        return res;
    }
};


// Approach IV
class Solution {
public:
    string reorganizeString(string S) {
        vector<int> mp(26);
        int n = S.size();
        for (char c: S) ++mp[c-'a'];
        vector<pair<int, char>> charCounts;
        for (int i = 0; i < 26; ++i) {
            if (mp[i] > (n+1)/2) return "";
            if (mp[i]) charCounts.push_back({mp[i], i+'a'});
        }
        sort(charCounts.rbegin(), charCounts.rend());
        string strSorted;
        for (auto& p: charCounts)
            strSorted += string(p.first, p.second);
        string ans;
        for (int i = 0, j = (n-1)/2+1; i <= (n-1)/2; ++i, ++j) {
            ans += strSorted[i];
            if (j < n) ans += strSorted[j];
        }
        return ans;
    }
}
