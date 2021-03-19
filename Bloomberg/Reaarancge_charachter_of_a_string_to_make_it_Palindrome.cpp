// Check if characters of a given string can be rearranged to form a palindrome

// A set of characters can form a palindrome if at most one character occurs odd number
// of times and all characters occur even number of times.

bool canFormPalindrome(string s) {
    unordered_set<char> m;
    for (auto& c : s) {
        if (m.find(c) != m.end()) m.erase(m.find(c));
        else m.insert(c);
    }
    return m.size() == 1 || m.size() == 0; 
}