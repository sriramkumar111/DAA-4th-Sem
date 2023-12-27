#include <iostream>
#include <fstream>
using namespace std;
int n; // vertex
int adjMat[100][100];
struct Edge
{
	int src;
	int dest;
	int weight;
};
struct Edge arr[100];
int totalEdges = 0;
void readGraph()
{
	fstream input;
	input.open("kruskal.txt", ios::in);
	input >> n;
	for (unsigned int i = 0; i < n; i += 1)
	{
		for (unsigned int j = 0; j < n; j += 1)
		{
			input >> adjMat[i][j];
		}
	}
	input.close();
	for (unsigned int i = 0; i < n; i += 1)
	{
		for (unsigned int j = 0; j <= i; j += 1)
		{
			if (adjMat[i][j])
			{
				arr[totalEdges].src = j;
				arr[totalEdges].dest = i;
				arr[totalEdges++].weight = adjMat[i][j];
			}
		}
	}
}

void bubbleSort()
{
	for (int i = 0; i < totalEdges - 1; i++)
	{
		for (int j = 0; j < totalEdges - i - 1; j++)
		{
			if (arr[j].weight > arr[j + 1].weight)
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int parent[100];
struct Edge mst[100];
void makeSet()
{
	for (int i = 0; i < n; i++)
	{
		parent[i] = -1;
	}
}
int find(int i)
{
	while (parent[i] > 0)
	{
		i = parent[i];
	}
	return i;
}
void Union(int i, int j)
{
	int x = find(i);
	int y = find(j);
	parent[x] = y;
}
int mstEdge = 0;
void showMST()
{
	int totalCost = 0;
	for (int i = 0; i < mstEdge; i++)
	{
		cout << char('A' + mst[i].src) << "-" << char('A' + mst[i].dest) << "->" << mst[i].weight << endl;
		totalCost += mst[i].weight;
	}
	cout << "Total cost for this MST will be: " << totalCost << endl;
}
void kruskalAlgorithm()
{
	readGraph();
	bubbleSort();
	makeSet();
	for (int i = 0; i < totalEdges; i++)
	{
		if (find(arr[i].src) != find(arr[i].dest))
		{
			Union(arr[i].src, arr[i].dest);
			mst[mstEdge].src = arr[i].src;
			mst[mstEdge].dest = arr[i].dest;
			mst[mstEdge++].weight = arr[i].weight;
		}
	}
	showMST();
}

int main()
{
	kruskalAlgorithm();
	return 0;
}
