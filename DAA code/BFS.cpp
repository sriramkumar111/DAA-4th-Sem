#include <iostream>
#include <fstream>
using namespace std;
int n;					   // number of vertex
int graph[100][100] = {0}; // graph adjacency matrix
void readGraph()
{
	fstream input;
	input.open("graph.txt", ios::in);
	input >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			input >> graph[i][j];
		}
	}
	input.close();
}
// Queue
int queue[100] = {0};
int front = -1, rear = -1;
bool isEmpty()
{
	return front > rear or front == -1;
}
void insert(int element)
{
	// no need to check is full condition as it is unreachable for our code
	if (front == -1)
	{
		front++;
	}
	rear++;
	queue[rear] = element;
}
void remove()
{
	// no need to check is empty as it is also unreachable
	front++;
}
int top()
{
	return queue[front];
}
void BFS(int source)
{
	int visited[n] = {0}; // to track the vertices
	insert(source);
	cout << char('A' + source) << " ";
	visited[source] = 1; // mark as visited
	while (!isEmpty())
	{
		int currNode = top();
		remove();
		for (int i = 0; i < n; i++)
		{
			// edge is available and not visited till now
			if (graph[currNode][i] && !visited[i])
			{
				insert(i);
				cout << char('A' + i) << " ";
				visited[i] = 1; // mark as visited
			}
		}
	}
}
int main()
{
	readGraph();
	BFS(0);
	return 0;
}
