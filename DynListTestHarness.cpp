/*
 *  main.cc
 *  
 *
 *  Created by Joanne Atlee on 24/05/10.
 *  Copyright 2010. All rights reserved.
 *
 */

#include <iostream>
#include <string>
#include "DynList.h"

using namespace std;


//************************************************************************
//  Helper variables and functions for test harness
//************************************************************************

//  test harness commands
enum Op {NONE, Def, Size, Copy, Read, Mut, Assign};


// parse input command
Op convertOp(string opStr) {
	switch (opStr[0]) {
		case 'd': return Def;
		case 's': return Size;
		case 'c': return Copy;
		case 'r': return Read;
		case 'm': return Mut;
		case 'a': return Assign;
		default: return NONE;
	}
}

// parse name of dynamic list that is to be operated on
bool readName(int& name) {	
	char l;
	cin >> l;
	if ( l != 'l' )
		return false;
	
	name = -1;
	cin >> name;
	if ( name < 0 || name > 9 ) {
		cout << "Invalid name of date variable." << endl;
		return false;
	}
	else {
		return true;
	}
}


//*******************
// main()
//*******************


int main() {
	cout << "Test harness for List ADT" << endl << endl;
	
	
	// create a collection of dynamic lists to manipulate
	DynList *lists[10] = {0};
	
	// get input command
	cout << "Command: ";
	string command;
	cin >> command;
	
	Op op = convertOp(command);
	
	while ( !cin.eof() ) {
		switch (op) {
			// default construction of a new dynamic list
			case Def: {
				cout << "Enter name of list (l0-l9): ";
				int name;
				if ( readName(name) ) {
					lists[name] = new DynList;
				}
				break;
			}
				
			// use operator[] to read/access element in a list
			case Read: {
				cout << "Enter name of list (l0-l9): ";
				int name;
				if ( readName(name) ) {
					if (lists[name] == 0) {
						cout << "List l" << name << " is not yet defined." << endl;
						break;
					}
					cout << "Enter index into list l" << name << ": ";
					int index;
					cin >> index;
					if (0 > index ) {
						cout << "Invalid index." << endl;
						break;
					}
					cout << "Value of the " << index << "th element of list l" << name << " == \"" << (*lists[name])[index] << "\"" << endl;;
				}
				break;
			}
				
			// change the value of an element in a list, by assigning to the result of operator[]
			case Mut: {
				cout << "Enter name of list (l0-l9): ";
				int name;
				if ( readName(name) ) {
					if (lists[name] == 0) {
						cout << "List l" << name << " is not yet defined." << endl;
						break;
					}
					cout << "Enter index into list l" << name << ": ";
					int index;
					cin >> index;
					if (0 > index ) {
						cout << "Invalid index." << endl;
						break;
					}
					cout << "Enter new value of l" << name << "[" << index << "]: ";
					string newValue;
					cin >> newValue;
					(*lists[name])[index] = newValue;
					cout << "Value of the " << index << "th element of list l" << name << " == \"" << (*lists[name])[index] << "\"" << endl;;
				}
				break;				
			}
				
			// query the size of a list
			case Size: {
				cout << "Enter name of list (l0-l9): ";
				int name;
				if ( readName(name) ) {
					if (lists[name] == 0) {
						cout << "List l" << name << " is not yet defined." << endl;
						break;
					}
					cout << "Size of list l" << name << " = " << lists[name]->size() << endl;
				}
				break;					
			}
				
			// assign one dynamic list to another.  Print contents of both lists, to check results
			case Assign: {
				cout << "Enter name of list to be assigned (l0-l9): ";
				int name;
				if ( readName(name) ) {
					if (lists[name] == 0) {
						cout << "List l" << name << " is not yet defined." << endl;
						break;
					}
					
					cout << "Enter name of list to be copied to assigned list (l0-l9): ";
					int name2;
					if ( readName(name2) ) {
						if (lists[name2] == 0) {
							cout << "List l" << name2 << " is not yet defined." << endl;
							break;
						}

						*lists[name] = *lists[name2];
						
						cout << "Size of l" << name << " = " << lists[name]->size() << endl;
						cout << "Value of l" << name << " = [";
						for (int i=0; i < (lists[name]->size()); i+=1) {
							cout << (*lists[name])[i] << ",";
						}
						cout << "]" << endl;
						cout << "Size of l" << name2 << " = " << lists[name2]->size() << endl;
						cout << "Value of l" << name2 << " = [";
						for (int i=0; i < (lists[name2]->size()); i+=1) {
							cout << (*lists[name2])[i] << ",";
						}
						cout << "]" << endl;
					}
				}
				break;
			}
			
			// use copy constructor to create a new list, initializing from an existing list
			// print the contents of both lists, to check results
			case Copy: {
				cout << "Enter name of list to be copied to (l0-l9): ";
				int name;
				if ( readName(name) ) {
					if (lists[name] == 0) {
						cout << "List l" << name << " is not yet defined." << endl;
						break;
					}
					
					DynList copy(*lists[name]);
											
					cout << "Size of l" << name << " = " << lists[name]->size() << endl;
					cout << "Value of l" << name << " = [";
					for (int i=0; i < (lists[name]->size()); i+=1) {
						cout << (*lists[name])[i] << ",";
					}
					cout << "]" << endl;
					
					cout << "Size of copy" << " = " << copy.size() << endl;
					cout << "Value of copy" << " = [";
					for (int i=0; i < (copy.size()); i+=1) {
						cout << copy[i] << ",";
					}
					cout << "]" << endl;
			}
				break;
			}
			default: {
				cout << "Invalid command." << endl;
			}
		} // switch command
				
		cout << endl << "Command: ";
		cin >> command;
		op = convertOp(command);
				

	} // while cin OK
}
