#include <iostream>
#define MAX_INT 2147483647

using namespace std;

//merge and mergeSort functions based on geeksforgeeks
void merge(int arr[],int left, int mid, int right){
	int i,j,k; //indeces for different loops
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	//temporary arrays for splitting and merging
	int *leftArray = new int [n1]; 
	int *rightArray = new int[n2]; 
	
	//copy original array into temp arrays
	for(i = 0; i < n1; i++){
		leftArray[i] = arr[left + i];
	}
	for(j = 0; j < n2; j++){
		rightArray[j] = arr[mid + j + 1];
	}
	
	//merge the arrays back into arr[]
	i = 0; //index of first subarray
	j = 0; //index of second subarray
	k = left; //index of merged array
	
	while((i < n1) && (j < n2)){
		if(leftArray[i] <= rightArray[j]){
			arr[k++] = leftArray[i++];
		}
		else{
			arr[k++] = rightArray[j++];
		}
	}
	
	//copy remaining elements of leftArray[] if there are any
	while(i < n1){
		arr[k++] = leftArray[i++];
	}
	
	//copy remaining elements of rightArray[] if there are any
	while(j < n2){
		arr[k++] = rightArray[j++];
	}
}

void mergeSort(int arr[], int left, int right){
	if (left < right){ //left and right are indexes
		
		int mid = left+(right-left)/2;
		
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		
		merge(arr, left, mid, right);
	}
}

int main(){
	int arraySize;
	cin >> arraySize;
	int i, j; 
	
	
	int *arr = new int[arraySize];
	for(i = 0; i < arraySize; i++){
		cin >> arr[i];
	}
	
	mergeSort(arr, 0, arraySize-1);
	
	//used separate variable for printing loop index just 
	//to show that the for loops are different

	for(j = 0; j < arraySize; j++){
    	cout << arr[j] << ";";
   	}
	
	
	
	return 0;
}