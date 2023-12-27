#include <iostream>
using namespace std;
int profit[] = {3, 5, 20, 18, 1, 6, 30};
int deadline[] = {1, 3, 4, 3, 2, 1, 2};
const int n = 7;

struct JOB{
	int profit;
	int deadline;
};
struct JOB arr[n] = {0};
void initialize(){

	for(int i = 0; i < n; i++){
		arr[i].profit = profit[i];
		arr[i].deadline = deadline[i];
	}
}

void bubbleSort(){
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-i-1; j++){
			if(arr[j].profit < arr[j+1].profit){
				swap(arr[j],arr[j+1]);
			}
		}
	}
}
int getMax(){
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(ans, deadline[i]);
	}
	return ans;
}
void jobSequencing(){
	initialize();
	bubbleSort();
	int size = getMax();
	int gaantChart[size] = {0};
	int totalProfit = 0;
	for(int i = 0; i < n; i++){
		int index = arr[i].deadline - 1;
		while(gaantChart[index] > 0 && index > 0){
			index--;
		}
		if(gaantChart[index] == 0)
			gaantChart[index] = arr[i].profit;
	}
	for(int i = 0; i < size; i++){
		totalProfit += gaantChart[i];
	}
	cout << "Total Profit is = " << totalProfit << endl;
}
int main(){
	jobSequencing();
	return 0;
}
