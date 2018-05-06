#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>

using namespace std;

class Graph
{
    int V; // V = vertex count    
    list<int> *adjacentLists;
    vector<int> *printVector;
 
    void fillOrder(int v, bool visited[], stack<int> &Stack){
		visited[v] = true;
	 
		list<int>::iterator i;
		for(i = adjacentLists[v].begin(); i != adjacentLists[v].end(); ++i)
			if(!visited[*i])
				fillOrder(*i, visited, Stack);
	 
		Stack.push(v);
	}
 
    void DepthSearch(int v, bool visited[], vector<int> &numVector){
		// Mark the current node as visited and print it
		visited[v] = true;

		// If nothing in there, just push
		if (numVector.empty()) {
			numVector.push_back(v);
		} 
		else {
			bool gotem = false;
			for (int i = 0; i < numVector.size(); i++){
				if (v <= numVector.at(i)){
					gotem = true;
					numVector.insert(numVector.begin() + i, v);
					i++;
				}
			}
			if (!gotem)
				numVector.push_back(v);
		}
 
    // Recur for all the vertices adjacentListsacent to this vertex
		list<int>::iterator i;
		for (i = adjacentLists[v].begin(); i != adjacentLists[v].end(); ++i)
			if (!visited[*i])
				DepthSearch(*i, visited, numVector);
	}
	
public:
    
	Graph(int V){
		this->V = V;
		adjacentLists = new list<int>[V];

		this->printVector = new vector<int> (V, 0);
	}
    
	void pushEdge(int v, int w){
		adjacentLists[v].push_back(w);
	}
 

    void printSCCs(){
		stack<int> Stack;
		bool *visited = new bool[V];
		
		for(int i = 0; i < V; i++)
			visited[i] = false;
	 
		for(int i = 0; i < V; i++)
			if(visited[i] == false)
				fillOrder(i, visited, Stack);
	 
		Graph g = transpose();

		for(int i = 0; i < V; i++)
			visited[i] = false;
	 
		while (Stack.empty() == false) {

			int v = Stack.top();
			Stack.pop();

			vector<int> *numVector = new vector<int>; // Holds numbers for sorting before printing
	 
			if (visited[v] == false){
				g.DepthSearch(v, visited, *numVector);

				int minimum = numVector->at(0);
				for (int i = 0; i < numVector->size(); i++){
					printVector->at(numVector->at(i)) = minimum;
				}

				// Clear numVector to make room for next SCC
				numVector->clear();
			}
		}

		// Print out contents of printVector
		for (int i = 0; i < printVector->size(); i++){
			cout << printVector->at(i) << endl;
		}

	}
 

    Graph transpose(){
		Graph g(V);

		for (int v = 0; v < V; v++){
			// Recur for all the vertices
			list<int>::iterator i;
			for(i = adjacentLists[v].begin(); i != adjacentLists[v].end(); ++i){
				g.adjacentLists[*i].push_back(v);
			}
		}
		
		return g;
	}
};

int main(int argc, char **argv)
{  
    // Get the number of verticies and edges in the
    // input
    int numVerts, numEdges;
    cin >> numVerts;
    cin >> numEdges;

    // Create instance of our graph object
    Graph graph(numVerts);

    // Loop through edges and add each one to graph
    int vertOneID, vertTwoID;
    for (int i = 0; i < numEdges; i++)
    {
        cin >> vertOneID;
        cin >> vertTwoID;

        graph.pushEdge(vertOneID, vertTwoID);
    }

    // Print out SCCs
    graph.printSCCs();

    return 0;
}