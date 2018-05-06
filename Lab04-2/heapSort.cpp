#include <iostream>
#include <stdio.h>
#include <limits.h>
#define MAX_INT 2147483647

using namespace std;

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low-1;
	
	for(int j = low; j <= high-1; j++){
		if(arr[j] <= pivot) {
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1], arr[high]);
	return (i+1);
}

int randomPartition(int arr[], int low, int high){
	srand(time(NULL));
	int random = low + rand() % (high - low);
	swap(arr[random], arr[high]);
	
	return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high){
	if(low < high){
		int partitionIndex = randomPartition(arr,low,high);
		quickSort(arr,low,partitionIndex - 1);
		quickSort(arr,partitionIndex + 1, high);
	}
}

int main(){
	int arraySize;
	cin >> arraySize;
	
	int *arr = new int[arraySize];
	
	for(int i = 0; i < arraySize; i++){
		cin >> arr[i];
	}
	
	quickSort(arr,0,arraySize-1);
	
	for(int i = 0; i < arraySize; i++){
		cout << arr[i] << ";";
	}
	return 0;

}