class Solution {
public:
    string reverseWords(string s) {
        if (s == "" || s.length() == 0)
            return "";

        string result = "";

        int curr = s.length() - 1;
        int start = 0, end;

        while (start < s.length() && s[start] == ' ')
            start++;

        while (curr >= start && s[curr] == ' ')
            curr--;

        while (curr >= start) {
            if (s[curr] == ' ') {
                result += ' ';
                curr--;
                //handle multiple spaces
                while (curr >= start && s[curr] == ' ')
                    curr--;
            }
            else {
                end = curr;
                while(curr >= start && s[curr] != ' ')
                    curr--;
                //copy word into buffer
                for (int i = curr; i <= end; i++)
                    result += s[i];
            }
        }

        return result;
    }
};