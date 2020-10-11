
// Idea is to change the problem statement from finding maximum xor of two numbers
// in an array to - > find two numbers in an array, such that xor of which equals
// to a number X. In this case, X will be maximum number we want to achieve
// till i-th bit.

// To find the largest value of an XOR operation, the value of XOR should have
// every bit to be set bit i.e. 1. In a 32-bit number, the goal, is to set
// the most 1 starting fro the left to right.

// A mask is needed
// will use mask to keep prefix for every number in the input till the i-th bit then
// with the list of possible numbers in our set, after inserting the number we will
// evaluate if we can update the max for that bit position to be 1.

// Time : O(NlogM)

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int maxx = 0, mask = 0;
        set<int> se;

        for (int i = 30; i >= 0; i--) {
            // set the i-th bit in the mask
            mask |= (1 << i);

            for (int j = 0; j < n; j++) {
                // just keep the prefix till
                // i-th bit neglecting all
                // the bit's after i'th bit
                se.insert(nums[j] & mask);
            }

            int newMaxx = maxx | (1 << i);

            for (int prefix : se) {
                if (se.count(newMaxx ^ prefix)) {
                    maxx = newMaxx;
                    break;
                }
            }

            se.clear();
        }

        return maxx;
    }
};

// SOLUTION 2 - Greedy with Trie
class Solution {
private:
    struct TrieNode {
        int number ;
        vector<TrieNode*> next;

        TrieNode(): number(0), next(2, nullptr) {
        }
    } *root;

    void insert(int number) {
        TrieNode *temp = root;
        for (int i = 31; i >= 0; i--) {
            int currBit = (number & (1 << i)) >> i;

            if (!(temp->next[currBit]))
                temp->next[currBit] = new TrieNode;

            temp = temp->next[currBit];
        }

        temp->number = number;
    }

    int getMaxXor(int number) {
        TrieNode *temp = root;

        for (int i = 31; i >= 0; i--) {
            int currBit = (number & (1 << i)) >> i;
            if (temp->next[1 - currBit])
                temp = temp->next[1 - currBit];
            else if (temp->next[currBit])
                temp = temp->next[currBit];
            else
                return number;
        }

        return temp->number;
    }

public:

    int findMaximumXOR(vector<int>& nums) {
        int maxXor = 0;
        root = new TrieNode;

        for (auto &n : nums) {
            maxXor = max(maxXor, (n ^ getMaxXor(n)));
            insert(n);
        }

        return maxXor;
    }
};
