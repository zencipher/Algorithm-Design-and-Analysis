#include <iostream>

#define MAX_INT 2147483647

using namespace std;

int main() {

  int* array;
  int arraySize;
  int i, key, j;

  // Get the size of the array
  cin >> arraySize;
  array = new int[arraySize];
  
  // Get the contents of the array
  for(i = 0; i < arraySize; i++){
	  cin >> array[i];
  }
  //int done_array[arraySize];
  
   for (i = 1; i < arraySize; i++){
       key = array[i];
       j = i-1;
 
   
       while (j >= 0 && array[j] > key) {
           array[j+1] = array[j];
           j = j-1;
       }
       
       array[j+1] = key;
	   for(int t = 0; t < i+1; t++){
		  cout << array[t] << ";";
	  }
	  cout << endl;
   }
	  
  }

