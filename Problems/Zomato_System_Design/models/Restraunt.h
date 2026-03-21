#pragma once

#include <string>
#include <vector>
#include <algorithm>

#include "MenuItem.h"
using namespace std;

class Restaurant 
{
	private:
		int id;
		string name;
		string location;
		vector<MenuItem*> menu;
		
	public:
		Restaurant(int id, string name, string location) 
		{
			this->id = id;
			this->name = name;
			this->location = location;
		}
		
		~Restaurant() 
		{
			for (MenuItem* item : menu) 
			{
				delete item;
			}
		}
		
		void setName(string name) 
		{
			this->name = name;
		}
		
		void setLocation(string location) 
		{
			this->location = location;
		}
		
		string getName() 
		{
			return name;
		}
		
		string getLocation() 
		{
			return location;
		}
		
		const vector<MenuItem*>& getMenuItems() 
		{
			return menu;
		}

		int getId() const
		{
			return id;
		}

		void addMenuItem(MenuItem* item)
		{
			menu.push_back(item);
		}

		MenuItem* findMenuItemByCode(const string& code) const
		{
			for (MenuItem* item : menu)
			{
				if (item && item->getCode() == code)
				{
					return item;
				}
			}
			return nullptr;
		}
		
};
