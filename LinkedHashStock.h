#ifndef LINKED_HASH_STOCK 
#define LINKED_HASH_STOCK
#include <string>
#include "Stock.h"

/*
 * ETK - April 2022
 * LinkedHashStock class
 * provides a node suitable for the linked list
 * in a hash table with chaining
 * Nodes contain a pointer to an Stock and pointer
 * to the next entry in the list.
 */


using namespace std;

class LinkedHashStock{

public:
	// constructors 
	LinkedHashStock(Stock *s);
	LinkedHashStock(string name, string ticker, int quantity, double price);

	// destructor
	~LinkedHashStock();

	// mutators
	void setStock(Stock *s);
	void setNext(LinkedHashStock *next);

	// accessors 	
	string getKey();
	Stock * getStock();	
	LinkedHashStock * getNext();
	
private:
	Stock * stock;
	LinkedHashStock *next;
};

#endif
