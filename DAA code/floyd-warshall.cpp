#include <iostream>
using namespace std;
#define INF 999
#define n 4
int graph[4][4] = {0, 3, INF, 5,
               2, 0, INF, 4,
               INF, 1, 0, INF,
               INF, INF, 2, 0};
int dist[10][10];
int pred[10][10];

void initialize(){
	for (int i = 0; i < n; i += 1)
	{
		for (int j = 0; j < n; j += 1)
		{
			dist[i][j] = graph[i][j];
			if(dist[i][j] == 999 || dist[i][j] == 0){
				pred[i][j] = -1;
			}
			else{
				pred[i][j] = i;
			}
		}
	}
}

void Floyd(){
	initialize();
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(dist[i][k] != 999 && dist[k][j] != 999){
					if(dist[i][k]+dist[k][j] < dist[i][j]){
						dist[i][j] = dist[i][k] + dist[k][j];
						pred[i][j] = pred[k][j];
					}
				}
			}
		}
	}
}

void APSP(int i, int j){
	if(i == j){
		cout << " " << char('A'+i);
	}
	else if(pred[i][j] == -1) {
		cout << "NO PATH" << endl;
	}
	else{
		APSP(i,pred[i][j]);
		cout << " " << char('A'+j);
	}
}

int main(){
	Floyd();
	APSP(0,2);
	return 0;
}
