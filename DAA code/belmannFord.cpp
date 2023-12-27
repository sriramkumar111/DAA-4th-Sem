#include <iostream>
using namespace std;
struct Edge
{
    int src;
    int dest;
    int weight;
};
const int nov = 4; // number of vertex
int noe = 0;       // number of edges
int dist[nov];
int pred[20];
// weighted graph with negative cost
int w[4][4] = {0, 10, 8, 999,
               999, 0, -6, 999,
               999, 999, 0, 2,
               999, 999, 999, 0};
Edge edgeList[20];
int totalEdges = 0;
void createList(){
	for(int i = 0; i < nov; i++){
		for(int j = 0; j < nov; j++){
			if(w[i][j] != 0 || w[i][j] != 999){
				edgeList[totalEdges].src = i;
				edgeList[totalEdges].dest = j;
				edgeList[totalEdges++].weight = w[i][j];
			}
		}
	}
}
void initialize(){
	for(int i = 0; i < nov; i++){
		dist[i] = 999;
		pred[i] = -1;
	}
}
void belmannFord(int source){
	createList();
	initialize();
	dist[source] = 0;
	for(int i = 1; i < nov-1; i++){
		for(int j = 0; j < totalEdges; j++){
			int u = edgeList[j].src;
			int v = edgeList[j].dest;
			int weight = edgeList[j].weight;
			
			if(dist[u] + weight < dist[v]){
				dist[v] = dist[u] + weight;
				pred[v] = u;
			}
		}
	}
}
void displayPath(int i){
	if(i == -1) return;
	displayPath(pred[i]);
	cout << char('A' + i) << " ";
}
void printInformation()
{
    for (int i = 0; i < nov; i++)
    {
        cout << char('A' + i) << " - ";
        displayPath(i);
        cout << "Destination Reached. Cost = " << dist[i] << endl;
    }
}
int main(){
	belmannFord(0);
	printInformation();
	return 0;
}
