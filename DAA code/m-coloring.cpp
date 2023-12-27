#include <iostream>
#include <fstream>
using namespace std;
int n; // number of vertex
int graph[100][100];
int colourGraph[100] = {0};
int m = 0; // number of colours
void display(int colourGraph[], int m)
{
    cout << "Solution is: ";
    for (int i = 0; i <= m; i++)
    {
        cout << colourGraph[i] << " ";
    }
    cout << endl;
}
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

bool isSafe(int currColor, int currNode)
{
    for (int i = 0; i < n; i++)
    {
        // if edge exists & current colour is not same as adjacent colours
        if (graph[currNode][i] && colourGraph[i] == currColor)
        {
            return false;
        }
    }
    return true;
}

bool graphColor(int node)
{
    // base case
    if (node == n)
    {
        // cout << "The graph can be successfully coloured by " << m << " colours\n";
        display(colourGraph, m);
        return true;
    }
    for (int i = 1; i <= m; i++)
    {
        if (isSafe(i, node))
        {
            colourGraph[node] = i;
            graphColor(node + 1);
            colourGraph[node] = 0; // backtrack
        }
    }
    return false;
}

int main()
{
    cout << "Enter the number of colours: ";
    cin >> m;
    readGraph();
    graphColor(0); // 0 as the starting node
    return 0;
}