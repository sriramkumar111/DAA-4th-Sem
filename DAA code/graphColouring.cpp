#include <iostream>
#include <fstream>

using namespace std;
int graph[100][100] = {0};
int colourGraph[100];
int n,m;
void readGraph(){
	fstream input;
	input.open("graph.txt",ios::in);
	input >> n;
	for (int i = 0; i < n; i += 1)
	{
		for (int j = 0; j < n; j += 1)
		{
			input >> graph[i][j];
		}
	}
	input.close();
}
bool isSafe(int currNode, int currColour){
	for(int i = 0; i < n; i++){
		if(graph[currNode][i] && colourGraph[i]==currColour){
			return false;
		}
	}
	return true;
}
void display(){
	cout<<"Solution: ";
	for (int i = 0; i < n; i += 1)
	{
		cout<<colourGraph[i]<<" ";
	}
	cout<<endl;
}
void graphColoring(int node){
	if(node == n){
		display();
	}
	else{
		for(int i = 1; i <= m; i++){
			if(isSafe(node,i)){
				colourGraph[node] = i;
				graphColoring(node+1);
				colourGraph[node] = 0; //backtrack
			}
		}
	}
}
int main(){
	readGraph();
	cout << "Enter how many colours do you have? ";
	cin >> m;
	graphColoring(0);
	return 0;
}
