// Solutiion -- This places elements into correct places
// when nums1 & nums2 combined then it is already sorted

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for (int i = n - 1; i >= 0; i++) {
            int j, last = nums1[m - 1];
            for (j = m - 2; j >= 0 && nums1[j] > nums2[i]; j--)
                nums1[j + 1] = nums1[j];
            
            // if there was a greater element
            if (j != m - 2 || last > nums2[i]) {
                nums1[j + 1] = nums2[i];
                nums2[i] = last;
            }
        }
    }
};


// Solution 2 -- 

class Solution {
public:
    void merge(vector<int>& arr1, int n1, vector<int>& arr2, int n2) {
        int i = 0, j = 0, k = 0; 
  
    // Traverse both array 
    while (i < n1 && j < n2) 
    { 
        // Check if current element of first 
        // array is smaller than current element 
        // of second array. If yes, store first 
        // array element and increment first array 
        // index. Otherwise do same with second array 
        if (arr1[i] < arr2[j]) 
            arr3[k++] = arr1[i++]; 
        else
            arr3[k++] = arr2[j++]; 
    } 
  
    // Store remaining elements of first array 
    while (i < n1) 
        arr3[k++] = arr1[i++]; 
  
    // Store remaining elements of second array 
    while (j < n2) 
        arr3[k++] = arr2[j++]; 
    }
}

// Solution 3 -- using map - T: O(n)
class Solution {
public:
    void merge(vector<int>& arr1, int n1, vector<int>& arr2, int n2) {
        std::map< int, int > mp;
        
        for (int x : arr1) mp[x]++;
        for (int y : arr2) mp[y]++;

        for (int i = 0; i < arr1.size() + arr2.size(); i++) {
            while (mp.begin()->second) {
                arr1[i] = mp.begin()->first;
                i++;
                mp.begin()->second--;
            }
            mp.erase(mp.begin());
        }
}


// Solution 4 --
namespace
{
    class Solution {
    public:
        
        void static merge(vector<int>& nums1, int m, const vector<int>& nums2, int n)
        {
            std::merge(nums2.rbegin() + (nums2.size() - n), 
                       nums2.rend(), 
                       nums1.rbegin() + (nums1.size() - m), 
                       nums1.rend(), 
                       nums1.rbegin(), 
                       [](const int l, const int r) { return l >= r; }
                    );
        }
    };

    static const auto fast=[](){ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return nullptr;}();
}