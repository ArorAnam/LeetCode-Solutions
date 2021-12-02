#include <iostream>
#include <map>
#include <math.h>
#include <vector>
#include <set>
#include <queue>
#include  <sstream>
#include  <fstream>

using namespace std;







int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    vector<int>distance(n,INT_MAX);
    distance[src]=0;
    K++;
    while(K--){
        vector<int>tmp(distance);
        for(auto it:flights){
            int sr=it[0],des=it[1],len=it[2];
            if(distance[sr]!=INT_MAX&&distance[sr]+len<tmp[des]){
                tmp[des]=distance[sr]+len;
            }
        }
        distance=tmp;
}
return distance[dst]==INT_MAX?-1:distance[dst];
}
int main() {
    vector<vector<int> >v={{0,1,100},{1,2,100},{0,2,500}};
    int z=findCheapestPrice(3,v,0,2,0);
    cout<<"The Cheapest way to reach from source city to destination city "<<z<<endl;
}