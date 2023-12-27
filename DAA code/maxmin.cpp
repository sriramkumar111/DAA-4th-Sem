#include <iostream>
using namespace std;
void maxmin(int *arr, int start, int end, int &_max, int &_min){
	// base case
	// if single element is present 
	if(start == end){
		_max = _min = arr[start];
		return;
	}
	// smaller subcase
	if(end == start+1){
		if(arr[end] > arr[start]){
			_max = arr[end];
			_min = arr[start];
		}
		else{
			_max = arr[start];
			_min = arr[end];
		}
	}
	// recursive calls
	int mid = (start+end)/2; // mid position 
	int leftMax, leftMin, rightMax, rightMin;
	maxmin(arr, start, mid, leftMax, leftMin);
	maxmin(arr, mid+1, end, rightMax, rightMin);
	_max = leftMax > rightMax ? leftMax : rightMax;
	_min = leftMin < rightMin ? leftMin : rightMin;
}

int main(){
	int arr[] = {3, 1, 8, 9, 6, 8, 9, 5, 10, 15};
	int n = sizeof(arr)/sizeof(int);
	int _max = -9999;
	int _min = 9999;
	maxmin(arr, 0, n-1, _max, _min);
	cout << "Max: " << _max << " Min: " << _min << endl;
	return 0;
}
