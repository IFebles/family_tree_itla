/*
 * Tree.cpp
 *
 *  Created on: May 28, 2016
 *      Author: raydelto
 */
#include <iostream>
#include "Tree.h"

using namespace std;

namespace ITLA {

//List<Element> heightlist;
//List mylist;

Tree::Tree() : _first(NULL), _last(NULL)
{ }

void Tree::addbranch(string name, int height, int id, int parentid)
{
	Element* elem = new Element(name, height, id, parentid);

	if(_last == NULL)
		_last = _first = elem;
	else
		_last = _last->_next = elem;
}

void Tree::showtree()
{
	if(_first == NULL)
	{
		cout << "* There is no element in the tree! *" << endl;
		return;
	}

	Element* elem = _first;

	while(elem != NULL)
	{
		for(int x = 0; x < elem->_height; x++)
			cout << "-";
		cout << elem->_name << endl;

		elem = elem->_next;
	}
	cout << endl;
}

void Tree::clear()
{
	if(_first == NULL)
		return;

	Element* elem = _first;

	while(elem != NULL)
	{
		Element* temp = elem;
		elem = elem->_next;
		delete temp;
	}
}

/*Tree::~Tree() {
	// TODO Auto-generated destructor stub
}*/

} /* namespace ITLA */
