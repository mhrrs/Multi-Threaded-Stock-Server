#include "LinkedHashStock.h"

/*
 * ETK - April 2022
 * LinkedHashStock class
 * provides a node suitable for the linked list
 * in a hash table with chaining
 * Nodes contain a pointer to an Stock and pointer
 * to the next entry in the list.
 */


// constructors 
LinkedHashStock::LinkedHashStock(Stock *s): stock(s), next(nullptr){};

LinkedHashStock::LinkedHashStock(string n, string t, int q, double p):
	stock(new Stock(n,t, q, p)), next(nullptr){};

// destructor 
LinkedHashStock::~LinkedHashStock(){
	delete stock;
};

// mutators
void LinkedHashStock::setStock(Stock *s){
	this->stock = s;
};

void LinkedHashStock::setNext(LinkedHashStock *n){
	this->next = n;
};


// accessors
string LinkedHashStock::getKey(){
	if (stock != nullptr)
		return stock->getKey();
	else
		return nullptr;
};

Stock * LinkedHashStock::getStock(){
	return stock;
};	

LinkedHashStock * LinkedHashStock::getNext(){
	return next;
};

