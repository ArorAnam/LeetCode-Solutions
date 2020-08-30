// Solution I - heap of distances
class comp {
    double EuclideanDistance(int x, int y) {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return EuclideanDistance(a.first, a.second) > EuclideanDistance(b.first, b.second);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        if(points.size() <= K)
            return points;

        int n = points.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> dist;

        for (auto point : points) {
            dist.push(make_pair(point[0], point[1]));
        }

        vector<vector<int>> res;
        // print the first k elements
        for (int i = 0; i < K; i++) {
            res.push_back({dist.top().first, dist.top().second});
            dist.pop();
        }

        return res;
    }
};


// Solution II - Heap of points in array only
// T : O(n + klog(n))
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        int n = points.size();
        if (n <=  K)
            return points;

        vector<int> dist(n);
        for(int i = 0; i < n; i++) {
            dist[i] = points[i][0]*points[i][0] + points[i][1]*points[i][1];
        }

        auto comp = [&dist](int i, int j) {
            return dist[i] > dist[j];
        };

        vector<int> heap(n);
        for(int i = 0; i < n; i++)
            heap[i] = i;
        make_heap(heap.begin(), heap.end(), comp);

        vector<vector<int>> res;
        for(int i = 0; i < K; i++) {
            pop_heap(heap.begin(), heap.end(), comp);
            res.push_back(points[heap.back()]);
            heap.pop_back();
        }

        return res;
    }
};

// Soltion III - Same as above but different heap lenght
// O(k + nlog(k))
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        if (points.size() <= K)
            return points;
        vector<int> dist(points.size());
        for (int i = 0; i < points.size(); ++i) {
            int x = points[i][0], y = points[i][1];
            dist[i] = x * x + y * y;
        }
        auto comp = [&dist](int i, int j) {
            return dist[i] < dist[j];
        };
        vector<int> heap(K + 1);
        for (int i = 0; i < K; ++i)
            heap[i] = i;
        make_heap(heap.begin(), heap.end() - 1, comp);
        for (int i = K; i < points.size(); ++i) {
            heap[K] = i;
            push_heap(heap.begin(), heap.end(), comp);
            pop_heap(heap.begin(), heap.end(), comp);
        }
        vector<vector<int>> res;
        for (int i = 0; i < K; ++i)
            res.push_back(points[heap[i]]);
        return res;
    }
};

// Soltion - IV
// Using Quickselect
// O(n) on avergae
// O(n^^2) in Worst Case
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = points.size();
        if (n <= K)
            return points;

        vector<int> dist(n);
        vector<int> indices(n);

        for(int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            dist[i] = x * x + y * y;
            indices[i] = i;
        }

        auto comp = [&dist](int i, int j) {
            return dist[i] < dist[j];
        };

        nth_element(indices.begin(), indices.begin() + K, indices.end(), comp);

        vector<vector<int>> res(K);
        for(int i = 0; i < K; i++)
            res[i] = points[indices[i]];

        return res;
    }
};
