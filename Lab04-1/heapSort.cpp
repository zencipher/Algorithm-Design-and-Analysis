#include <iostream>
#include <stdio.h>
#include <limits.h>
#define MAX_INT 2147483647

using namespace std;

void heapTree(int arr[], int size, int i){ //i is the index of arr[]
	int large = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
	
	if (left < size && arr[left] > arr[large]){
		large = left;
	}
	
	if (right < size && arr[right] > arr[large]){
		large = right;
	}
	
	if (large != i) {
		swap(arr[i],arr[large]);
		
		heapTree(arr,size,large);
	}
}

void heapSort(int arr[], int size){
	for (int i = size/2-1; i >= 0; i--){
		heapTree(arr,size,i);
	}
	for(int i = size - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapTree(arr,i,0);
	}
}

int main(){
	int arraySize;
	cin >> arraySize;
	
	int *arr = new int[arraySize];
	
	for(int i = 0; i < arraySize; i++){
		cin >> arr[i];
	}
	
	heapSort(arr,arraySize);
	
	for(int i = 0; i < arraySize; i++){
		cout << arr[i] << ";";
	}
	return 0;

}