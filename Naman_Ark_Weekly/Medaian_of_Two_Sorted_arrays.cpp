
// Approch 1:
// merge elements in an efficient way, and keep count of the
// elements inserted into the output array or printed form.
// SO when the elemen in the output array are half the original
// size print the median
// Case 1: m+n is odd, the (m+n)/2 th indx
// m+n is even, then average of ((m+n)/2-1) and ((m+n)/2)


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m1 = -1, m2 = -1;
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        int count;

        if((m + n) % 2 == 1) {
            for(count = 0; count <= (n+m)/2; count++) {
                if(i != n && j != m)
                    m1 = nums1[i] > nums2[j] ? nums2[j++] : nums1[i++];
                else if(i < n)
                    m1 = nums1[i++];
                else
                    m1 = nums2[j++];
            }
            return m1;
        }
        else {
            for(count = 0; count <= (n + m)/2; count++) {
                m2 = m1;
                if(i != n && j != m) {
                    
                }
            }
        }
    }
};



// Approach 2
/*
Create a recursive function that takes two arrays and the sizes of both the arrays.
Take care of the base cases for the size of arrays less than 2. (previously discussed in Approach).Note: The first array is always the smaller array.
Find the middle elements of both the arrays. i.e element at (n – 1)/2 and (m – 1)/2 of first and second array respectively. Compare both the elements.
If the middle element of the smaller array is less than the middle element of the larger array then the first half of smaller array is bound to lie strictly in the first half of the merged array. It can also be stated that there is an element in the first half of the larger array and second half of the smaller array which is the median. So, reduce the search space to the first half of the larger array and second half of the smaller array.
Similarly, If the middle element of the smaller array is greater than the middle element of the larger array then reduce the search space to the first half of the smaller array and second half of the larger array.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    }
};
