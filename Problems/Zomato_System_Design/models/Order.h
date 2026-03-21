#pragma once

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

#include "Restraunt.h"
#include "MenuItem.h"
#include "User.h"
#include "../strategies/PaymentStrategy.h"
using namespace std;

class Order 
{
	protected:
		int id;
		Restaurant* restraunt;
		User* user;
		vector<MenuItem*> items;
		PaymentStrategy* ps;
		double total;
		string scheduled;
		
		
	public:
		Order(int id)
		{
			this->id = id;
			user = nullptr;
			restraunt = nullptr;
			ps = nullptr;
			total = 0.0;
			scheduled = "";
		}
		
		virtual ~Order()
		{
			delete ps;
		}
		
		bool processPayment()
		{
			if(ps)
			{
				ps -> pay(total);
				return true;
			}
			else
			{
				cout<<"Please choose a payment method first\n";
				return false;
			}
		}
		
		virtual string getType() const = 0;
		
		int getOrderId() 
		{
			return id;
		}
		
		void setUser(User* u) 
		{
			user = u;
		}
		
		User* getUser()
		{
			return user;
		}
		
		void setRestraunt(Restaurant* r)
		{
			restraunt = r;
		}
		
		Restaurant* getRestraunt()
		{
			return restraunt;
		}
		
		const vector<MenuItem*>& getItems() const
		{
			return items;
		}
		
		void setItems(const vector<MenuItem*>& its)
		{
			items = its;
			total = 0;
			for(auto i : items)
			{
				if (i) total += i->getPrice();
			}
		}
		
		void setPaymentStrategy(PaymentStrategy* p)
		{
			ps = p;
		}
		
		double getTotal() const
		{
			return total;
		}
		
		string getScheduled() const
		{
			return scheduled;
		}
		
		void setScheduled(string s)
		{
			scheduled = s;
		}
};
