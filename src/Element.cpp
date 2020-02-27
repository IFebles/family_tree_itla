#include "Element.h"

using namespace std;

namespace ITLA
{
	Element::Element(string name, int height, int id, int parentid) : _name(name)
	//, _parent(NULL), _firstchild(NULL)
	, _height(height), _id(id), _parentid(parentid), _next(NULL)
	{ }
}