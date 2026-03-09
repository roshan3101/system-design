#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "Restraunt.h"
#include "MenuItem.h"
using namespace std;

class Cart
{
	private:
		Restaurant* restaurant;
		vector<MenuItem*> items;
		
	public:
		Cart() 
		{
			this->restaurant = nullptr;
		}
		
		void addItem(MenuItem* item) 
		{
			if(!restaurant)
			{
				cerr<<"Please select a restaurant first."<<endl;
				return;
			}
			
			items.push_back(item);
		}
		
		double getTotalAmount()
		{
			double total = 0;
			for(MenuItem* item : items) 
			{
				total += item->getPrice();
			}
			return total;
		}
		
		bool isEmpty() 
		{
			return items.empty();
		}
		
		void clear()
		{
			items.clear();
			restaurant = nullptr;
		}
		
		void setRestaurant(Restaurant* restaurant) 
		{
			this->restaurant = restaurant;
		}
		
		Restaurant* getRestaurant() 
		{
			return restaurant;
		}
		
		const vector<MenuItem*>& getItems() const
		{
			return items;
		}
};
