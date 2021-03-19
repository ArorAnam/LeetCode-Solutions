// Solution 1
// 1. find the pivot element
// 2. apply binary search two the 2 subarrays before & after pivot element.

int findPivot(vector<int> arr, int low, int high) {
    if (high == low) return low;
    
    int mid = (high - low) / 2 + low;
    if (mid < high && arr[mid] > arr[mid] + 1)
        return mid;
    if (mid > low && arr[mid] < arr[mid - 1])
        return mid - 1;
    if (marr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);

    return findPivot(arr, mid + 1, high);
}

int binarySearch(vector<int> arr, int low, int high, int target) {
    if (high < low) 
        return -1; 
  
    int mid = low + (high - low)/2;
    if (key == arr[mid]) 
        return mid; 
  
    if (key > arr[mid]) 
        return binarySearch(arr, (mid + 1), high, key); 
  
    // else 
    return binarySearch(arr, low, (mid - 1), key); 
}

int findElement(vector<int> arr, int target) {
    int n = arr.size();

    int pivot = findPivot(arr, 0, n - 1);

    if (arr[pivot] == target) retur pivot;

    if (arr[0] <= target)
        return binarySearch(arr, 0, pivot - 1, target);
    
    return binarySearch(arr, pivot + 1, n - 1, target);
}