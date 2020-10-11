// Map order and calculate total score

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.size() == 1)
            return true;

        unordered_map<char, int> idx;
        for (int i = 0; i < order.length(); i++) {
                idx[order[i]] = i;
            }

        unordered_map<string, int> scores;
        for (int i = 0; i < words.size(); i++) {
            for (auto x : words[i])
                scores[words[i]] += idx[x];
        }

        auto elem = scores.begin()->second;
        for (auto &word : scores) {
            if (word.second > elem)
                return false;
            elem = word.second;
        }

        return true;
    }
};

// SOLUTION 2
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        if( words.empty() ) return false;

        vector<int> order_arr( 26, 0 );
        for( int i = 0 ; i < order.length(); ++i  ){
            order_arr[order[i] - 'a'] = i;
        }

        int N = words.size();

        for( int i = 0 ; i < N - 1; ++i ) {
         string first = words[i];
         string second = words[i+1];

         int j = 0;
         while( j < first.size() ) {
             if( first[j] == second[j])
                 ++j;
             else if( j >= second.size() || order_arr[first[j] - 'a' ] > order_arr[second[j] -  'a'])
                 return false;
             else break;
            }
        }

        return true;
    }
};
