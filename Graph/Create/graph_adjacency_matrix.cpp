/* Directed graph using Adjacency Matrix */

#include<iostream>

using namespace std;

bool graph[10][10];

void initialize()
{
	for (int i = 0;i < 10; i++)
		for (int j = 0;j < 10; j++)
			graph[i][j] = false;
}

int main()
{
	int nodes, edges, x, y;
	initialize();
	cout << "Enter the no. of nodes" << endl;
	cin >> nodes;
	cout << "Enter the no. of edges" << endl;
	cin >> edges;
	for (int i = 0; i < edges ; i++)
	{
		cout << "Enter the u and v" << endl;
		cin >> x >> y;
		graph[x][y] = true;
	}
	return 0;	
}

