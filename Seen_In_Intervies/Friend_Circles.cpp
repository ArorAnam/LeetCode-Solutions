class UnionFind {
private:
    vector<int> parents;
    vector<int> size;
    int circleCount;

public:
    UnionFind(int n) {
        parents.resize(n);
        size.assign(n, 1);
        for(int i = 0; i < n; i++)
            parents[i] = i;
    }

    int find(int x) {
        if (parents[x] == x)
            return x;

        return parents[x] = find(parents[x]);
    }

    void Union(int a, int b) {
        int groupA = find(a);
        int groupB = find(b);

        if (groupA != groupB) {
            //parents[groupA] = groupB;
            if (size[groupA] < size[groupB]) {
                parents[groupA] = groupB;
                size[groupB] += size[groupA];
            }
            else {
                parents[groupB] = groupA;
                size[groupA] += size[groupB];
            }

            circleCount--;
        }
    }

    void setCircleCount(int circleCount) {
        this->circleCount = circleCount;
    }

    int getCircleCount() {
        return this->circleCount;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if (n == 0)
            return 0;

        UnionFind unionFind(n * n);
        unionFind.setCircleCount(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 1 && i != j)
                    unionFind.Union(i, j);
            }
        }

        return unionFind.getCircleCount();
    }
};
