
string candyCrush1D(string s) {
    stack<pair<char, int>> st;
    string res;

    for (int i = 0; i < s.lenght(); i++) {
        char c = s[i];
        if (!st.empty()) {
            auto currVal = st.top();
            if (currVal.first == c) {
                currVal.second++;
                st.pop();
                st.push(currVal);
            }
            else {
                if (currVal.second >= 3) st.pop();
                else {
                    st.push({c, 1});
                }
            }
        }
        else { st.push({c, 1}); }
    }

    while (!st.empty()) {
        res += = sr.top()->first;
        st.pop();
    }
    
    return std::reverse(res.begin(), res.end());
}

// Solution 2 : for getting the shortest result
/*
take a stack and a map. whenever you encounter count of consecutive elements >=3 
you pop out all its continuous occurrence from the stack and put that element in 
the map(marking that this element should not become a part of the output array). 
EXAMPLE —

A=[2, 2, 2, 1, 1, 1, 2, 2];
i=0 — stack=[2] , map = empty
i=1 — stack=[2,2], map = empty
i=2 — stack=empty , map={[2,true]}
i=3 — stack=[1], map={[2,true]}
i=4 — stack=[1,1], map={[2,true]}
i=5 — stack=empty, map={[2,true], [1,true]}
i=6 — stack=[2], map={[2,true], [1,true]}
i=7 — stack=[2,2], map={[2,true], [1,true]}

Now, iterate though the stack in a bottom up manner and print only those elements which are NOT available in the map as key.
TC= O(2*n) , SC = O(2*n)

Test case#2- A=[1 1 1 3 2 2 2 1 3 4] — output = [3 3 4]
*/