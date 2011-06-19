/*
 *  DynArray.cpp
 *  
 *
 *  Created by Joanne Atlee on 25/05/10.
 *  Copyright 2010. All rights reserved.
 *
 */

#include "DynList.h"
#include <string>

using namespace std;

//***********************************
// Node Structure
//***********************************

struct DynList::Node {
	string value;
	Node *next;
};

//******************************************
// Member Functions - IMPLEMENT!
//******************************************



//******************************************
// Accessor Functions
//******************************************

// operator[]
string& DynList::operator[] (int i) {
	// check whether array needs to grow
	if (0 <= i && i < size_) {
		
		// locate ith node and return contents
		Node *curr;
		int index;
		for (curr = list_, index = 0; index < i; curr = curr->next, index+=1);
		return curr->value;
	}
	
	// otherwise, need to grow the list. New elements have empty strings
	else {
		if (size_ == 0) {
			DynList::Node *node = new DynList::Node;
			node->value = "";
			node->next = 0;
			list_ = node;
			last = node;
			size_ = 1;
		}
		for (int index = size_; index <= i; index+=1) {
			DynList::Node *node = new DynList::Node;
			node->value = "";
			node->next = 0;
			last->next = node;
			last = node;
			size_ += 1;
		}
		
		return last->value;
	}
}

int DynList::size() const {
	return size_;
}