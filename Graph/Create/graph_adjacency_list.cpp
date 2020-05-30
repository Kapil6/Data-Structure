#include <iostream>
#include <vector>

using namespace std;

vector <int> adj[10];

int main()
{
	int nodes, edges, x, y;
	cout << "Enter the no. of nodes" << endl;
	cin >> nodes;
	cout << "Enter the no. of edges" << endl;
	cin >> edges;
	for (int i = 0; i < edges; i++)
	{
		cout << "Enter the u and v" << endl;
		cin >> x >> y ;
		adj[x].push_back(y);
	}
	for (int i = 1; i <= nodes ; i++)
	{
		cout << "Adjacency List of node " << i << ":" ;
		for (int j = 0; j < adj[i].size(); j++)
		{
			if (j == (adj[i].size() - 1))
				cout << adj[i][j] << endl;
			else
				cout << adj[i][j] << "-->";
		}
	}	
	return 0;
}
