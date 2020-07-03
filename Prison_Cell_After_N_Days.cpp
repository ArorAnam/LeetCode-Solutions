class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> temp (8);
        vector<vector<int>> seen;

        while(N--) {
            for(int j = 1; j < 7; j++)
                temp[j] = cells[j-1] == cells[j+1];

            if(seen.size() && seen.front() == temp)
                return seen[N % seen.size()];
            else
                seen.push_back(temp);

            cells = temp;
            // cout<<"[ ";
            // for(int j = 0; j<8; j++) 
            //     cout<<cells[i]<<", ";
            // cout<<"]"<<endl;
        }
        return cells;      
    }
};
