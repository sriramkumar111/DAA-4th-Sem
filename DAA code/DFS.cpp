#include <iostream>
#include <fstream>
using namespace std;
int n; //number of vertex
int graph[100][100] = {0};
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
int visited[10] = {0};
void DFS_Recursion(int source){
	cout << char('A' + source) << " ";
	visited[source] = 1; // mark as visited
	for (int i = 0; i < n; i += 1)
	{
		if(graph[source][i] && !visited[i]){
			DFS_Recursion(i);
		}
	}
}
// Now what I want is a normal DFS code using Stack
int stack[100] = {0};
int top = -1;
bool isEmpty(){
	return top == -1;
}
void push(int element){
	// no need to check is full condition as it will not reach for our implementation
	stack[++top] = element;
}
int _top(){
	return stack[top];
}
void pop(){
	top--;
}

void DFS_Normal(int source){
	push(source);
	cout << char('A' + source) << " ";
	visited[source] = 1; // mark as visited
	while(!isEmpty()){
		int currNode = _top();
		pop();
		for(int i = 0; i < n; i++){
			// edge is available and vertex is not visited
			if(graph[currNode][i] && !visited[i]){
				push(i);
				cout << char('A' + i) << " ";
				visited[i] = 1; // mark as visited
			}
		}
	}
}	
int main(){
	readGraph();
	int choice;
	cout << "1. Recursive DFS\n2. Normal DFS\nEnter the choice: ";
	cin>>choice;
	switch(choice){
		case 1:
			DFS_Recursion(0);
			break;
		case 2:
			DFS_Normal(0);
			break;
		default:
			break;
	}
	//DFS_Recursion(0);
	//DFS_Normal(0);
	return 0;
}
