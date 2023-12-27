#include <iostream>
using namespace std;

bool ternarySearch(int *arr, int start, int end, int key){
	while(start <= end){
		int mid1 = start + (end-start)/3;
		int mid2 = end - (end-start)/3;
		if(arr[mid1] == key || arr[mid2] == key){
			return true;
		}
		// key present at extreme left position
		if(key < arr[mid1]){
			return ternarySearch(arr, start, mid1-1, key);
		}
		// key is at middle position
		else if(key > arr[mid1] && key < arr[mid2]){
			return ternarySearch(arr, mid1+1, mid2-1, key);
		}
		//key is present at extreme right position
		else if(key == arr[mid2]){
			return true;
		}
		else{
			return ternarySearch(arr, mid2+1, end, key);
		}
	}
	return false;
}


int main(){
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int n = 10;
	int key;
	cin >> key;
	if(ternarySearch(arr, 0, n-1, key)){
		cout << "Found" << endl;
	}
	else{
		cout << "Not Found" << endl;
	}
	return 0;
}
