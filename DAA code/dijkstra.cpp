#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
int n;
int adjMat[100][100];
bool visited[100];
int parent[100];
int key[100];
void initialize()
{
	for (int i = 0; i < n; i++)
	{
		parent[i] = -1;
		visited[i] = false;
		key[i] = INT_MAX;
	}
};
void readGraph()
{
	fstream input;
	input.open("prims.txt", ios::in);
	input >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			input >> adjMat[i][j];
		}
	}
	input.close();
}
int extractMin()
{
	int minIndex = -1;
	int minVal = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		if (key[i] < minVal && !visited[i])
		{
			minVal = key[i];
			minIndex = i;
		}
	}
	return minIndex;
}
void printMST()
{
	for (int i = 0; i < n; i += 1)
	{
		cout << "Edge: " << char('A' + parent[i]) << "---" << char('A' + i) << " -> " << key[i] << endl;
	}
}
void dijkstraAlgo()
{
	readGraph();
	initialize();
	key[0] = 0; // assume
	parent[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int minIndex = extractMin();
		visited[minIndex] = true;
		for (int j = 0; j < n; j++)
		{
			if (adjMat[minIndex][j])
			{
				int u = minIndex;
				int v = j;
				int weight = adjMat[minIndex][j];
				// relaxation
				if (key[u] + weight < key[v])
				{
					key[v] = key[u] + weight;
					parent[v] = u;
				}
			}
		}
	}
	printMST();
}
int main()
{
	dijkstraAlgo();
	return 0;
}
