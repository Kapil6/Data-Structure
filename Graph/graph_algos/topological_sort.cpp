#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/*Below program is use to sort the graph using topological
sort
*/

class TopologicalSort {
	public:
	vector<int> sort(int vertices, const vector<vector<int>> &edges) {
			vector<int> sortedOrder;
			if (vertices <= 0)
				return sortedOrder;
			
			// Init the graph and indegree
			unordered_map<int, int> inDegree;
			unordered_map<int, vector<int>> graph;
			for (int i = 0; i < vertices; i++) {
				inDegree[i] = 0;
				graph[i] = vector<int> ();
			}

			// Build the graph and indegree
			for (int i = 0; i < edges.size(); i++) {
				int parent = edges[i][0], child = edges[i][1];
				graph[parent].push_back(child);
				inDegree[child]++;
			}

			// Find all the sources and put it int the queue
			queue<int> sources;
			for (auto entry: inDegree) {
				if (entry.second == 0)
					sources.push(entry.first);
			}

			// For each source, add it to the sorted order and get the children of source node and decreament its degree, if degree becomes zero then put the child node into the queue and loop it
			while(!sources.empty()) {
				int vertex = sources.front();
				sources.pop();
				sortedOrder.push_back(vertex);
				vector<int> children = graph[vertex];
				for (auto child : children) {
					inDegree[child]--;
					if (inDegree[child] == 0)
						sources.push(child);
				}
			}
		
			if (sortedOrder.size() != vertices) { //topological sort is not possible as graph has a cycle. 
				return vector<int> (); 
			}			
			
			return sortedOrder;
	  }
};

int main() {
	TopologicalSort s;
	vector<int> result = s.sort(4, vector<vector<int>> {vector<int>{3,2},vector<int>{3,0},vector<int>{2,0},vector<int>{2,1}});

	for (auto num: result)
		cout << num << " ";

	return 0;
}
