#pragma once

#include <string>
#include <vector>

#include "Cart.h"
using namespace std;

class User
{
	private:
		int id;
		string name;
		string address;
		Cart* cart;
		
	public:
		User(int id, string name, string address)
		{
			this->id = id;
			this->name = name;
			this->address = address;
			this->cart = new Cart();
		}
		
		~User() 
		{
			delete cart;
		}
		
		string getName() 
		{
			return name;
		}
		
		string getAddress() 
		{
			return address;
		}
		
		void setName(string name) 
		{
			this->name = name;
		}
		
		void setAddress(string address) 
		{
			this->address = address;
		}
		
		Cart* getCart() 
		{
			return cart;
		}

		int getId() const
		{
			return id;
		}
		
};
