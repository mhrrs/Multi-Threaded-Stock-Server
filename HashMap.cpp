#include "HashMap.h"
using namespace std;


/*
 * ETK - April 2022
 * HashMap class
 * implements hashing with chaining
 * where the nodes in the tables are 
 * LinkedHashStock nodes, which 
 * contain a pointer to an Stock and a pointer
 * to the next stock in the list.
 */

// constructor initialize table size and counter
// then creates table of nullptr entries
HashMap::HashMap(int sz):table_size(sz),counter(0){
	table = new LinkedHashStock*[table_size];
	for (int i=0; i < table_size; i++){
		table[i] = nullptr;
	}
}

// destructor iterates through the table
// and traverses each list, deleting the nodes in the list 
HashMap::~HashMap(){
	for (int i=0; i<table_size; i++){
		if (table[i] != nullptr){
			LinkedHashStock *trailingCursor = nullptr;
			LinkedHashStock *leadingCursor = table[i];
			while (leadingCursor != nullptr){
				trailingCursor = leadingCursor;
				leadingCursor = leadingCursor->getNext();
				delete trailingCursor;
			}
		}
	}
	delete[] table;
}

// returns number of entries in the hash table
int HashMap::size(){
	return counter;
}

// a reasonabe hash code function
int HashMap::myHashCode(const string &str){
	unsigned hash = HASH_SEED;
	int nchars = str.length();
	for (int i=0; i < nchars; i++){
		hash = HASH_MULTIPLIER * hash + str[i];
	}
	return (hash & HASH_MASK);
}

// for your debugging pleasure
void HashMap::display(){

	for (int i=0; i< table_size; i++){
		cout << i << ": ";
		if (table[i] == nullptr){
			cout << endl;
		}
		else {
			LinkedHashStock *stock = table[i];
			while (stock != nullptr){
				cout << stock->getKey() << " -> ";
				stock = stock->getNext();
			}
			cout << " nullptr" << endl;
		}
	}
}

// creates a new Stock and then invokes the other insert method
bool HashMap::insert(string n, string t, int q, double p){
	Stock *e = new Stock(n,t,q,p);
	return this->insert(e);
}

// inserts the stock into the HashMap
bool HashMap::insert(Stock *ent){
	// get the key from the stock
	// ...
	string key = ent->getKey();

	// generate a hash code, recalling that it is two_step process
	// first turn the key into an integer
	// then place it in the range 0 ... table_size -1 (use mod operator)
	int hash = (myHashCode(key) % table_size);
	
	// if that bucket is empty, just make it the first stock in the list
	if (table[hash] == nullptr){
		table[hash] = new LinkedHashStock(ent);
	}
	else{
		// otherwise, iterate through that bucket's list
		// checking to see if the key already exists in the list
		LinkedHashStock *stock = table[hash];
		if (stock->getKey() == key){
				// if so, return false	
				delete ent;
				return false;
		}
		while (stock->getNext() != nullptr){
			if (stock->getKey() == key){
				// if so, return false	
				delete ent;
				return false;
			}
			stock = stock->getNext();
		}

		// otherwise, add a new LinkedHashStock containing that Stock
	   // at the end of the list
		if (stock->getKey() == key){
			// if so, return false	
			delete ent;
			return false;
		}
		stock->setNext(new LinkedHashStock(ent));
	}
	// don't forget to increment counter and return true
	counter++;
	return true;
}


// returns a pointer to the Stock if it is in the HashMap
// otherwise return nullptr
Stock* HashMap::find(string key){
	int hash = (myHashCode(key) % table_size);

	if (table[hash] == nullptr)
		return nullptr;
	else{
		LinkedHashStock *cursor = table[hash];
		while (cursor != nullptr && cursor->getKey() != key){
			cursor = cursor->getNext();
		}
		if (cursor == nullptr){
			return nullptr;
		}
		else{ 
			return cursor->getStock();
		}
	}
}


void HashMap::remove(string key){
	int hash = (myHashCode(key) % table_size);

	if (table[hash] != nullptr){
		LinkedHashStock *leadingCursor = table[hash];
		LinkedHashStock *trailingCursor = nullptr;
		while (leadingCursor != nullptr && leadingCursor->getKey() != key){
			trailingCursor = leadingCursor;
			leadingCursor = leadingCursor->getNext();
		}
		if (leadingCursor->getKey() == key){
			counter--;
			// if it is the first item in the list for that hash code
			if (trailingCursor == nullptr){
				LinkedHashStock *nextStock = leadingCursor->getNext();
				delete leadingCursor;
				table[hash] = nextStock;
			}
			else{ // it is not the first item in the list for that hash code
				LinkedHashStock *nextStock = leadingCursor->getNext();
				delete leadingCursor;
				trailingCursor->setNext(nextStock);
			}
		}
	}
}


