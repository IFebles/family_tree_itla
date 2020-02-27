/*
 * Menu.h
 *
 *  Created on: May 28, 2016
 *      Author: raydelto
 */

#ifndef MENU_H_
#define MENU_H_
#include "Tree.h"

namespace ITLA {

class Menu {
public:
	Menu();
	void show();
	virtual ~Menu();
private:
	void clscreen();
	void setpause();
	bool validate(int);
	void setroute(int);
	std::string getname(std::string);
	int getamount(std::string);
	void create(int h = 0, std::string pn = "", int pid = 0);
	void deploy();
};

} /* namespace ITLA */

#endif /* MENU_H_ */
