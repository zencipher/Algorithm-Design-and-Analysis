#include<iostream>
#include <iostream>
#include <stdio.h>
#include <limits.h>
#define MAX_INT 2147483647

using namespace std;

 
void cutRod (int *price, int rodLength) {
  
    int *optimalPrice = new int[rodLength + 1];
    int *endLength = new int[rodLength + 1];
    optimalPrice[0] = 0;
  
    int i, j;
  

    for (i = 1; i <= rodLength; i++) {
      
        int max_value = INT_MIN;
              
        int bestLength = -1;
      
        for (j = 1; j <= i; j++) {
            if (max_value < price[j] + optimalPrice[i - j]){
                max_value = price[j] + optimalPrice[i - j];
                bestLength = j;
	    
            }
	
        }
      
        optimalPrice[i] = max_value;
        endLength[i] = bestLength;
    }
  

    cout << optimalPrice[rodLength] << endl;
    i = rodLength;
  
    while (i > 0) {    
        cout << endLength[i] << " ";        
        i = i - endLength[i];
    }
  
    cout << "-1" <<endl;
  
    delete optimalPrice;
    delete endLength;
}


int main (int argc, char **argv) {
  
    int size;
    cin >> size;
    
    int *arr = new int[size + 1];
      
    arr[0] = 0;
  
    for (int i = 1; i <= size; i++){
        cin >> arr[i];
    }  
    cutRod (arr, size);
  
    return 0;

}
