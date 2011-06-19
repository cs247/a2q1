/*
 *  DynArray.h
 *  
 *
 *  Created by Joanne Atlee on 24/05/10
 *  Copyright 2010. All rights reserved.
 *
 */

#ifndef DYN_LIST_H
#define DYN_LIST_H

#include <string>

class DynList {
  public:
	DynList();                              // default constructor
	~DynList();                             // destructor
	DynList(const DynList&);                // copy constructor
	DynList& operator=(const DynList&);     // assignment
	std::string& operator[](int i);         // accessor 
	int size() const;
  private:
	struct Node;
	Node *list_;
	Node *last;
	int size_;
};
    
#endif
