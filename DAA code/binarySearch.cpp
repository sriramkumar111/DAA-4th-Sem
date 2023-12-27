#include <iostream>
using namespace std;
bool binarySearch(int *arr, int start, int end, int key){
	while(start < end){
		int mid = (start+end)/2;
		if(arr[mid] == key){
			return true;
		}
		//key is present at left side
		if(key < arr[mid]){
			return binarySearch(arr, start, mid-1, key);
		}
		//key is at right side
		else{
			return binarySearch(arr, mid+1, end, key);
		}
	}
	return false;
}
int main(){
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int n = 10;
	int key = 4;
	if(binarySearch(arr,0,n,key)){
		cout << "Found!!!" << endl;
	}
	else{
		cout << "Not Found!!!" << endl;
	}
}
