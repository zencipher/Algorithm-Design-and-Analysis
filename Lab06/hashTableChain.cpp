#include <iostream>
#include <list>
using namespace std;

 
class HashTable {				// hashTable class
    private:
        list < int >*hashTable;
    
    public:
    HashTable () {				//initialize hastable to null on creation
        hashTable = NULL;
    };
      
     
    ~HashTable () {	//destructor
        if (hashTable != NULL){
    	    delete[]hashTable;
        }
    }
    
    void createHashTable (int size) {//intialize hashtable with linked lists
        hashTable = new list < int >[size];
    } 
 
    void insert (int key, int size) {
        hashTable[key % size].push_front (key);	//inserting key to the front of linked list at hash(key)
    } 
 
    bool deleteKey (int key, int size) {
        list < int >l = hashTable[key % size];	//if key is present it should be in the list at index=key mod size
        list < int >::iterator it;
    
        if (l.empty ())
            return false;		//list empty means delete failed
        else {
	        for (it = l.begin (); it != l.end (); ++it) {	//search the list for key
	            if (*it == key) {
                    l.erase (it);	//if found erase element from list
		            hashTable[key % size] = l;	//copy modified list back to hashtable
		            return true;
                }
	  
            }
            return false;
      
        }
  
    }
  
    void search (int key, int size) {
        list < int >l = hashTable[key % size];	//if key is present it should be in list at index=key mod size
        list < int >::iterator it;
        int index = 0;
    
        if (l.empty ())
            cout << key << ":NOT_FOUND;" << endl;	//list empty means not found
        else {
            for (it = l.begin (); it != l.end (); ++it){	//search list
	            if (*it == key) {
		            cout << key << ":FOUND_AT" << (key % size) << "," << index << ";" <<endl;
		            return;
	            }
                index++;
            }
            cout << key << ":NOT_FOUND;" << endl;
        }
    }
  
    void output (int size) {
        list < int >l;
        list < int >::iterator it;
        for (int i = 0; i < size; i++) {
            l = hashTable[i];	//take each list from hashtable
            if (l.empty ()) {
                cout << i << ":;" << endl;
            }
	
    	    else {
                cout << i << ":";	//print hashtable index
	            for (it = l.begin (); it != l.end (); ++it){	//print list
	                cout << *it << "->";
                }
	    
                cout << ";" << endl;
	  
            }
      
        }
  
    }

 
};


 
int main () {
  
    int size, key;
    cin >> size;
    char ch;
     
    HashTable table;
      
    table.createHashTable (size);
    cin >> ch;
    while (ch != 'e') {
          
        if (ch == 'i'){
            cin >> key;
            table.insert (key, size);
        }
        else if (ch == 'd'){
            cin >> key;
            
            if (table.deleteKey (key, size))
                cout << key << ":DELETED;" << endl;
    	    else
                cout << key << ":DELETE_FAILED;" << endl;
        }
        
        else if (ch == 's') {
            cin >> key;
            table.search (key, size);
        }
        
        else if (ch == 'o'){
            table.output (size);
        }
          
     
        cin >> ch;
        
    }
      
     
    return 0;

}


 
