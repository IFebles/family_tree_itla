/*
 * Menu.cpp
 *
 *  Created on: May 28, 2016
 *      Author: raydelto
 */
#include <iostream>
#include <cstdlib>
#include <climits>
#include <sstream>
#include "Menu.h"

using namespace std;

namespace ITLA {

Tree mytree;
int mycount= 0;

Menu::Menu() { }

void Menu::clscreen()
{
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
}

void Menu::setpause()
{
	#ifdef _WIN32
	system("pause");
	#else
	system("read -n1 -r -p \"Press any key to continue...\" key");
	#endif
}

void Menu::show()
{
	int resp = 0;

	while(resp != 3)
	{
		clscreen();
		cout << "* Welcome to the Family Tree! *\n\n";
		cout << "1- Create family tree" << endl;
		cout << "2- Deploy family tree" << endl;
		cout << "3- Exit" << endl;

		cout << endl << ">> ";
		cin >> resp;
		cin.ignore(INT_MAX, '\n');

		if(validate(resp))
			setroute(resp);
	}
}

bool Menu::validate(int resp)
{
	if(resp >= 1 && resp <= 3)
		return true;
	else
	{
		cout << "* Invalid option! *" << endl;
		setpause();
		return false;
	}
}

void Menu::setroute(int resp)
{
	switch(resp)
	{
		case 1:
			create();
		break;
		case 2:
			deploy();
		break;
		case 3:
			cout << "* Goodbye! *" << endl;
		break;
	}

	setpause();
}

string Menu::getname(string prompt)
{
	string name;
	do
	{
		cout << prompt;
		getline(cin, name);
	}
	while (name == "");

	return name;
}

int Menu::getamount(string name)
{
	int cant = -1;

	while(cant == -1)
	{
		string temp;
		cout << "Input the offsprings amount of " << name << ": ";
		cin >> temp;
		cant = atoi(temp.c_str());

		if((cant == 0 && temp != "0") || cant < 0)
			cant = -1;
	}

	cin.ignore(INT_MAX, '\n');

	return cant;
}

void Menu::create(int height, string parentname, int parentid)
{
	int cant = height == 0 ? 1: getamount(parentname);
	int id = mycount++;
	string names[cant];

	for(int x = 1; x <= cant; x++)
	{
		stringstream prompt;
		
		if(height == 0)
			prompt << "Input the name of the first person: ";
		else
			prompt << "Input the name of the offspring #" << x
		    << " of " << parentname << ": ";

		names[x-1] = getname(prompt.str());
	}

	for(int x = 0; x < cant; x++)
	{
		mytree.addbranch(names[x], height, id, parentid);
		create(height+1, names[x], id);
	}
}

void Menu::deploy()
{
	mytree.showtree();
}

Menu::~Menu()
{
	mytree.clear();
	cout << "* All data erased! *" << endl;
}

} /* namespace ITLA */
