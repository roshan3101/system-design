#pragma once

#include <string>
using namespace std;

class MenuItem
{
	private:
		string code;
		string name;
		double price;
		
	public:
		MenuItem(string code, string name, double price) 
		{
			this->code = code;
			this->name = name;
			this->price = price;
		}
		
		void setName(string name) 
		{
			this->name = name;
		}
		
		void setPrice(double price) 
		{
			this->price = price;
		}
		
		string getName() const
		{
			return name;
		}
		
		double getPrice() const
		{
			return price;
		}
		
		string getCode() const
		{
			return code;
		}
		
		void setCode(string code) 
		{
			this->code = code;
		}

};
