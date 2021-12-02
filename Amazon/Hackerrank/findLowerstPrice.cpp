#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <cctype>

using namespace std;

int findLowestPrice(vector< vector<string> > &products, 
                    vector< vector<string> > &discounts) 
    {
        int totalPrice = 0;
        //unordered_map<string, pair<string, string>> dMap;
        unordered_map< string, pair<string, int> > dMap;

        for (auto discount : discounts) {
            int d2 = 0;
            stringstream ss1(discount[2]); ss1 >> d2;
            //cout << d2 << " ";
            //dMap[discount[0]] = {discount[1], discount[2]};
            dMap[discount[0]] = make_pair(discount[1], d2);
        }
        cout << endl;

        for (auto product : products) {
            int price = 0;
            stringstream ss2(product[0]);
            ss2 >> price;
            
            priority_queue< int, vector<int>, greater<int> > minPriceList;
            for (int i = 1; i < product.size(); i++) {
                transform(product[i].begin(), product[i].end(), product[i].begin(), ::tolower);
                if (product[i] == "empty" || product[i] == "") {
                    minPriceList.push(price);
                }
                else if (dMap.find(product[i]) != dMap.end()) {
                    pair<string, int> disParam = dMap[product[i]];
                    if (disParam.first == "0") {
                        minPriceList.push(disParam.second);
                    }
                    if (disParam.first == "1") {
                        minPriceList.push(round(price - price * (float(disParam.second) / 100)));
                        //cout << float(disParam.second) / 100 << endl;
                    }
                    if (disParam.first == "2") {
                        minPriceList.push(price - disParam.second);
                    }
                }
            } 

            if (!minPriceList.empty()) {
                totalPrice += minPriceList.top();
                cout << minPriceList.top() << " ";
            }
            else totalPrice += price;

            while(!minPriceList.empty()) minPriceList.pop();
        }

        return totalPrice;
    }


int main () {
    vector< vector<string> > products1 {
        { "10", "d0", "d1" },
        {"15", "EMPTY", "EMPTY"},
        { "20", "d1", "EMPTY" }
    };

    vector< vector<string> > discounts1 {
                    { "d0", "1", "27" },
                    { "d1", "2", "5" }
                };

    vector< vector<string> > products2 {
        { "10", "sale", "january-sale" },
        { "200", "sale", "EMPTY" }
    };

    vector< vector<string> > discounts2 {
                    { "sale", "0", "10" },
                    { "january-sale", "1", "10" }
                };
                     
    cout << findLowestPrice(products2, discounts2) << endl;

    return 0;
}