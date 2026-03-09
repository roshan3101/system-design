#pragma once

#include <string>
#include "Order.h"
using namespace std;

class DeliveryOrder : public Order
{
	private:
		string userAddress;
		
		
	public:
		DeliveryOrder(int id) : Order(id)
		{
			userAddress = "";
		}
		
		string getType() const override
		{
			return "Delivery";
		}
		
		void setUserAddress(string add) 
		{
			userAddress = add;
		}
		
		string getUserAddress()
		{
			return userAddress;
		}
		
		
};
