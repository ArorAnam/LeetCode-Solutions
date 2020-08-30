
// Soltion 1 : Make graph, detect cycles
class Solution {
public:

	bool canFinish(int numCourses,vector<vector<int>>& prerequisites)
	{
		vertices.reserve(numCourses);
		edges.reserve(numCourses);
		status.reserve(numCourses);
		//Make graph - step 1 & 2
		//1. Make vertices
		for(int i=0; i<numCourses; ++i){
		   vertices.emplace_back(i);
			status[i] = UNVISITED;
		}
		//2. Make edges
		for(auto& v: prerequisites)
			edges[v[0]].emplace_back(v[1]);

        //3. Detect cyclic
		for(const auto& v: vertices){
		   if(status[v] == VISITED) continue;
		   if(IsDFSCyclic(v)) return false; //If cyclic then can't finish course
		}
		return true;
	}

	bool IsDFSCyclic(int u)
	{
		status[u] = VISTING;
		for(auto& e: edges[u]){
			if(status[e] == VISITED) continue;
			else if(status[e] == VISTING) return true;
			if(IsDFSCyclic(e)) return true;
		}
		status[u] = VISITED; //After all edges visited
		return false;
	}

private:
  	   static constexpr int UNVISITED = -1; //(by default)
		static constexpr int VISTING = 0;
		static constexpr int VISITED = 1;

		vector<int> vertices;
		unordered_map<int,vector<int>> edges;
		vector<int> status;
};

// Solution 2 : BFS, keep track of in-degree of a vertice
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDeg(numCourses, 0);
        vector<vector<int>> graph(numCourses);

        for(auto p : prerequisites) {
            int first = p[0];
            int second = p[1];
            inDeg[first]++;
            graph[second].push_back(first);
        }

        queue<int> q;
        for(int i=0; i<numCourses; ++i) {
            if(inDeg[i] == 0)
                q.push(i);
        }

        int count = 0;
        while(!q.empty()) {
            auto x = q.front();
            q.pop();
            for(auto y : graph[x]) {
                inDeg[y]--;
                if(inDeg[y] == 0)
                    q.push(y);
            }
            count++;
        }
        return count==numCourses;
    }
};


// Soltion 3 ::
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       unordered_map<int, vector<int>> adjacent_list;
       for (const auto& i : prerequisites) {
           adjacent_list[i[0]].push_back(i[1]);
       }

       vector<int> visit(numCourses, 0);

       function<bool(int)> dfs = [&](int e) ->bool {
           if (visit[e] == 1) {
               return false;
           }
           if (visit[e] == 2) {
               return true;
           }
           visit[e] = 1; // visiting
           for (auto i : adjacent_list[e]) {
               if (!dfs(i)) {
                   return false;
               }
           }
           visit[e] = 2;
           return true;
       };

       for (auto i = 0; i < numCourses; ++i) {
           if (!dfs(i)) {
               return false;
           }
       }
       return true;
   }
