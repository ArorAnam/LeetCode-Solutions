#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class SuperStack {
    vector<int> stack;
    vector<int> incr;
    int currSum;

public:
    SuperStack() { currSum = 0; }
    ~SuperStack() {}

    void push (int v) {
        currSum += v;
        stack.push_back(v);
        incr.push_back(0);
    }

    void pop() {
        //if (incr.empty()) return -1;
        if (incr.size() > 1) {
            incr[incr.size() - 2] += incr[incr.size() - 1];
        }

        int val = stack.back() + incr.back();
        stack.pop_back(); incr.pop_back();

        currSum -= val;
        //return val;
    }

    void inc (int i, int v) {

        if (!incr.empty()) {
            int idx = std::min(i, int(incr.size())) - 1;
            incr[idx] += v;
        }
        currSum += i * v;
    }

    bool empty() {
        if (stack.empty()) return true;
        return false;
    }

    int top() {
        if (!incr.empty()) return stack.back() + incr.back();
        return stack.back();
    }

    int sum () { return currSum; }
};

string superStack (vector<string> &operations) {

    SuperStack st;

    for (auto const& strOp : operations) {
        if (strOp.compare(0, 4, "push") == 0) {
            int val = atoi(strOp.substr(5, strOp.length()-5).c_str());
            st.push(val);
        }
        else if (strOp.compare(0, 4, "pop") == 0) {
            assert(!st.empty());
            st.pop();
        }
        else if (strOp.compare(0, 3, "inc") == 0) {
            int begin = 4; int end = 0;
            int i = begin;
            while (i < strOp.length() && strOp[i] >= '0' && strOp[i] <= '9') ++i;
            end = i-1;
            int e = atoi(strOp.substr(begin, end-begin+1).c_str());

            begin = end+2;
            assert(strOp.length() > begin);
            
            int k = atoi(strOp.substr(begin, end-begin+1).c_str());
            st.inc(e, k);
        }
    
        if (!st.empty())
            cout << st.top() << " " << st.sum() << endl;
        else
            cout << "EMPTY" << endl;
    }

    if (!st.empty()) {
        string str;
        stringstream ss;  
        ss << st.top();  
        ss >> str;
        //cout << str << endl;
        return str;
    }
    else
        return "EMPTY";    
}

int main(int argc, char** argv) {

    // vector<string> operations = {"push -36", "push 20", "pop", "push -9", "pop",
    //     "push -53", "pop", "inc 1 -17"};

    vector<string> operations = { "push 4", "push 5", "inc 2 1", "pop", "pop" };
    
    string res = superStack(operations);
    
    return 0;
}