#include<iostream>
#include<stdlib.h>
#include <string.h>

using namespace std;

struct BinaryTree {
	int data;
	BinaryTree *left;
	BinaryTree *right;
};

//returns the node which contains the min value
BinaryTree* findMin(BinaryTree *treeNode){
	if(treeNode == NULL){
		return NULL;
	}
	//Search left subtree for min element
	if(treeNode -> left)
		return findMin(treeNode -> left);
	else
		return treeNode;
}

//returns the node which contains the max value
BinaryTree* findMax(BinaryTree *treeNode){
	if(treeNode == NULL){
		//if tree is empty
		return NULL;
	}
	//Search left sub tree for min element
	if(treeNode -> right)
		return(findMax(treeNode -> right));
	else
		return treeNode;
}

BinaryTree *Insert(BinaryTree *treeNode,int value){
	if(treeNode == NULL){
		BinaryTree *temp;
		temp = new BinaryTree;
		temp -> data = value;
		temp -> left = temp -> right = NULL;
		return temp;
	}
	if(value >(treeNode -> data)){
		treeNode -> right = Insert(treeNode -> right, value);
	}
	else if(value < (treeNode -> data)){
		treeNode -> left = Insert(treeNode -> left, value);
	}
	return treeNode;
}

BinaryTree * Delete(BinaryTree *treeNode, int value){
	BinaryTree *temp;
	if(treeNode == NULL){
		cout<<"Not found!";
	}
	else if(value < treeNode -> data){
		treeNode -> left = Delete(treeNode -> left, value);
	}
	else if(value > treeNode -> data){
		treeNode -> right = Delete(treeNode -> right, value);
	}
	else {
		//deletes current node and replaces with min from the right sub tree or max from the left sub tree
		if(treeNode -> right && treeNode -> left){
			temp = findMin(treeNode -> right);
			treeNode -> data = temp -> data;

			treeNode -> right = Delete(treeNode -> right, temp -> data);
		}
		else {
			temp = treeNode;
			if(treeNode -> left == NULL)
				treeNode = treeNode -> right;
			else if(treeNode -> right == NULL)
				treeNode = treeNode -> left;
			//Delete temp
			free(temp);
		}
	}
	return treeNode;
}

//Search for a node
BinaryTree * Find(BinaryTree *treeNode, int value) {
	if(treeNode == NULL){
		//Element is not found
		return NULL;
	}
	if(value > treeNode -> data){
		//Search in the right sub tree.
		return Find(treeNode -> right, value);
	}
	else if(value < treeNode -> data){
		//Search in the left sub tree.
		return Find(treeNode -> left, value);
	}
	else{
	//Element Found
	return treeNode;
	}
}

void inOrder(BinaryTree *treeNode){
	if(treeNode == NULL)	{
		return;
	}
	inOrder(treeNode -> left);
	cout<<treeNode -> data<<endl;
	inOrder(treeNode -> right);
}

void preOrder(BinaryTree *treeNode){
	if(treeNode == NULL){
		return;
	}
	cout<<treeNode -> data<<endl;
	preOrder(treeNode -> left);
	preOrder(treeNode -> right);
}

void postOrder(BinaryTree *treeNode){
	if(treeNode == NULL){
		return;
	}
	postOrder(treeNode -> left);
	postOrder(treeNode -> right);
	cout<<treeNode -> data<< endl;
}


int main(){
	BinaryTree *root = NULL;
	char ch[10];
	int val, x;
	char cho;
	//Loops until user cin's 'e'
	while(1){
		
		cin>>ch;

		for(x = 0; ch[x]!='\0'; x++) ;
		
		if(x == 2)
			val = ch[1] - 48;
		else if(x == 3)
			val = (ch[1] - 48) * 10 + (ch[2] - 48);
		else if(x == 4)
			val = (ch[1] - 48) * 100 + (ch[2] - 48) * 10 + (ch[2] - 48);
			cho = ch[0];
		if(cho == 'i'){
			root = Insert(root, val);
		}
		else if(cho == 'd'){
			root = Delete(root,val);
		}
		else if(strcmp(ch,"oin") == 0){
			inOrder(root);
		}
		else if(strcmp(ch,"opre") == 0){
			preOrder(root);
		}
		else if(strcmp(ch,"opost") == 0){
			postOrder(root);
		}
		else if(cho == 'e')
			exit(0);
		
	}//End of while
	return 0;
}//End of main