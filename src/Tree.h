/*
 * Tree.h
 *
 *  Created on: May 28, 2016
 *      Author: raydelto
 */

#ifndef TREE_H_
#define TREE_H_
#include <string>
#include "Element.h"

namespace ITLA {

class Tree
{
public:
	Tree();
	void addbranch(std::string, int, int, int);
	void showtree();
	void clear();
private:
	Element* _first;
	Element* _last;
};

} /* namespace ITLA */

#endif /* TREE_H_ */
