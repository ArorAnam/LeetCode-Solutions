// Solution 1 : Brute Force
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int up = x, down = x, left = y, right = y;
        for (int i = 0; i < image.size(); ++i) {
            for (int j = 0; j < image[0].size(); ++j) {
                if (image[i][j] == '1') {
                    up = min(up, i);
                    down = max(down, i);
                    left = min(left, j);
                    right = max(right, j);
                }
            }
        }
        return (right - left  + 1) * (down - up + 1);
    }
};


// Soltion 2- DFS
// T: O(mn), S: O(nm)
class Solution {
    int top, bottom, left, right;

    void dfs(vector<vector<char>>& image, int x, int y) {
        if (x < 0 || y < 0 || x >= image.size() || y>= image[0].size()
                                        || image[x][y] == '0')
                return;
        image[x][y] = '0'; // mark visted black pixel as white
        top = min(top, x);
        bottom = max(bottom, x + 1);
        left = min(left, y);
        right = max(right, y +  1);
        dfs(image, x + 1, y);
        dfs(image, x - 1, y);
        dfs(image, x, y + 1);
        dfs(image, x, y - 1);
    }

public:
    int minArea(vector<vector<char>> image, int x, int y) {
        if (image.size() == 0 || image[0].size() == 0) return 0;
        top = botton = x;
        left = right = y;
        dfs (image, x, y);

        return (right - left) * (bottom - top);
    }
};


// Solution 3 : Binary Search
class Solution {
    int binarySearch(vector<vector<char>> image, bool horizontal, int low, int high,
                        int min, int max, bool goLower)
        {
            while (low < high) {
                int mid = (high - low)/2 + low, i = min;
                while (i < max && (horizontal ? image[mid][i] : image[i][mid]) == '0')
                    ++i;
                if ((i < max) == goLower) high = mid;
                else low = mid + 1;
            }
            return low;
        }
public:
    int minArea(vector<vector<char>> image, int x, int y) {
        int m = image.size(), n = image[0].size();
        int up = binarySearch(image, true, 0, x, 0, n, true);
        int down = binarySearch(image, true, x + 1, m, 0, n, false);
        int left = binarySearch(image, false, 0, y, up, down, true);
        int right = binarySearch(image, false, y + 1, n, up, down, false);
        return (right - left) * (down - up);
    }
};
