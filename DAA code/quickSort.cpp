#include <iostream>
#include <time.h>
using namespace std;
int partion(int *arr, int low, int high)
{
	int pivotIndex = low; // we assume pivot as 0th element
	int count = 0;		  // to count the number lesser than pivot element
	for (int i = low + 1; i <= high; i++)
	{
		if (arr[pivotIndex] > arr[i])
			count++;
	}
	// now place the element at right position
	pivotIndex = low + count;
	swap(arr[low], arr[pivotIndex]); // swap the elements to place at right index
	int i = low, j = high;			 // initialize two pointers
	while (i < pivotIndex && j > pivotIndex)
	{
		while (arr[i] <= arr[pivotIndex])
		{
			i++;
		}
		while (arr[j] > arr[pivotIndex])
		{
			j--;
		}
		// if upper 2 conditions failed then execute this statement
		if (i < pivotIndex && j > pivotIndex)
		{
			swap(arr[i++], arr[j--]);
		}
	}
	return pivotIndex;
}
// it is for randomized quick sort algorithm
int randomization(int *arr, int low, int high)
{
	srand(time(NULL));
	int randomIndex = low + rand() % (high - low + 1);
	swap(arr[randomIndex], arr[low]);
	return partion(arr, low, high);
}
void quickSort(int *arr, int low, int high)
{
	// base case
	if (low >= high)
		return;
	int pivot = randomization(arr, low, high);
	quickSort(arr, low, pivot - 1);
	quickSort(arr, pivot + 1, high);
}
void display(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	int arr[] = {8, 1, 3, 7, 2, 9, 5, 6, 4, 10};
	int n = sizeof(arr) / sizeof(int);
	quickSort(arr, 0, n - 1);
	display(arr, n);
	return 0;
}
