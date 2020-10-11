


class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<string, int> item;
        map<int, unordered_map<int, int>> table;
        int i = 0;

        // add food items to item map and see their index
        for (auto o : orders) item[o[2]] = 0;
        for (auto e : item  ) item[e.first] = i++;

        // add items to table map
        for (auto o : orders) table[stoi(o[1])][item[o[2]]]++;

        // Initialize return vector and add header
        vector<vector<string>> ret(table.size() + 1, vector<string>());
        i = 0; ret[i].push_back("Table");
        for (auto e : item) ret[i].push_back(e.first); i++;

        // add rows to return vector
        for (auto e : table) {
            int j = 0;
            ret[i].push_back(to_string(e.first));   // table no.
            while (j < item.size()) ret[i].push_back(to_string(e.second[j++]));     //item count
            i++;
        }

        return ret;
    }
};


// Soltion - 2
#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string>col;
        set<int> row;
        map<string,int> m1;
        map<string,int> m2;
        for(int i=0;i<orders.size();i++){
            int x=stoi(orders[i][1]);
            col.insert(orders[i][2]);
            row.insert(x);
        }
        vector< vector<string> > ans(row.size()+1,vector<string>(col.size()+1,"0"));
        ans[0][0]="Table";
        int i=1;
        for(auto e:col){
            ans[0][i]=e;m1[e]=i;i++;
        }
        i=1;
        for(auto e:row){
            ans[i][0]=to_string(e);m2[to_string(e)]=i;i++;
        }
        for(int i=0;i<orders.size();i++){
            int r=m2[orders[i][1]];
            int c=m1[orders[i][2]];
            int x=stoi(ans[r][c]);
            x++;
            ans[r][c]=to_string(x);
        }
        return ans;
    }
};
