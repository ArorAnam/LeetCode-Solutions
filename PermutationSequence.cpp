class Solution {
public:
    void setPerm(vector<int>& v, string& ans, int n, int k, vector<int>& factVal) {
        //only one element left to append to ans
        if(n == 1) {
            ans += to_string(v.back());
            return;
        }

        int index = (k / factVal[n-1]);
        //if k is a multiple of elements of partition then decrement thr index
        if(k%factVal[n-1] == 0)
            index--;

        ans += to_string(v[index]); //add the value to the string
        v.erase(v.begin() + index); // remove the element from the array
        k -= factVal[n-1]*index; // ajust value of k; e.g. k=15-6*2=3.
        
        //recursively call for n=n-1 until n=1
        setPerm(v, ans, n-1, k, factVal);
    }

    string getPermutation(int n, int k) {
        if(n == 1)
            return "1";

        vector<int> factVal = {1,1,2,6,24,120,720,5040,40320,362880};
        string ans = "";
        vector<int> v;

        for(int i=1;i<=n;i++)
            v.emplace_back(i);

        setPerm(v, ans, n, k, factVal);

        return ans;
    }
};