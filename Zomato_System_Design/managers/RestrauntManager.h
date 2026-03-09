#pragma once

#include <string>
#include <vector>
#include <algorithm>

#include "../models/Restraunt.h"
using namespace std;

class RestrauntManager
{
	private:
	 	vector<Restaurant*> restaurants;
		int nextId;
		
	public:
		RestrauntManager() : nextId(1) {}
		
		Restaurant* addRestaurant(const string& name, const string& location) 
		{
			Restaurant* restaurant = new Restaurant(nextId++, name, location);
			restaurants.push_back(restaurant);
			return restaurant;
		}
		
		vector<Restaurant*> searchByLocation(string location)
		{
			vector<Restaurant*> result;
			transform(location.begin(), location.end(), location.begin(), ::tolower);
			for(Restaurant* res : restaurants) 
			{
				string resLocation = res->getLocation();
				transform(resLocation.begin(), resLocation.end(), resLocation.begin(), ::tolower);
				if(resLocation == location) 
				{
					result.push_back(res);
				}
			}
			return result;
		}

		~RestrauntManager()
		{
			for (auto* r : restaurants) delete r;
		}
		
};
