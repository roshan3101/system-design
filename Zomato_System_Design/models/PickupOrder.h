#pragma once

#include <string>
#include "Order.h"
using namespace std;

class PickupOrder : public Order
{
	private:
		string restrauntAddress;
		
	public:
		PickupOrder(int id) : Order(id)
		{
			restrauntAddress = "";
		}
		
		string getType() const override
		{
			return "Pickup";
		}
		
		void setRestrauntAddress(string s) 
		{
			restrauntAddress = s;
		}
		
		string getRestrauntAddress()
		{
			return restrauntAddress;
		}
};
