
#include <string>

namespace ITLA
{
	class Element
	{
	public:
		Element(std::string, int, int, int);
	private:
		std::string _name;
		int _height;
		int _id;
		int _parentid;
		//Element* _parent;
		//Element* _firstchild;
		Element* _next;

		friend class Tree;
	};
}