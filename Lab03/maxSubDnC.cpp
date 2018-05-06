#include <iostream>
#include <stdio.h>
#include <limits.h>
#define MAX_INT 2147483647

using namespace std;

int maxTwo(int num1, int num2){
	return(num1 > num2)? num1:num2;
}

int maxThree(int num1, int num2, int num3){
	return maxTwo(maxTwo(num1,num2),num3);
}

int maxCrossSub(int arr[], int low, int mid, int high){
	int sum = 0;
	int maxLeft, maxRight;
	int leftSum = INT_MIN;
	for(int i = mid; i >= low; i--){
		sum += arr[i];
		if(sum > leftSum){
			leftSum = sum;
			//maxLeft = i;
		}
	}
	int rightSum = INT_MIN;
	sum = 0;
	
	for(int j = mid+1; j <= high; j++){
		sum = sum + arr[j];
		if(sum > rightSum){
			rightSum = sum;
			//maxRight=j;
		}
	}
	
	return (leftSum+rightSum);
}

int sumMaxSub(int arr[], int low, int high){
	if(high == low)
		return(low,high,arr[low]);
	else{
		int mid = (low+high)/2;
		return maxThree(sumMaxSub(arr,low,mid),sumMaxSub(arr,mid+1,high),maxCrossSub(arr,low,mid,high));
	}
}


int main(){
	int arraySize;
	cin >> arraySize;
	
	int *arr = new int[arraySize];
	
	for(int i = 0; i < arraySize; i++){
		cin >> arr[i];
	}
	
	cout << sumMaxSub(arr,0,arraySize-1);
	return 0;

}