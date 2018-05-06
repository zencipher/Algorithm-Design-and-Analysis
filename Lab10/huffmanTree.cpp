#include <bits/stdc++.h>
#define MAX_TREE_HT 100

using namespace std;

// A Huffman tree node struct

struct MinHeap {

	char data;
	unsigned freq;

	MinHeap *left, *right;

	MinHeap(char data, unsigned freq){
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

// For comparison of two heap nodes

struct compare {

	bool operator()(MinHeap* l, MinHeap* r){

		return (l->freq > r->freq);

	}

};

// Print from root

void printCodes(struct MinHeap* root, string str){

	if (!root)
		return;

	if (root->data != '$')
		cout << root->data << ":" << str << "\n";

	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");

}

// Build the tree and print through traversal
void HuffmanCodes(char data[], int freq[], int size){

	struct MinHeap *left, *right, *top;

	priority_queue<MinHeap*, vector<MinHeap*>, compare> minHeap;

	for (int i = 0; i < size; ++i){
		minHeap.push(new MinHeap(data[i], freq[i]));
	}

	while (minHeap.size() != 1) {
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		
		top = new MinHeap('$', left->freq + right->freq);
		
		top->left = left;
		top->right = right;
		minHeap.push(top);

	}

	printCodes(minHeap.top(), "");

}

// Test Function

int main() {

	char arr[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	int freq[6] ;
	int size = 6;


	for(int i=0;i<size;i++){
		cin>>freq[i];
	}
	
	HuffmanCodes(arr, freq, size);

	return 0;

}