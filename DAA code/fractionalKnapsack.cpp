#include <iostream>
using namespace std;

const int n = 7;
int weight = 15;
int Profit[] = {10, 5, 15, 7, 6, 18, 3};
int Weight[] = {2, 3, 5, 7, 1, 4, 1};

struct KnapSack{
	int profit;
	int weight;
	double ratio;
};

struct KnapSack arr[n] = {0};
void initialize(){
	for (int i = 0; i < n; i += 1)
	{
		arr[i].profit = Profit[i];
		arr[i].weight = Weight[i];
		arr[i].ratio = (double)Profit[i]/Weight[i];
	}
}

void bubbleSort(){
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-i-1; j++){
			if(arr[j].ratio < arr[j+1].ratio){
				swap(arr[j],arr[j+1]);
			}
		}	
	}
}

void fractionalKnapSack(){
	initialize();
	bubbleSort();
	double profit = 0;
	for(int i = 0; i < n; i++){
		if(weight > 0){
			int takenWeight = min(weight,arr[i].weight);
			profit += takenWeight * arr[i].ratio;
			weight -= takenWeight;
		}
	}
	cout << "The total profit will be: " << profit << endl;
}

int main(){
	fractionalKnapSack();
	return 0;
}
